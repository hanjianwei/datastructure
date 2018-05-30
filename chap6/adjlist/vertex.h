#pragma once

#include "list.h"

struct Vertex {
  char label;
  struct List adj_verts;

  bool marked;
  int path_from;
};
