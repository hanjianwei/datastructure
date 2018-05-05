#include "graph.h"

#include <stdio.h>

void init_undirected_graph(struct Graph *g) {
  graph_init(g, 6, UNDIRECTED_GRAPH);

  graph_add_edge(g, 0, 1, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 0, 3, 3);
  graph_add_edge(g, 1, 2, 4);
  graph_add_edge(g, 4, 5, 5);
}

// 连通分量
void init_undirected_subgraph1(struct Graph *g) {
  graph_init(g, 4, UNDIRECTED_GRAPH);

  graph_add_edge(g, 0, 1, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 0, 3, 3);
  graph_add_edge(g, 1, 2, 4);
}

// 子图，非连通分量
void init_undirected_subgraph2(struct Graph *g) {
  graph_init(g, 5, UNDIRECTED_GRAPH);

  graph_add_edge(g, 0, 1, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 0, 3, 3);
  graph_add_edge(g, 1, 2, 4);
}

// 非子图
void init_undirected_subgraph3(struct Graph *g) {
  graph_init(g, 6, UNDIRECTED_GRAPH);

  graph_add_edge(g, 0, 1, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 0, 3, 3);
  graph_add_edge(g, 1, 2, 4);
  graph_add_edge(g, 1, 4, 4);
  graph_add_edge(g, 4, 5, 5);
}

void test_undirected_graph() {
  struct Graph g;
  init_undirected_graph(&g);

  printf("Degree: \n");
  for (int i = 0; i < 6; i++) {
    printf("%d => %d\n", i, graph_degree(&g, i));
  }

  printf("g is %sconnected\n", graph_is_connected(&g) ? "" : "not ");

  printf("%d and %d are %sconnected\n", 0, 2,
         graph_is_vertex_connected(&g, 0, 2) ? "" : "not ");
  printf("%d and %d are %sconnected\n", 0, 4,
         graph_is_vertex_connected(&g, 0, 4) ? "" : "not ");

  printf("d(%d, %d) = %d\n", 0, 2, graph_vertex_distance(&g, 0, 2));
  printf("d(%d, %d) = %d\n", 1, 3, graph_vertex_distance(&g, 1, 3));

  struct Graph sg1, sg2, sg3;
  init_undirected_subgraph1(&sg1);
  init_undirected_subgraph2(&sg2);
  init_undirected_subgraph3(&sg3);

  printf("sg1 is %ssubgraph and is %sconnected component\n",
         graph_is_subgraph(&g, &sg1) ? "" : "not ",
         graph_is_connected_component(&g, &sg1) ? "" : "not ");
  printf("sg2 is %ssubgraph and is %sconnected component\n",
         graph_is_subgraph(&g, &sg2) ? "" : "not ",
         graph_is_connected_component(&g, &sg2) ? "" : "not ");
  printf("sg3 is %ssubgraph and is %sconnected component\n",
         graph_is_subgraph(&g, &sg3) ? "" : "not ",
         graph_is_connected_component(&g, &sg3) ? "" : "not ");

  graph_destroy(&sg1);
  graph_destroy(&sg2);
  graph_destroy(&sg3);
  graph_destroy(&g);
}

void init_directed_graph(struct Graph *g) {
  graph_init(g, 4, DIRECTED_GRAPH);

  graph_add_edge(g, 0, 3, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 2, 1, 3);
  graph_add_edge(g, 1, 0, 4);
}

// 强连通分量
void init_directed_subgraph1(struct Graph *g) {
  graph_init(g, 3, DIRECTED_GRAPH);

  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 2, 1, 3);
  graph_add_edge(g, 1, 0, 4);
}

// 子图，非强连通分量
void init_directed_subgraph2(struct Graph *g) {
  graph_init(g, 3, DIRECTED_GRAPH);

  graph_add_edge(g, 2, 1, 3);
  graph_add_edge(g, 1, 0, 4);
}

// 非子图
void init_directed_subgraph3(struct Graph *g) {
  graph_init(g, 5, DIRECTED_GRAPH);

  graph_add_edge(g, 0, 3, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 2, 1, 3);
  graph_add_edge(g, 1, 0, 4);
}

void test_directed_graph() {
  struct Graph g;
  init_directed_graph(&g);

  printf("Degree: \n");
  for (int i = 0; i < 6; i++) {
    printf("%d => %d(%d in, %d out)\n", i, graph_degree(&g, i),
           graph_in_degree(&g, i), graph_out_degree(&g, i));
  }

  printf("g is %sconnected\n", graph_is_connected(&g) ? "" : "not ");

  printf("%d and %d are %sconnected\n", 0, 2,
         graph_is_vertex_connected(&g, 0, 2) ? "" : "not ");
  printf("%d and %d are %sconnected\n", 0, 4,
         graph_is_vertex_connected(&g, 0, 4) ? "" : "not ");

  printf("d(%d, %d) = %d\n", 0, 2, graph_vertex_distance(&g, 0, 2));
  printf("d(%d, %d) = %d\n", 1, 3, graph_vertex_distance(&g, 1, 3));

  struct Graph sg1, sg2, sg3;
  init_directed_subgraph1(&sg1);
  init_directed_subgraph2(&sg2);
  init_directed_subgraph3(&sg3);

  printf("sg1 is %ssubgraph and is %sconnected component\n",
         graph_is_subgraph(&g, &sg1) ? "" : "not ",
         graph_is_connected_component(&g, &sg1) ? "" : "not ");
  printf("sg2 is %ssubgraph and is %sconnected component\n",
         graph_is_subgraph(&g, &sg2) ? "" : "not ",
         graph_is_connected_component(&g, &sg2) ? "" : "not ");
  printf("sg3 is %ssubgraph and is %sconnected component\n",
         graph_is_subgraph(&g, &sg3) ? "" : "not ",
         graph_is_connected_component(&g, &sg3) ? "" : "not ");

  graph_destroy(&sg1);
  graph_destroy(&sg2);
  graph_destroy(&sg3);
  graph_destroy(&g);
}

int main() {
  printf("Test undirected graph\n");
  test_undirected_graph();
  printf("Test directed graph\n");
  test_directed_graph();
}
