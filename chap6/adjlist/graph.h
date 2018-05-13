#pragma once

#include <stdbool.h>

#include "vector.h"

enum GraphType { UNDIRECTED_GRAPH = 0, DIRECTED_GRAPH = 1 };

struct Graph {
  int v;
  int e;
  enum GraphType type;
  struct Vector adjlist;

  bool *marked;
  int *path;
};

void graph_init(struct Graph *g, int num_vertices, enum GraphType type);

void graph_destroy(struct Graph *g);

void graph_add_edge(struct Graph *g, int u, int v);

int graph_degree(struct Graph *g, int v);

int graph_in_degree(struct Graph *g, int v);

int graph_out_degree(struct Graph *g, int v);

// 判断是否连通图
bool graph_is_connected(struct Graph *g);

// 判断两个顶点是否连通
bool graph_is_vertex_connected(struct Graph *g, int u, int v);

// 两个顶点之间的距离
DataType graph_vertex_distance(struct Graph *g, int u, int v);

void graph_dfs(struct Graph *g, int v);

void graph_bfs(struct Graph *g, int v);
