#include "stack.h"

#include <stdio.h>

void print_num(int n, int base);

int main() {
  int n, base;

  scanf("%d%d", &n, &base);
  print_num(n, base);
}

void print_num(int n, int base) {
  Stack s;

  stack_init(&s, 10);

  while (n != 0) {
    stack_push(&s, n % base);
    n /= base;
  }

  while (!stack_empty(&s)) {
    printf("%d", stack_pop(&s));
  }

  stack_destroy(&s);
}
