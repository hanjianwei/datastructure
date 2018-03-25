#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void print_int(void *pi) { printf("%d ", *(int *)pi); }

void print_vector(struct Vector *vec) {
  vector_foreach(vec, print_int);
  printf("\n");
}

void exit_if_error(enum Status st) {
  if (st == STATUS_OK) {
    return;
  }

  switch (st) {
  case STATUS_ERR_ALLOC:
    printf("Memory allocation error\n");
    break;
  case STATUS_ERR_INVALID_CAPACITY:
    printf("Invalide capacity\n");
    break;
  case STATUS_ERR_INVALID_RANGE:
    printf("Invalide range\n");
    break;
  case STATUS_ERR_OUT_OF_RANGE:
    printf("Out of range\n");
    break;
  default:
    printf("Unknown error\n");
    break;
  }

  exit(1);
}

struct Vector *generate_vector(int from, int to) {
  int i;
  int *pv;
  enum Status err;
  int step = (from < to ? 1 : -1);
  struct Vector *v = (struct Vector *)malloc(sizeof(struct Vector));

  if (v == NULL) {
    exit_if_error(STATUS_ERR_ALLOC);
  }

  err = vector_init(v, 10, free);
  exit_if_error(err);

  for (i = from; i != to; i += step) {
    pv = (int *)malloc(sizeof(int));
    *pv = i;
    err = vector_push_back(v, pv);
    exit_if_error(err);
  }

  return v;
}

void free_vector(struct Vector *v) {
  vector_destroy(v);
  free(v);
}

/* Test swap */
void test_swap() {
  struct Vector *a = generate_vector(0, 5);
  struct Vector *b = generate_vector(2, 7);

  print_vector(a);
  print_vector(b);

  free_vector(a);
  free_vector(b);
}

void test_shrink() {
  struct Vector *a = generate_vector(0, 5);

  printf("capacity of a: %d\n", a->capacity);
  vector_shrink_to_fit(a);
  printf("shrink capacity of a: %d\n", a->capacity);

  free_vector(a);
}

void test_reverse() {
  struct Vector *a = generate_vector(0, 5);

  vector_reverse(a);
  print_vector(a);

  free_vector(a);
}

void test_at() {
  struct Vector *a = generate_vector(0, 5);
  int i;
  int *p;

  for (i = -10; i < 10; i++) {
    p = (int *)vector_at(a, i);
    printf("%d ", *p);
  }

  free_vector(a);
}

int main() {

  test_swap();
  test_reverse();
  test_shrink();
  test_at();

  return 0;
}
