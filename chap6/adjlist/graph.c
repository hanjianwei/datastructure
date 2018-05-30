#include "graph.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void graph_init_marked(struct Graph *g) {
  for (int i = 0; i < g->v; i++) {
    graph_visit_vertex(g, i, false, -1);
  }
}

// TODO: DONE
void graph_init(struct Graph *g, int num_vertices, enum GraphType type) {
  g->v = num_vertices;
  g->e = 0;
  g->type = type;

  // Initialize adjacent list
  vector_init(&g->adjlist, g->v);
  vector_resize(&g->adjlist, g->v);
  for (int i = 0; i < g->v; i++) {
    struct Vertex *v = graph_vertex(g, i);
    v->label = 'A' + i;
    list_init(&v->adj_verts);
  }
}

// TODO: DONE
void graph_destroy(struct Graph *g) {
  g->v = 0;
  g->e = 0;

  // Destroy adjacent list
  for (int i = 0; i < g->v; i++) {
    list_destroy(&graph_vertex(g, i)->adj_verts);
  }
  vector_destroy(&g->adjlist);
}

struct Vertex *graph_vertex(struct Graph *g, int v) {
  return g->adjlist.buffer + v;
}

void graph_visit_vertex(struct Graph *g, int v, bool marked, int from) {
  struct Vertex *vert = graph_vertex(g, v);
  vert->marked = marked;
  vert->path_from = from;
}

// Edge from u to v.
struct Edge *graph_edge(struct Graph *g, int u, int v) {
  struct ListNode *p = graph_vertex(g, u)->adj_verts.head;

  while (p != NULL) {
    if (p->data.to == v) {
      return &p->data;
    }
    p = p->next;
  }

  return NULL;
}

// TODO: DONE
void graph_add_edge(struct Graph *g, int u, int v, int weight) {
  list_push_back(&graph_vertex(g, u)->adj_verts,
                 (struct Edge){.to = v, .weight = weight});

  if (g->type == UNDIRECTED_GRAPH) {
    list_push_back(&graph_vertex(g, v)->adj_verts,
                   (struct Edge){.to = u, .weight = weight});
  }
  g->e++;
}

// TODO: DONE
int graph_degree(struct Graph *g, int v) {
  if (g->type == UNDIRECTED_GRAPH) {
    return graph_out_degree(g, v);
  }

  return graph_out_degree(g, v) + graph_in_degree(g, v);
}

// TODO: DONE
int graph_in_degree(struct Graph *g, int v) {

  if (g->type == UNDIRECTED_GRAPH) {
    return graph_out_degree(g, v);
  }

  int ideg = 0;
  for (int i = 0; i < g->v; i++) {
    if (graph_edge(g, i, v) != NULL) {
      ideg++;
    }
  }

  return ideg;
}

// TODO: DONE
int graph_out_degree(struct Graph *g, int v) {
  return graph_vertex(g, v)->adj_verts.size;
}

static bool graph_has_cycle_check(struct Graph *g, int v, int from) {
  graph_visit_vertex(g, v, true, from);

  struct ListNode *p = graph_vertex(g, v)->adj_verts.head;
  while (p != NULL) {
    if (!graph_vertex(g, p->data.to)->marked) {
      if (graph_has_cycle_check(g, p->data.to, v)) {
        return true;
      }
    } else if (p->data.to != from) {
      return true;
    }

    p = p->next;
  }

  return false;
}

bool graph_has_cycle(struct Graph *g) {
  graph_init_marked(g);
  return graph_has_cycle_check(g, 3, -1);
}

static void graph_inverted(struct Graph *g, struct Graph *ig) {
  graph_init(ig, g->v, g->type);

  for (int i = 0; i < g->v; i++) {
    struct ListNode *p = graph_vertex(g, i)->adj_verts.head;

    while (p != NULL) {
      graph_add_edge(ig, p->data.to, i, p->data.weight);
      p = p->next;
    }
  }
}

// TODO: DONE
// 判断是否连通图
bool graph_is_connected(struct Graph *g) {
  graph_dfs(g, 0);

  for (int i = 0; i < g->v; i++) {
    if (!graph_vertex(g, i)->marked) {
      return false;
    }
  }

  if (g->type == UNDIRECTED_GRAPH) {
    return true;
  }

  struct Graph ig; // Inverted graph
  graph_inverted(g, &ig);

  graph_dfs(&ig, 0);

  bool connected = true;
  for (int i = 0; i < ig.v; i++) {
    if (!graph_vertex(&ig, i)->marked) {
      connected = false;
      break;
    }
  }

  graph_destroy(&ig);

  return connected;
}

// TODO: DONE
// 判断两个顶点是否连通
bool graph_is_vertex_connected(struct Graph *g, int u, int v) {
  graph_dfs(g, u);
  return graph_vertex(g, v)->marked;
}

// TODO: DONE
// 两个顶点之间的距离
int graph_vertex_distance(struct Graph *g, int u, int v) {
  graph_dfs(g, u);

  if (!graph_vertex(g, v)->marked) {
    return -1;
  }

  int dist = 0;
  int from;
  while ((from = graph_vertex(g, v)->path_from) >= 0) {
    dist += graph_edge(g, from, v)->weight;
    v = from;
  }

  return dist;
}

static void graph_dfs_recursion(struct Graph *g, int v, int from) {
  graph_visit_vertex(g, v, true, from);

  struct ListNode *p = graph_vertex(g, v)->adj_verts.head;
  while (p != NULL) {
    if (!graph_vertex(g, p->data.to)->marked) {
      graph_dfs_recursion(g, p->data.to, v);
    }

    p = p->next;
  }
}

// TODO: DONE
void graph_dfs(struct Graph *g, int v) {
  graph_init_marked(g);
  graph_dfs_recursion(g, v, -1);
}

// TODO: DONE
void graph_bfs(struct Graph *g, int v) {
  graph_init_marked(g);

  Queue q;

  queue_init(&q);

  queue_enqueue(&q, (struct Edge){.to = v, .weight = 0});
  graph_visit_vertex(g, v, true, -1);

  while (!queue_empty(&q)) {
    struct Edge u = queue_dequeue(&q);
    int from = u.to;

    struct ListNode *p = graph_vertex(g, from)->adj_verts.head;
    while (p != NULL) {
      struct Vertex *adj = graph_vertex(g, p->data.to);
      if (!adj->marked) {
        adj->marked = true;
        adj->path_from = from;
        queue_enqueue(
            &q, (struct Edge){.to = p->data.to, .weight = p->data.weight});
      }
      p = p->next;
    }
  }

  queue_destroy(&q);
}

// TODO: DONE
// 判断图g是不是树
bool graph_is_tree(struct Graph *g) {
  if (graph_has_cycle(g)) {
    return false;
  }

  // Check connectivity
  for (int i = 0; i < g->v; i++) {
    if (!graph_vertex(g, i)->marked) {
      return false;
    }
  }

  return true;
}

// TODO: DONE
// 判断t是不是g的生成树
bool graph_is_spanning_tree(struct Graph *g, struct Graph *t) {
  return graph_is_tree(t) && t->v == g->v;
}

static int graph_build_spanning_tree(struct Graph *g, struct Graph *t) {
  int cost = 0;

  for (int i = 0; i < g->v; i++) {
    int from = graph_vertex(g, i)->path_from;

    if (from >= 0) {
      int weight = graph_edge(g, from, i)->weight;

      cost += weight;
      graph_add_edge(t, from, i, weight);
    }
  }

  return cost;
}

// TODO: DONE
// 用dfs生成g的一棵生成树
int graph_spanning_tree_dfs(struct Graph *g, struct Graph *t) {
  graph_init(t, g->v, g->type);
  graph_dfs(g, 0);

  return graph_build_spanning_tree(g, t);
}

// TODO: DONE
// 用bfs生成g的一棵生成树
int graph_spanning_tree_bfs(struct Graph *g, struct Graph *t) {
  graph_init(t, g->v, g->type);
  graph_bfs(g, 0);

  return graph_build_spanning_tree(g, t);
}

static void graph_spanning_tree_prim_find_min_edge(struct Graph *g, int *from,
                                                   int *to) {
  int minw = INT_MAX;

  for (int i = 0; i < g->v; i++) {
    struct Vertex *vert = graph_vertex(g, i);
    if (!vert->marked) {
      continue;
    }

    struct ListNode *p = vert->adj_verts.head;
    while (p != NULL) {
      if (!graph_vertex(g, p->data.to)->marked && p->data.weight < minw) {
        minw = p->data.weight;
        *from = i;
        *to = p->data.to;
      }
      p = p->next;
    }
  }
}

// TODO:DONE
// 用prim算法生成g的一棵最小生成树
int graph_spanning_tree_prim(struct Graph *g, struct Graph *t) {
  graph_init(t, g->v, g->type);
  graph_init_marked(g);

  // Add first vertex
  graph_visit_vertex(g, 0, true, -1);

  int from = -1;
  int to = -1;
  for (int i = 1; i < g->v; i++) {
    graph_spanning_tree_prim_find_min_edge(g, &from, &to);
    graph_visit_vertex(g, to, true, from);
  }

  return graph_build_spanning_tree(g, t);
}

static void graph_spanning_tree_kruskal_find_min_edge(struct Graph *g,
                                                      struct Graph *t,
                                                      int *from, int *to) {
  int minw = INT_MAX;

  for (int i = 0; i < g->v; i++) {
    struct ListNode *p = graph_vertex(g, i)->adj_verts.head;
    while (p != NULL) {
      if (p->data.weight < minw &&
          !graph_is_vertex_connected(t, i, p->data.to)) {
        minw = p->data.weight;
        *from = i;
        *to = p->data.to;
      }
      p = p->next;
    }
  }
}

// TODO: DONE
// 用kruskal算法生成g的一棵最小生成树
int graph_spanning_tree_kruskal(struct Graph *g, struct Graph *t) {
  graph_init(t, g->v, g->type);

  int cost = 0;
  int from, to, weight;
  for (int i = 1; i < g->v; i++) {
    graph_spanning_tree_kruskal_find_min_edge(g, t, &from, &to);
    weight = graph_edge(g, from, to)->weight;
    graph_add_edge(t, from, to, weight);
    cost += weight;
  }

  return cost;
}

// Save to graphviz format
void graph_save(struct Graph *g, const char *name, const char *filename) {
  FILE *fp = fopen(filename, "w");

  fprintf(fp, "strict %sgraph {\n", g->type == DIRECTED_GRAPH ? "di" : "");
  fprintf(fp, "\tlabel=\"%s\"\n", name);

  for (int i = 0; i < g->v; i++) {
    struct ListNode *p = graph_vertex(g, i)->adj_verts.head;

    while (p != NULL) {
      fprintf(fp, "\t%c %s %c [label = %d]\n", graph_vertex(g, i)->label,
              g->type == DIRECTED_GRAPH ? "->" : "--",
              graph_vertex(g, p->data.to)->label, p->data.weight);

      p = p->next;
    }
  }

  fprintf(fp, "}\n");

  fclose(fp);
}
