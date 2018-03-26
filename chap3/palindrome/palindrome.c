#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s, int n);

int main() {
  char s[100];

  scanf("%s", s);

  if (is_palindrome(s, strlen(s))) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

int is_palindrome(const char *s, int n) {
  if (n <= 1) {
    return 1;
  } else {
    return s[0] == s[n - 1] && is_palindrome(s + 1, n - 2);
  }
}
