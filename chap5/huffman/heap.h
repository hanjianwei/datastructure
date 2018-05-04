#pragma once

#include "vector.h"

// Implement min heap using vector

typedef struct Vector Heap;

#define heap_destroy vector_destroy

enum Status heap_init(Heap *h);

void heap_rebuild(Heap *h);

int heap_size(Heap *h);

void heap_adjust(Heap *h, int node);

DataType heap_pop(Heap *h);

DataType heap_top(Heap *h);
