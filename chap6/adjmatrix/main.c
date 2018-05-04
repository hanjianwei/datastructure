#include "graph.h"

int main() {
  struct Graph g;

  graph_init(&g, 5, UNDIRECTED_GRAPH);

  graph_destroy(&g);
}
