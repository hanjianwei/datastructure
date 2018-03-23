#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

enum cc_stat vector_reserve(struct vector *vec, int new_cap) {
  if (new_cap < vec->size) {
    return CC_ERR_INVALID_CAPACITY;
  }

  elem_t *p = (elem_t *)realloc(vec->buffer, new_cap * sizeof(elem_t));
  if (p == NULL) {
    return CC_ERR_ALLOC;
  }

  vec->buffer = p;
  vec->capacity = new_cap;

  return CC_OK;
}

enum cc_stat vector_init(struct vector *vec, int cap,
                         void (*destroy)(void *data)) {
  vec->size = 0;
  vec->destroy = destroy;
  vec->buffer = NULL;

  return vector_reserve(vec, cap);
}

void vector_destroy(struct vector *vec) {
  int i;

  if (vec->buffer == NULL) {
    return;
  }

  /* Remove data */
  if (vec->destroy != NULL) {
    for (i = 0; i < vec->size; i++) {
      vec->destroy(vec->buffer[i]);
    }
  }

  free(vec->buffer);
  vec->buffer = NULL;
  vec->capacity = 0;
  vec->size = 0;
}

void vector_foreach(struct vector *vec, void (*fn)(elem_t value)) {
  int i;

  if (fn == NULL) {
    return;
  }

  for (i = 0; i < vec->size; i++) {
    fn(vec->buffer[i]);
  }
}

enum cc_stat vector_insert(struct vector *vec, int pos, elem_t value) {
  int i;
  enum cc_stat err;

  if (pos < 0 || pos > vec->size) {
    return CC_ERR_INVALID_RANGE;
  }

  if (vec->size == vec->capacity) {
    err = vector_reserve(vec, 2 * vec->capacity);
    if (err != CC_OK) {
      return err;
    }
  }

  for (i = vec->size - 1; i >= pos; i--) {
    vec->buffer[i + 1] = vec->buffer[i];
  }

  vec->buffer[pos] = value;
  vec->size++;

  return CC_OK;
}

enum cc_stat vector_push_back(struct vector *vec, elem_t value) {
  return vector_insert(vec, vec->size, value);
}

enum cc_stat vector_push_front(struct vector *vec, elem_t value) {
  return vector_insert(vec, 0, value);
}

enum cc_stat vector_remove_at(struct vector *vec, int pos) {
  int i;

  if (pos < 0 || pos > vec->size - 1) {
    return CC_ERR_INVALID_RANGE;
  }

  if (vec->destroy != NULL) {
    vec->destroy(vec->buffer[pos]);
  }

  for (i = pos + 1; i < vec->size; i++) {
    vec->buffer[i - 1] = vec->buffer[i];
  }

  vec->size--;

  return CC_OK;
}

enum cc_stat vector_pop_front(struct vector *vec) {
  return vector_remove_at(vec, 0);
}

enum cc_stat vector_pop_back(struct vector *vec) {
  return vector_remove_at(vec, vec->size - 1);
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
    if (vec->buffer[i] == value) {
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
    if (vector_find_first(c, a->buffer[i]) == -1) {
      vector_push_back(c, a->buffer[i]);
    }
  }

  for (i = 0; i < b->size; i++) {
    if (vector_find_first(c, b->buffer[i]) == -1) {
      vector_push_back(c, b->buffer[i]);
    }
  }
}

void vector_intersection(struct vector *c, struct vector *a, struct vector *b) {
  int i;

  for (i = 0; i < a->size; i++) {
    if (vector_find_first(b, a->buffer[i]) >= 0) {
      vector_push_back(c, a->buffer[i]);
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
    SWAP(vec->buffer[i], vec->buffer[vec->size - i - 1], elem_t);
  }
}

void vector_swap(struct vector *a, struct vector *b) {
  SWAP(a->size, b->size, int);
  SWAP(a->capacity, b->capacity, int);
  SWAP(a->buffer, b->buffer, elem_t *);
  /* SWAP(a->destroy, b->destroy, void (*destroy)(void *data)); */
}

enum cc_stat vector_shrink_to_fit(struct vector *vec) {
  return vector_reserve(vec, vec->size);
}

elem_t vector_at(struct vector *vec, int index) {
  int r = index % vec->size;
  if (r < 0)
    r += vec->size;

  return vec->buffer[r];
}
