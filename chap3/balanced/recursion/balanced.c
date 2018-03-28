#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_balanced(char *s, int len, int open);

int main() {
  char s[100];

  scanf("%s", s);

  if (is_balanced(s, strlen(s), 0)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

bool is_balanced(char *s, int len, int open) {
  if (len == 0) {
    return open == 0;
  } else {
    if (s[0] == '(') {
      return is_balanced(s + 1, len - 1, open + 1);
    } else if (s[0] == ')') {
      return open > 0 && is_balanced(s + 1, len - 1, open - 1);
    } else {
      return is_balanced(s + 1, len - 1, open);
    }
  }
}
