#include "dlist.h"

#include <stdio.h>

void print_dlist(struct DList *list) {
  struct DListNode *p = list->head;

  while (p) {
    printf("%.1f ", p->data);
    p = p->next;
  }

  printf("\n");
}

int main() {
  struct DList list;
  int i;

  dlist_init(&list);

  // Insert to front
  printf("Insert 0-4 to front\n");
  for (i = 0; i < 5; i++) {
    dlist_push_front(&list, i);
  }
  print_dlist(&list);

  // Insert to back
  printf("Insert 5-9 to back\n");
  for (i = 5; i < 10; i++) {
    dlist_push_back(&list, i);
  }
  print_dlist(&list);

  // Remove 2 elements from front
  printf("Remove 2 elements from front\n");
  for (i = 0; i < 2; i++) {
    dlist_pop_front(&list);
  }
  print_dlist(&list);

  // Remove 3 elements from back
  printf("Remove 3 elements from back\n");
  for (i = 0; i < 3; i++) {
    dlist_pop_back(&list);
  }
  print_dlist(&list);

  printf("size: %d\n", list.size);

  dlist_destroy(&list);

  return 0;
}
