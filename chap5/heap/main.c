#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  Heap h;
  heap_init(&h);

  srand(time(NULL));
  printf("Insert: ");
  for (int i = 0; i < 10; i++) {
    double v = rand() * 10.0 / RAND_MAX;
    printf("%6.2f", v);
    vector_push_back(&h, v);
  }
  printf("\n");

  heap_rebuild(&h);

  printf("Sorted: ");
  while (heap_size(&h) > 0) {
    printf("%6.2f", heap_pop(&h));
  }
  printf("\n");

  heap_destroy(&h);
}
