#include "graph.h"

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

static void graph_init_marked(struct Graph *g) {
  if (g->marked == NULL) {
    g->marked = malloc(g->v * sizeof(bool));
  }
  for (int i = 0; i < g->v; i++) {
    g->marked[i] = false;
  }

  if (g->path == NULL) {
    g->path = malloc(g->v * sizeof(int));
  }
  for (int i = 0; i < g->v; i++) {
    g->path[i] = -1;
  }
}

static void graph_destroy_marked(struct Graph *g) {
  if (g->marked != NULL) {
    free(g->marked);
  }
  if (g->path != NULL) {
    free(g->path);
  }
}

// TODO: DONE
void graph_init(struct Graph *g, int num_vertices, enum GraphType type) {
  g->v = num_vertices;
  g->e = 0;
  g->type = type;
  matrix_init(&g->m, num_vertices, num_vertices, 0);
  g->marked = NULL;
  g->path = NULL;
}

// TODO: DONE
void graph_destroy(struct Graph *g) {
  g->v = 0;
  g->e = 0;
  matrix_destroy(&g->m);
  graph_destroy_marked(g);
}

// TODO: DONE
void graph_add_edge(struct Graph *g, int u, int v, DataType weight) {
  matrix_set(&g->m, u, v, weight);
  if (g->type == UNDIRECTED_GRAPH) {
    matrix_set(&g->m, v, u, weight);
  }
}

// TODO: DONE
int graph_degree(struct Graph *g, int v) {
  if (g->type == UNDIRECTED_GRAPH) {
    return graph_in_degree(g, v);
  }

  return graph_in_degree(g, v) + graph_out_degree(g, v);
}

// TODO: DONE
int graph_in_degree(struct Graph *g, int v) {
  int n = 0;

  for (int i = 0; i < g->v; ++i) {
    if (matrix_get(&g->m, i, v) != 0) {
      n++;
    }
  }

  return n;
}

// TODO: DONE
int graph_out_degree(struct Graph *g, int v) {
  int n = 0;

  for (int i = 0; i < g->v; ++i) {
    if (matrix_get(&g->m, v, i) != 0) {
      n++;
    }
  }

  return n;
}

// TODO: DONE
// 判断是否连通图
bool graph_is_connected(struct Graph *g) {
  graph_dfs(g, 0);

  for (int i = 0; i < g->v; i++) {
    if (!g->marked[i]) {
      return false;
    }
  }

  if (g->type == UNDIRECTED_GRAPH) {
    return true;
  }

  // Flip edge direction
  g->m.mode = 1 - g->m.mode;
  graph_dfs(g, 0);
  bool connected = true;
  for (int i = 0; i < g->v; i++) {
    if (!g->marked[i]) {
      connected = false;
    }
  }
  g->m.mode = 1 - g->m.mode;

  return connected;
}

// TODO: DONE
// 判断两个顶点是否连通
bool graph_is_vertex_connected(struct Graph *g, int u, int v) {
  graph_dfs(g, u);
  return g->marked[v];
}

// TODO: DONE
// 两个顶点之间的距离
DataType graph_vertex_distance(struct Graph *g, int u, int v) {
  graph_dfs(g, u);

  if (!g->marked[v]) {
    return -1;
  }

  DataType dist = 0;
  while (g->path[v] >= 0) {
    dist += matrix_get(&g->m, g->path[v], v);
    v = g->path[v];
  }

  return dist;
}

// TODO: DONE
// 判断sg是否为g的子图
bool graph_is_subgraph(struct Graph *g, struct Graph *sg) {
  if (g->m.rows < sg->m.rows) {
    return false;
  }

  for (int i = 0; i < sg->m.rows; i++) {
    for (int j = 0; j < sg->m.cols; j++) {
      if (matrix_get(&sg->m, i, j) != 0 && matrix_get(&g->m, i, j) == 0) {
        return false;
      }
    }
  }
  return true;
}

// TODO: DONE
// 判断sg是否是g的（强）连通分量
bool graph_is_connected_component(struct Graph *g, struct Graph *sg) {
  return graph_is_subgraph(g, sg) && graph_is_connected(sg);
}

void graph_dfs_recursion(struct Graph *g, int v, int from) {
  g->marked[v] = true;
  g->path[v] = from;

  for (int i = 0; i < g->v; i++) {
    if (matrix_get(&g->m, v, i) != 0 && !g->marked[i]) {
      graph_dfs_recursion(g, i, v);
    }
  }
}

void graph_dfs(struct Graph *g, int v) {
  graph_init_marked(g);
  graph_dfs_recursion(g, v, -1);
}

void graph_bfs(struct Graph *g, int v) {
  graph_init_marked(g);

  Queue q;

  queue_init(&q);

  queue_enqueue(&q, v);
  g->marked[v] = true;
  g->path[v] = -1;

  while (!queue_empty(&q)) {
    int u = queue_dequeue(&q);

    for (int i = 0; i < g->v; i++) {
      if (matrix_get(&g->m, u, i) != 0 && !g->marked[i]) {
        queue_enqueue(&q, i);
        g->marked[i] = true;
        g->path[i] = u;
      }
    }
  }

  queue_destroy(&q);
}

void graph_save(struct Graph *g, const char *filename) {
  FILE *fp = fopen(filename, "w");

  fprintf(fp, "strict %sgraph {\n", g->type == DIRECTED_GRAPH ? "di" : "");

  for (int i = 0; i < g->v; i++) {
    for (int j = 0; j < g->v; j++) {
      int weight = matrix_get(&g->m, i, j);
      if (weight != 0) {
        fprintf(fp, "\t%d %s %d [label = %d]\n", i,
                g->type == DIRECTED_GRAPH ? "->" : "--", j, weight);
      }
    }
  }

  fprintf(fp, "}\n");

  fclose(fp);
}
