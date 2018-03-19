#include "list.h"

#include <stdio.h>

int main() {
  struct list s;
  int i;

  list_init(&s);

  for (i = 0; i < 5; i++) {
    list_push_front(&s, i);
  }

  list_print(&s);

  list_insert_after(&s, 2, 7);

  list_print(&s);

  printf("list_size: %d\n", list_size(&s));
  printf("size: %d\n", s.size);

  list_destroy(&s);

  return 0;
}
