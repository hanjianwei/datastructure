#pragma once

#include <stdbool.h>

#include "matrix.h"

enum GraphType { UNDIRECTED_GRAPH = 0, DIRECTED_GRAPH = 1 };

typedef char VertexData;

struct Graph {
  int v;
  int e;
  enum GraphType type;
  struct Matrix m;

  VertexData *vertex_data;

  bool *marked;
  int *path;
  DataType *dists;
};

void graph_init(struct Graph *g, int num_vertices, enum GraphType type);

void graph_destroy(struct Graph *g);

void graph_set_edge(struct Graph *g, int u, int v, DataType weight);

bool graph_has_edge(struct Graph *g, int u, int v);

int graph_edge(struct Graph *g, int u, int v);

int graph_degree(struct Graph *g, int v);

int graph_in_degree(struct Graph *g, int v);

int graph_out_degree(struct Graph *g, int v);

// 判断是否连通图
bool graph_is_connected(struct Graph *g);

// 判断两个顶点是否连通
bool graph_is_vertex_connected(struct Graph *g, int u, int v);

// 两个顶点之间的距离
DataType graph_vertex_distance(struct Graph *g, int u, int v);

// 判断sg是否为g的子图
bool graph_is_subgraph(struct Graph *g, struct Graph *sg);

// 判断sg是否是g的（强）连通分量
bool graph_is_connected_component(struct Graph *g, struct Graph *sg);

// 深度遍历，结果保存在marked, path
void graph_dfs(struct Graph *g, int v);

// 广度遍历，结果保存在marked, path
void graph_bfs(struct Graph *g, int v);

// 用Dijkstra算法计算顶点v到其它顶点的距离,
// 并将距离记录在dists中，路径记录在path中
void graph_dijkstra(struct Graph *g, int v);

// 用Floyd算法计算顶点两两之间的距离, 将其记录在dists矩阵中
void graph_floyd(struct Graph *g, struct Matrix *dists);

// 用Ford Fulkerson算法计算从s到t的最大流，返回最大流的值，并将流量记录在flow中
DataType graph_ford_fulkerson(struct Graph *g, int s, int t,
                              struct Graph *flow);

void graph_save(struct Graph *g, const char *filename);
