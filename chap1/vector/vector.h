#pragma once

typedef int elem_t;

struct vector {
  int capacity;
  int size;
  elem_t *buffer;
};

/* Allocate and destroy buffer for vector */
void vector_init(struct vector *vec, int cap);
void vector_destory(struct vector *vec);

/* Print vector content */
void vector_print(struct vector *vec);

/* Insert element */
void vector_insert(struct vector *vec, int pos, elem_t value);
void vector_push_back(struct vector *vec, elem_t value);
void vector_push_front(struct vector *vec, elem_t value);

/* Find element */
int vector_find_first(struct vector *vec, elem_t value);
int vector_find_next(struct vector *vec, elem_t value, int start_pos);

/* Delete element */
void vector_remove_at(struct vector *vec, int pos);
void vector_pop_front(struct vector *vec);
void vector_pop_back(struct vector *vec);
void vector_delete_value(struct vector *vec, elem_t value);

/* Set operations */
void vector_union(struct vector *c, struct vector *a, struct vector *b);
void vector_intersection(struct vector *c, struct vector *a, struct vector *b);

/* Methods to be implemented */
void vector_reverse(struct vector *vec);
void vector_swap(struct vector *a, struct vector *b);
void vector_shrink_to_fit(struct vector *vec);
elem_t vector_at(struct vector *vec, int index);
