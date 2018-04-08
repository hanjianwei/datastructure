#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

enum Status vector_init(struct Vector *vec, int cap) {
  if (cap <= 0) {
    return STATUS_ERR_INVALID_CAPACITY;
  }

  vec->buffer = (DataType *)malloc(cap * sizeof(DataType));
  if (vec->buffer == NULL) {
    return STATUS_ERR_ALLOC;
  }

  vec->capacity = cap;
  vec->size = 0;

  return STATUS_OK;
}

enum Status vector_reserve(struct Vector *vec, int new_cap) {
  if (new_cap < vec->size) {
    return STATUS_ERR_INVALID_CAPACITY;
  }

  DataType *p = (DataType *)realloc(vec->buffer, new_cap * sizeof(DataType));
  if (p == NULL) {
    return STATUS_ERR_ALLOC;
  }

  vec->buffer = p;
  vec->capacity = new_cap;

  return STATUS_OK;
}

void vector_destroy(struct Vector *vec) {
  if (vec->buffer == NULL) {
    return;
  }

  free(vec->buffer);
  vec->buffer = NULL;
  vec->capacity = 0;
  vec->size = 0;
}

enum Status vector_insert(struct Vector *vec, int pos, DataType value) {
  int i;
  enum Status err;

  if (pos < 0 || pos > vec->size) {
    return STATUS_ERR_INVALID_RANGE;
  }

  if (vec->size == vec->capacity) {
    err = vector_reserve(vec, 2 * vec->capacity);
    if (err != STATUS_OK) {
      return err;
    }
  }

  for (i = vec->size - 1; i >= pos; i--) {
    vec->buffer[i + 1] = vec->buffer[i];
  }

  vec->buffer[pos] = value;
  vec->size++;

  return STATUS_OK;
}

enum Status vector_push_back(struct Vector *vec, DataType value) {
  return vector_insert(vec, vec->size, value);
}

enum Status vector_push_front(struct Vector *vec, DataType value) {
  return vector_insert(vec, 0, value);
}

enum Status vector_remove_at(struct Vector *vec, int pos) {
  int i;

  if (pos < 0 || pos > vec->size - 1) {
    return STATUS_ERR_INVALID_RANGE;
  }

  for (i = pos + 1; i < vec->size; i++) {
    vec->buffer[i - 1] = vec->buffer[i];
  }

  vec->size--;

  return STATUS_OK;
}

enum Status vector_pop_front(struct Vector *vec) {
  return vector_remove_at(vec, 0);
}

enum Status vector_pop_back(struct Vector *vec) {
  return vector_remove_at(vec, vec->size - 1);
}

void vector_delete_value(struct Vector *vec, DataType value) {
  int pos = 0;

  while ((pos = vector_find_next(vec, value, pos)) != -1) {
    vector_remove_at(vec, pos);
  }
}

int vector_find_next(struct Vector *vec, DataType value, int start_pos) {
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

int vector_find_first(struct Vector *vec, DataType value) {
  return vector_find_next(vec, value, 0);
}

void vector_reverse(struct Vector *vec) {
  int i;

  for (i = 0; i < vec->size / 2; i++) {
    SWAP(vec->buffer[i], vec->buffer[vec->size - i - 1], DataType);
  }
}

void vector_swap(struct Vector *a, struct Vector *b) {
  SWAP(a->size, b->size, int);
  SWAP(a->capacity, b->capacity, int);
  SWAP(a->buffer, b->buffer, DataType *);
}

enum Status vector_shrink_to_fit(struct Vector *vec) {
  return vector_reserve(vec, vec->size);
}

DataType vector_at(struct Vector *vec, int index) {
  int r = index % vec->size;
  if (r < 0)
    r += vec->size;

  return vec->buffer[r];
}
