#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
         c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void reverse_vowels_recursion(char *s, int len) {
  if (len <= 0) {
    return;
  }

  if (!is_vowel(s[0])) {
    putchar(s[0]);
    reverse_vowels_recursion(s + 1, len - 1);
  } else if (!is_vowel(s[len - 1])) {
    reverse_vowels_recursion(s, len - 1);
    putchar(s[len - 1]);
  } else {
    putchar(s[len - 1]);
    reverse_vowels_recursion(s + 1, len - 2);
    putchar(s[0]);
  }
}

// TODO: DONE
void reverse_vowels(char *s) {
  reverse_vowels_recursion(s, strlen(s));
  putchar('\n');
}

int main() {
  reverse_vowels("hello");    // 打印  holle
  reverse_vowels("leetcode"); // 打印 leotcede
}
