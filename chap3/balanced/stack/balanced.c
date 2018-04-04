#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_balanced(char *s);

int main() {
  char s[100];

  scanf("%s", s);

  if (is_balanced(s)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

char matched_char(char c) {
  switch (c) {
  case ')':
    return '(';
    break;
  case ']':
    return '[';
    break;
  case '}':
    return '{';
    break;
  case '>':
    return '<';
    break;
  default:
    return '\0';
    break;
  }
}

bool is_balanced(char *s) {
  Stack stack;
  bool balanced = true;

  stack_init(&stack, 10);

  while (*s != '\0' && balanced) {
    switch (*s) {
    case '(':
    case '[':
    case '{':
    case '<':
      stack_push(&stack, *s);
      break;

    case ')':
    case ']':
    case '}':
    case '>':
      if (stack_empty(&stack) || stack_pop(&stack) != matched_char(*s)) {
        balanced = false;
      }
      break;
    }

    s++;
  }

  balanced = balanced && stack_empty(&stack);

  stack_destroy(&stack);

  return balanced;
}
