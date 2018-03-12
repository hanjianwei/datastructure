#include "vector.h"
#include <stdio.h>

int main() {
  struct vector v, a, b;
  int i;

  vector_new(&v, 10);
  vector_new(&a, 10);
  vector_new(&b, 10);

  for (i = 0; i < 5; i++) {
    vector_push_back(&a, i);
  }

  for (i = 2; i < 7; i++) {
    vector_push_back(&b, i);
  }

  vector_union(&v, &a, &b);

  /* for (i = 0; i < 10; i++) { */
  /*   vector_push_front(&v, i); */
  /* } */
  /* vector_print(&v); */

  /* for (i = 0 ; i < 5; i++) { */
  /*   vector_pop_back(&v); */
  /* } */

  /* vector_print(&v); */

  /* for (i = 0; i < 5; i++) { */
  /*   vector_push_back(&v, i); */
  /* } */
  /* for (i = 0; i < 5; i++) { */
  /*   vector_push_back(&v, i); */
  /* } */
  /* for (i = 0; i < 5; i++) { */
  /*   vector_push_back(&v, i); */
  /* } */

  /* vector_print(&v); */

  /* printf("Find all zero positions\n"); */
  /* i = vector_find_first(&v, 0); */
  /* printf("%d\n", i); */

  /* while ((i = vector_find_next(&v, 0, i+1)) != -1) { */
  /*   printf("%d\n", i); */
  /* } */

  /* vector_delete_value(&v, 0); */

  vector_print(&v);

  vector_destory(&v);

  return 0;
}
