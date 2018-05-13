#pragma once

#include "common.h"
#include "list.h"

struct Vertex {
  char data;
  struct List adj_verts;
};

typedef struct Vertex VecElemType;

struct Vector {
  int capacity;
  int size;
  VecElemType *buffer;
};

/* Allocate and destroy buffer for vector */
enum Status vector_init(struct Vector *vec, int cap);
void vector_destroy(struct Vector *vec);
enum Status vector_reserve(struct Vector *vec, int new_cap);

/* Insert element */
enum Status vector_insert(struct Vector *vec, int pos, VecElemType value);
enum Status vector_push_back(struct Vector *vec, VecElemType value);
enum Status vector_push_front(struct Vector *vec, VecElemType value);

/* Find element */
int vector_find_first(struct Vector *vec, VecElemType value);
int vector_find_next(struct Vector *vec, VecElemType value, int start_pos);

/* Delete element */
enum Status vector_remove_at(struct Vector *vec, int pos);
enum Status vector_pop_front(struct Vector *vec);
enum Status vector_pop_back(struct Vector *vec);

/* Methods to be implemented */
void vector_reverse(struct Vector *vec);
void vector_swap(struct Vector *a, struct Vector *b);
enum Status vector_shrink_to_fit(struct Vector *vec);
VecElemType vector_at(struct Vector *vec, int index);
