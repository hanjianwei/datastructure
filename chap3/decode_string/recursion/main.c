#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *find_matched(char *s, int open) {
  if (s[0] == ']') {
    open--;
  } else if (s[0] == '[') {
    open++;
  }

  return open == 0 ? s : find_matched(s + 1, open);
}

void decode_string_recursion(char *s, int len) {
  if (len == 0) {
    return;
  }

  char *rsb = NULL;
  if (isdigit(s[0]) && s[1] == '[' && (rsb = find_matched(s + 2, 1)) != NULL) {
    int count = s[0] - '0';
    while (count-- > 0) {
      decode_string_recursion(s + 2, rsb - s - 2);
    }
    decode_string_recursion(rsb + 1, len - (rsb - s + 1));
  } else {
    putchar(s[0]);
    decode_string_recursion(s + 1, len - 1);
  }
}

// TODO: DONE
void decode_string(char *s) {
  decode_string_recursion(s, strlen(s));
  putchar('\n');
}

int main() {
  decode_string("3[a]2[bc]");     // 输出 aaabcbc
  decode_string("3[a2[c]]");      // 输出 accaccacc
  decode_string("2[abc]3[cd]ef"); // 输出 abcabccdcdcdef
}
