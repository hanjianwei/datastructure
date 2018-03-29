#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

// TODO:
int rpn(char **tokens, int len) {
  return 0;
}

int main() {
  char *s1[] = {"2", "1", "+", "3", "*"};
  char *s2[] = {"4", "13", "5", "/", "+"};

  printf("%d\n", rpn(s1, ARRAY_SIZE(s1))); // 9
  printf("%d\n", rpn(s2, ARRAY_SIZE(s2))); // 6
}
