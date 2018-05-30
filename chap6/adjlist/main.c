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

void test_undirected_graph() {
  struct Graph g;
  init_undirected_graph(&g);

  graph_save(&g, "Graph", "undirected.dot");

  printf("Degree: \n");
  for (int i = 0; i < 6; i++) {
    printf("%d => %d\n", i, graph_degree(&g, i));
  }

  printf("g is %sconnected\n", graph_is_connected(&g) ? "" : "not ");

  printf("%d and %d are %sconnected\n", 0, 2,
         graph_is_vertex_connected(&g, 0, 2) ? "" : "not ");
  printf("%d and %d are %sconnected\n", 0, 4,
         graph_is_vertex_connected(&g, 0, 4) ? "" : "not ");

  printf("g %s tree\n", graph_is_tree(&g) ? "is" : "is not");

  graph_destroy(&g);
}

void init_directed_graph(struct Graph *g) {
  graph_init(g, 4, DIRECTED_GRAPH);

  graph_add_edge(g, 0, 3, 1);
  graph_add_edge(g, 0, 2, 2);
  graph_add_edge(g, 2, 1, 3);
  graph_add_edge(g, 1, 0, 4);
}

void test_directed_graph() {
  struct Graph g;
  init_directed_graph(&g);

  graph_save(&g, "Graph", "directed.dot");

  printf("Degree: \n");
  for (int i = 0; i < 4; i++) {
    printf("%d => %d(%d in, %d out)\n", i, graph_degree(&g, i),
           graph_in_degree(&g, i), graph_out_degree(&g, i));
  }

  printf("g is %sconnected\n", graph_is_connected(&g) ? "" : "not ");

  printf("%d and %d are %sconnected\n", 0, 2,
         graph_is_vertex_connected(&g, 0, 2) ? "" : "not ");
  printf("%d and %d are %sconnected\n", 3, 0,
         graph_is_vertex_connected(&g, 3, 0) ? "" : "not ");

  printf("d(%d, %d) = %d\n", 0, 2, graph_vertex_distance(&g, 0, 2));
  printf("d(%d, %d) = %d\n", 1, 3, graph_vertex_distance(&g, 1, 3));

  printf("g %s tree\n", graph_is_tree(&g) ? "is" : "is not");

  graph_destroy(&g);
}

void test_spanning_tree() {
  struct Graph g, t_prim, t_kruskal, t_dfs, t_bfs;
  graph_init(&g, 7, UNDIRECTED_GRAPH);

  graph_add_edge(&g, 0, 1, 7);
  graph_add_edge(&g, 0, 3, 5);
  graph_add_edge(&g, 1, 2, 8);
  graph_add_edge(&g, 1, 3, 9);
  graph_add_edge(&g, 1, 4, 7);
  graph_add_edge(&g, 2, 4, 5);
  graph_add_edge(&g, 3, 4, 15);
  graph_add_edge(&g, 3, 5, 6);
  graph_add_edge(&g, 4, 5, 8);
  graph_add_edge(&g, 4, 6, 9);
  graph_add_edge(&g, 5, 6, 11);

  graph_spanning_tree_bfs(&g, &t_bfs);
  graph_spanning_tree_dfs(&g, &t_dfs);
  graph_spanning_tree_prim(&g, &t_prim);
  graph_spanning_tree_kruskal(&g, &t_kruskal);

  graph_save(&g, "Graph", "g.dot");
  graph_save(&t_bfs, "BFS", "t_bfs.dot");
  graph_save(&t_dfs, "DFS", "t_dfs.dot");
  graph_save(&t_prim, "Prim", "t_prim.dot");
  graph_save(&t_kruskal, "Kruskal", "t_kruskal.dot");

  graph_destroy(&g);
  graph_destroy(&t_prim);
  graph_destroy(&t_kruskal);
  graph_destroy(&t_dfs);
  graph_destroy(&t_bfs);
}

int main() {
  printf("Test undirected graph\n");
  test_undirected_graph();
  printf("Test directed graph\n");
  test_directed_graph();
  printf("Test spanning tree\n");
  test_spanning_tree();
}
