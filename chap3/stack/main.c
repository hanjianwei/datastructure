#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack s;

  stack_init(&s, 10);

  for (int i = 0; i < 5; i++) {
    stack_push(&s, i);
  }

  while (!stack_empty(&s)) {
    DataType d = stack_pop(&s);

    printf("%f ", d);
  }

  printf("\n");

  stack_destroy(&s);

  return 0;
}
