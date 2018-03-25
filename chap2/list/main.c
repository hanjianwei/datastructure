#include "list.h"

#include <stdio.h>

void print_list(struct List *list) {
  struct ListNode *p = list->head;

  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }

  printf("\n");
}


int main() {
  struct List s;
  int i;

  list_init(&s);

  for (i = 0; i < 5; i++) {
    list_push_back(&s, i);
  }

  print_list(&s);

  printf("size: %d\n", s.size);


  list_pop_front(&s);

  print_list(&s);

  printf("size: %d\n", s.size);

  list_destroy(&s);

  return 0;
}
