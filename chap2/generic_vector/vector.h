#pragma once

#include "common.h"

typedef void *DataPointer;

struct Vector {
  int capacity;
  int size;
  DataPointer *buffer;
  void (*destroy)(void *data);
};

/* Allocate and destroy buffer for vector */
enum Status vector_init(struct Vector *vec, int cap,
                         void (*destroy)(void *data));
void vector_destroy(struct Vector *vec);
enum Status vector_reserve(struct Vector *vec, int new_cap);

void vector_foreach(struct Vector *vec, void (*fn)(DataPointer value));

/* Insert element */
enum Status vector_insert(struct Vector *vec, int pos, DataPointer value);
enum Status vector_push_back(struct Vector *vec, DataPointer value);
enum Status vector_push_front(struct Vector *vec, DataPointer value);

/* Find element */
int vector_find_first(struct Vector *vec, DataPointer value);
int vector_find_next(struct Vector *vec, DataPointer value, int start_pos);

/* Delete element */
enum Status vector_remove_at(struct Vector *vec, int pos);
enum Status vector_pop_front(struct Vector *vec);
enum Status vector_pop_back(struct Vector *vec);
void vector_delete_value(struct Vector *vec, DataPointer value);

/* Methods to be implemented */
void vector_reverse(struct Vector *vec);
void vector_swap(struct Vector *a, struct Vector *b);
enum Status vector_shrink_to_fit(struct Vector *vec);
DataPointer vector_at(struct Vector *vec, int index);
