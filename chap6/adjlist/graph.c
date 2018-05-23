#include "graph.h"

//TODO:
void graph_init(struct Graph *g, int num_vertices, enum GraphType type) {}

//TODO:
void graph_destroy(struct Graph *g) {}

//TODO:
void graph_add_edge(struct Graph *g, int u, int v) {}

//TODO:
int graph_degree(struct Graph *g, int v) { return 0; }

//TODO:
int graph_in_degree(struct Graph *g, int v) { return 0; }

//TODO:
int graph_out_degree(struct Graph *g, int v) { return 0; }

//TODO:
// 判断是否连通图
bool graph_is_connected(struct Graph *g) { return false; }

//TODO:
// 判断两个顶点是否连通
bool graph_is_vertex_connected(struct Graph *g, int u, int v) { return false; }

//TODO:
// 两个顶点之间的距离
DataType graph_vertex_distance(struct Graph *g, int u, int v) { return 0; }

//TODO:
void graph_dfs(struct Graph *g, int v) {}

//TODO:
void graph_bfs(struct Graph *g, int v) {}

//TODO:
// 判断图g是不是树
bool graph_is_tree(struct Graph *g) { return false; }

//TODO:
// 判断t是不是g的生成树
bool graph_is_spanning_tree(struct Graph *g, struct Graph *t) { return false; }

//TODO:
// 用dfs生成g的一棵生成树
void graph_spanning_tree_dfs(struct Graph *g, struct Graph *t) {}

//TODO:
// 用bfs生成g的一棵生成树
void graph_spanning_tree_bfs(struct Graph *g, struct Graph *t) {}

//TODO:
// 用prim算法生成g的一棵最小生成树
void graph_spanning_tree_prim(struct Graph *g, struct Graph *t) {}

//TODO:
// 用kruskal算法生成g的一棵最小生成树
void graph_spanning_tree_kruskal(struct Graph *g, struct Graph *t) {}
