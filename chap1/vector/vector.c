#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

void vector_realloc(struct vector *vec) {
  elem_t *p = (elem_t *)realloc(vec->data, vec->capacity * 2 * sizeof(elem_t));
  if (p == NULL) {
    printf("Reallocate failed\n");
    return;
  }

  vec->data = p;
  vec->capacity *= 2;
}

void vector_init(struct vector *vec, int cap) {
  if (cap <= 0) {
    printf("Wrong capacity!\n");
    return;
  }

  vec->data = (elem_t *)malloc(cap * sizeof(elem_t));
  if (vec->data == NULL) {
    printf("Allocate vector failed\n");
    return;
  }

  vec->capacity = cap;
  vec->size = 0;
}

void vector_destory(struct vector *vec) {
  if (vec->data != NULL) {
    free(vec->data);
    vec->data = NULL;
    vec->capacity = 0;
    vec->size = 0;
  }
}

void vector_print(struct vector *vec) {
  int i;

  for (i = 0; i < vec->size; i++) {
    printf("%d ", vec->data[i]);
  }
  printf("\n");
}

void vector_insert(struct vector *vec, int pos, elem_t value) {
  int i;

  if (pos < 0 || pos > vec->size) {
    printf("Wrong insert position\n");
    return;
  }

  if (vec->size == vec->capacity) {
    vector_realloc(vec);
  }

  for (i = vec->size - 1; i >= pos; i--) {
    vec->data[i + 1] = vec->data[i];
  }

  vec->data[pos] = value;
  vec->size++;
  return;
}

void vector_push_back(struct vector *vec, elem_t value) {
  vector_insert(vec, vec->size, value);
}

void vector_push_front(struct vector *vec, elem_t value) {
  vector_insert(vec, 0, value);
}

void vector_remove_at(struct vector *vec, int pos) {
  int i;

  if (pos < 0 || pos > vec->size - 1) {
    printf("Delete at wrong position\n");
    return;
  }

  for (i = pos + 1; i < vec->size; i++) {
    vec->data[i - 1] = vec->data[i];
  }

  vec->size--;
}

void vector_pop_front(struct vector *vec) { vector_remove_at(vec, 0); }

void vector_pop_back(struct vector *vec) {
  vector_remove_at(vec, vec->size - 1);
}

void vector_delete_value(struct vector *vec, elem_t value) {
  int pos = 0;

  while ((pos = vector_find_next(vec, value, pos)) != -1) {
    vector_remove_at(vec, pos);
  }
}

int vector_find_next(struct vector *vec, elem_t value, int start_pos) {
  int i;

  if (vec->size == 0) {
    return -1;
  }

  if (start_pos < 0 || start_pos >= vec->size) {
    printf("Invalid start position\n");
    return -1;
  }

  for (i = start_pos; i < vec->size; i++) {
    if (vec->data[i] == value) {
      return i;
    }
  }

  return -1;
}

int vector_find_first(struct vector *vec, elem_t value) {
  return vector_find_next(vec, value, 0);
}

void vector_union(struct vector *c, struct vector *a, struct vector *b) {
  int i;

  for (i = 0; i < a->size; i++) {
    if (vector_find_first(c, a->data[i]) == -1) {
      vector_push_back(c, a->data[i]);
    }
  }

  for (i = 0; i < b->size; i++) {
    if (vector_find_first(c, b->data[i]) == -1) {
      vector_push_back(c, b->data[i]);
    }
  }
}

void vector_intersection(struct vector *c, struct vector *a, struct vector *b) {
  int i;

  for (i = 0; i < a->size; i++) {
    if (vector_find_first(b, a->data[i]) >= 0) {
      vector_push_back(c, a->data[i]);
    }
  }
}

#define SWAP(x, y, T)                                                          \
  do {                                                                         \
    T SWAP = x;                                                                \
    x = y;                                                                     \
    y = SWAP;                                                                  \
  } while (0)

void vector_reverse(struct vector *vec) {
  int i;

  for (i = 0; i < vec->size / 2; i++) {
    SWAP(vec->data[i], vec->data[vec->size - i - 1], elem_t);
  }
}

void vector_swap(struct vector *a, struct vector *b) {
  SWAP(a->size, b->size, int);
  SWAP(a->capacity, b->capacity, int);
  SWAP(a->data, b->data, elem_t *);
}

void vector_shrink_to_fit(struct vector *vec) {
  elem_t *p = (elem_t *)realloc(vec->data, vec->size * sizeof(elem_t));
  if (p == NULL) {
    printf("Shrink failed\n");
    return;
  }

  vec->data = p;
  vec->capacity = vec->size;
}

elem_t vector_at(struct vector *vec, int index) {
  int r = index % vec->size;
  if (r < 0)
    r += vec->size;

  return vec->data[r];
}
