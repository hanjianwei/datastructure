#include "vector.h"
#include <stdio.h>

int main() {
  struct vector v, a, b;
  int i;

  vector_init(&v, 10);
  vector_init(&a, 10);
  vector_init(&b, 10);

  for (i = 0; i < 5; i++) {
    vector_push_back(&a, i);
  }

  for (i = 2; i < 7; i++) {
    vector_push_back(&b, i);
  }

  vector_print(&a);
  vector_print(&b);

  vector_swap(&a, &b);

  vector_print(&a);
  vector_print(&b);

  printf("capacity of a: %d\n", a.capacity);
  vector_shrink_to_fit(&a);
  printf("shrink capacity of a: %d\n", a.capacity);

  vector_reverse(&a);
  vector_print(&a);

  for (i = -10; i < 10; i++) {
    printf("%d ", vector_at(&a, i));
  }


  /* vector_intersection(&v, &a, &b); */

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

  /* vector_print(&v); */

  vector_destory(&v);
  vector_destory(&a);
  vector_destory(&b);

  return 0;
}
