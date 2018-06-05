#include "graph.h"

#include "queue.h"

#include <limits.h>
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

  if (g->dists == NULL) {
    g->dists = malloc(g->v * sizeof(int));
  }
  for (int i = 0; i < g->v; i++) {
    g->dists[i] = INT_MAX / 2;
  }
}

static void graph_destroy_marked(struct Graph *g) {
  if (g->marked != NULL) {
    free(g->marked);
  }
  if (g->path != NULL) {
    free(g->path);
  }
  if (g->dists != NULL) {
    free(g->dists);
  }
}

static void graph_add_path(struct Graph *g, int u, int v) {
  g->path[v] = u;
  g->dists[v] = u < 0 ? 0 : g->dists[u] + graph_edge(g, u, v);
}

// TODO: DONE
void graph_init(struct Graph *g, int num_vertices, enum GraphType type) {
  g->v = num_vertices;
  g->e = 0;
  g->type = type;
  matrix_init(&g->m, num_vertices, num_vertices, ROW_MAJOR);
  g->marked = NULL;
  g->path = NULL;
  g->dists = NULL;
}

// TODO: DONE
void graph_destroy(struct Graph *g) {
  g->v = 0;
  g->e = 0;
  matrix_destroy(&g->m);
  graph_destroy_marked(g);
}

// TODO: DONE
void graph_set_edge(struct Graph *g, int u, int v, DataType weight) {
  DataType old = matrix_get(&g->m, u, v);
  if (weight == old) {
    return;
  }

  matrix_set(&g->m, u, v, weight);
  if (g->type == UNDIRECTED_GRAPH) {
    matrix_set(&g->m, v, u, weight);
  }

  if (old == 0) {
    g->e++;
  } else if (weight == 0) {
    g->e--;
  }
}

bool graph_has_edge(struct Graph *g, int u, int v) {
  return graph_edge(g, u, v) != 0;
}

int graph_edge(struct Graph *g, int u, int v) {
  return matrix_get(&g->m, u, v);
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
    if (graph_has_edge(g, i, v)) {
      n++;
    }
  }

  return n;
}

// TODO: DONE
int graph_out_degree(struct Graph *g, int v) {
  int n = 0;

  for (int i = 0; i < g->v; ++i) {
    if (graph_has_edge(g, v, i)) {
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
      break;
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
  return g->marked[v] ? g->dists[v] : -1;
}

// TODO: DONE
// 判断sg是否为g的子图
bool graph_is_subgraph(struct Graph *g, struct Graph *sg) {
  if (g->m.rows < sg->m.rows) {
    return false;
  }

  for (int i = 0; i < sg->m.rows; i++) {
    for (int j = 0; j < sg->m.cols; j++) {
      if (graph_has_edge(sg, i, j) && !graph_has_edge(g, i, j)) {
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
  graph_add_path(g, from, v);

  for (int i = 0; i < g->v; i++) {
    if (graph_has_edge(g, v, i) && !g->marked[i]) {
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
  g->dists[v] = 0;

  while (!queue_empty(&q)) {
    int u = queue_dequeue(&q);

    for (int i = 0; i < g->v; i++) {
      if (graph_has_edge(g, u, i) && !g->marked[i]) {
        queue_enqueue(&q, i);
        g->marked[i] = true;
        graph_add_path(g, u, i);
      }
    }
  }

  queue_destroy(&q);
}

// Can we update distance of v from u?
static void graph_relax_edge(struct Graph *g, int u, int v) {
  if (graph_has_edge(g, u, v) &&
      g->dists[v] > g->dists[u] + graph_edge(g, u, v)) {
    graph_add_path(g, u, v);
  }
}

static void graph_relax_vertex(struct Graph *g, int v) {
  for (int i = 0; i < g->v; i++) {
    graph_relax_edge(g, v, i);
  }
}

static int graph_find_unmarked_mindist_vertex(struct Graph *g) {
  int mindist = INT_MAX;
  int mini = -1;

  for (int i = 0; i < g->v; i++) {
    if (!g->marked[i] && g->dists[i] < mindist) {
      mindist = g->dists[i];
      mini = i;
    }
  }

  return mini;
}

// TODO: DONE
// 用Dijistra算法计算顶点v到其它顶点的距离,
// 并将距离记录在dists中，路径记录在path中
void graph_dijkstra(struct Graph *g, int v) {
  graph_init_marked(g);
  g->dists[v] = 0;

  int w = -1;
  while ((w = graph_find_unmarked_mindist_vertex(g)) >= 0) {
    g->marked[w] = true;
    graph_relax_vertex(g, w);
  }
}

// shortest_path(i, j, k) =
// min(shortest_path(i, j, k-1), shortest_path(i, k-1, k-1) + shortest_path(k-1,
// j, k-1))
static int graph_floyd_shortest(struct Graph *g, int i, int j, int k) {
  if (k == 0) {
    if (i == j) {
      return 0;
    }
    int w = graph_edge(g, i, j);
    return w == 0 ? INT_MAX / 2 : w;
  } else {
    int w1 = graph_floyd_shortest(g, i, j, k - 1);
    int w2 = graph_floyd_shortest(g, i, k - 1, k - 1) +
             graph_floyd_shortest(g, k - 1, j, k - 1);
    return w1 < w2 ? w1 : w2;
  }
}

// TODO: DONE
// 用Floyd算法计算顶点两两之间的距离, 将其记录在dists矩阵中
void graph_floyd(struct Graph *g, struct Matrix *dists) {
  matrix_init(dists, g->m.rows, g->m.cols, g->m.mode);

  for (int i = 0; i < g->m.rows; i++) {
    for (int j = 0; j < g->m.cols; j++) {
      matrix_set(dists, i, j, graph_floyd_shortest(g, i, j, g->v));
    }
  }
}

static int min(int x, int y) { return x < y ? x : y; }

// 返回路径中最小的流
static int graph_min_flow_in_path(struct Graph *g, int s, int t) {
  int k = g->path[t];
  if (k == s) {
    return graph_edge(g, k, t);
  } else {
    return min(graph_edge(g, k, t), graph_min_flow_in_path(g, s, k));
  }
}

static void graph_update_edge(struct Graph *g, int u, int v, int dw) {
  graph_set_edge(g, u, v, graph_edge(g, u, v) + dw);
}

static int graph_update_flow(struct Graph *g, int s, int t,
                             struct Graph *flow) {
  int minflow = graph_min_flow_in_path(g, s, t);

  while (g->path[t] != -1) {
    int u = g->path[t];

    int total_flow = minflow + graph_edge(flow, u, t) - graph_edge(flow, t, u);
    if (total_flow > 0) {
      graph_set_edge(flow, u, t, total_flow);
      graph_set_edge(flow, t, u, 0);
    } else {
      graph_set_edge(flow, u, t, 0);
      graph_set_edge(flow, t, u, -total_flow);
    }
    /* graph_update_edge(flow, u, t, minflow); */

    graph_update_edge(g, u, t, -minflow);
    graph_update_edge(g, t, u, minflow);

    t = u;
  }

  return minflow;
}

// TODO: DONE
// 用Ford Fulkerson算法计算从s到t的最大流，返回最大流的值，并将流量记录在flow中

DataType graph_ford_fulkerson(struct Graph *g, int s, int t,

                              struct Graph *flow) {
  graph_init(flow, g->v, g->type);
  int f = 0;

  while (graph_dfs(g, s), g->marked[t]) {
    f += graph_update_flow(g, s, t, flow);
  }

  return f;
}

void graph_save(struct Graph *g, const char *filename) {
  FILE *fp = fopen(filename, "w");

  fprintf(fp, "strict %sgraph {\n", g->type == DIRECTED_GRAPH ? "di" : "");

  for (int i = 0; i < g->v; i++) {
    for (int j = 0; j < g->v; j++) {
      int weight = graph_edge(g, i, j);
      if (weight != 0) {
        fprintf(fp, "\t%d %s %d [label = %d]\n", i,
                g->type == DIRECTED_GRAPH ? "->" : "--", j, weight);
      }
    }
  }

  fprintf(fp, "}\n");

  fclose(fp);
}
