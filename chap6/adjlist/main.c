#include "graph.h"

#include <stdio.h>

void init_undirected_graph(struct Graph *g) {
  graph_init(g, 6, UNDIRECTED_GRAPH);

  graph_add_edge(g, 0, 1);
  graph_add_edge(g, 0, 2);
  graph_add_edge(g, 0, 3);
  graph_add_edge(g, 1, 2);
  graph_add_edge(g, 4, 5);
}

void test_undirected_graph() {
  struct Graph g;
  init_undirected_graph(&g);

  printf("Degree: \n");
  for (int i = 0; i < 6; i++) {
    printf("%d => %d\n", i, graph_degree(&g, i));
  }

  printf("DFS:\n");
  graph_dfs(&g, 0);

  printf("BFS:\n");
  graph_bfs(&g, 0);

  graph_destroy(&g);
}

void init_directed_graph(struct Graph *g) {
  graph_init(g, 4, DIRECTED_GRAPH);

  graph_add_edge(g, 0, 3);
  graph_add_edge(g, 0, 2);
  graph_add_edge(g, 2, 1);
  graph_add_edge(g, 1, 0);
}

void test_directed_graph() {
  struct Graph g;
  init_directed_graph(&g);

  printf("Degree: \n");
  for (int i = 0; i < 6; i++) {
    printf("%d => %d(%d in, %d out)\n", i, graph_degree(&g, i),
           graph_in_degree(&g, i), graph_out_degree(&g, i));
  }

  printf("DFS:\n");
  graph_dfs(&g, 0);

  printf("BFS:\n");
  graph_bfs(&g, 0);

  graph_destroy(&g);
}

int main() {
  printf("Test undirected graph\n");
  test_undirected_graph();
  printf("Test directed graph\n");
  test_directed_graph();
}
