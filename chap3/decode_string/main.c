#include "stack.h"
#include "vector.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

// TODO: DONE
void decode_string(char *s) {
  Stack count_stack, index_stack;
  struct Vector str;

  stack_init(&count_stack);
  stack_init(&index_stack);
  vector_init(&str, strlen(s));

  while (*s != '\0') {
    if (isdigit(*s)) {
      stack_push(&count_stack, *s - '0');
      stack_push(&index_stack, str.size);

      s += 2; // Skip '['
    } else if (*s == ']') {
      int count = stack_pop(&count_stack);
      int from = stack_pop(&index_stack);
      int to = str.size;

      for (int i = 0; i < count - 1; i++) {
        for (int j = from; j < to; j++) {
          vector_push_back(&str, str.buffer[j]);
        }
      }
      s++;
    } else {
      vector_push_back(&str, *s);
      s++;
    }
  }

  for (int i = 0; i < str.size; i++) {
    putchar(str.buffer[i]);
  }
  putchar('\n');

  vector_destroy(&str);
  stack_destroy(&count_stack);
  stack_destroy(&index_stack);
}

int main() {
  decode_string("3[a]2[bc]");     // 输出 aaabcbc
  decode_string("3[a2[c]]");      // 输出 accaccacc
  decode_string("2[abc]3[cd]ef"); // 输出 abcabccdcdcdef
}
