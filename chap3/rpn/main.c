#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

bool is_operator(const char *s) {
  return s[1] == '\0' &&
         (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
}

int eval(int lhs, int rhs, char op) {
  switch (op) {
  case '+':
    return lhs + rhs;
  case '-':
    return lhs - rhs;
  case '*':
    return lhs * rhs;
  case '/':
    return lhs / rhs;
  default:
    return 0;
  }
}

// TODO: DONE
int rpn(char **tokens, int len) {
  Stack stack;
  stack_init(&stack);

  int i;
  for (i = 0; i < len; i++) {
    char *token = tokens[i];

    if (is_operator(token)) {
      if (stack_size(&stack) < 2) {
        break;
      }

      int rhs = stack_pop(&stack);
      int lhs = stack_pop(&stack);
      stack_push(&stack, eval(lhs, rhs, token[0]));
    } else {
      stack_push(&stack, atoi(token));
    }
  }

  int result = 0;
  if (i == len && stack_size(&stack) == 1) {
    result = stack_pop(&stack);
  } else {
    printf("Wrong expression\n");
  }

  stack_destroy(&stack);

  return result;
}

int main() {
  char *s1[] = {"2", "1", "+", "3", "*"};
  char *s2[] = {"4", "13", "5", "/", "+"};

  printf("%d\n", rpn(s1, ARRAY_SIZE(s1))); // 9
  printf("%d\n", rpn(s2, ARRAY_SIZE(s2))); // 6
}
