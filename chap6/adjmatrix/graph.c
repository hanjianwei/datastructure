#include "graph.h"

// TODO:
void graph_init(struct Graph *g, int num_vertices, enum GraphType type) {}

// TODO:
void graph_destroy(struct Graph *g) {}

// TODO:
void graph_add_edge(struct Graph *g, int u, int v, DataType weight) {}

// TODO:
int graph_degree(struct Graph *g, int v) { return 0; }

// TODO:
int graph_in_degree(struct Graph *g, int v) { return 0; }

// TODO:
int graph_out_degree(struct Graph *g, int v) { return 0; }

// TODO:
// 判断是否连通图
bool graph_is_connected(struct Graph *g) { return false; }

// TODO:
// 判断两个顶点是否连通
bool graph_is_vertex_connected(struct Graph *g, int u, int v) { return false; }

// TODO:
// 两个顶点之间的距离
DataType graph_vertex_distance(struct Graph *g, int u, int v) { return 0; }

// TODO:
// 判断sg是否为g的子图
bool graph_is_subgraph(struct Graph *g, struct Graph *sg) { return false; }

// TODO:
// 判断sg是否是g的（强）连通分量
bool graph_is_connected_component(struct Graph *g, struct Graph *sg) {
  return false;
}
