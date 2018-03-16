#include "list.h"

int main() {
  struct list s;
  int i;

  list_init(&s);

  for (i = 0; i < 5; i++) {
    list_push_front(&s, i);
  }

  list_print(&s);

  list_destroy(&s);

  return 0;
}
