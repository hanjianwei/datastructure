#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Array a;

  array_init(&a, 5);

  for (int i = 0; i < 5; i++) {
    array_set(&a, i, i);
  }

  for (int i = 0; i < 5; i++) {
    printf("%.1f ", array_get(&a, i));
  }
  printf("\n");

  array_destroy(&a);

  return 0;
}
