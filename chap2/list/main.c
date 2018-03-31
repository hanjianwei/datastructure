#include "list.h"
#include "sorted_list.h"

#include <stdio.h>

void print_list(struct List *list) {
  struct ListNode *p = list->head;

  printf("[");

  while (p) {
    printf("%d", p->data);
    p = p->next;
    if (p) {
      printf(", ");
    }
  }

  printf("]\n");
}

void fill_list(struct List *list, int from, int to, int step) {
  for (int i = from; i < to; i += step) {
    list_push_back(list, i);
  }
}

void test_list() {
  struct List s;
  list_init(&s);

  printf("Insert 0, 1, 2, 3, 4\n");
  fill_list(&s, 0, 5, 1);
  print_list(&s);

  printf("Pop front\n");
  list_pop_front(&s);
  print_list(&s);

  printf("size: %d\n", s.size);

  list_destroy(&s);
}

void test_merge_two_lists() {
  struct List s1, s2, dst;

  list_init(&s1);
  list_init(&s2);
  list_init(&dst);

  fill_list(&s1, 0, 5, 1);
  fill_list(&s2, 2, 13, 2);

  printf("s1: ");
  print_list(&s1);
  printf("s2: ");
  print_list(&s2);

  printf("Merge s1 and s2\n");
  merge_sorted_lists(&dst, &s1, &s2);
  printf("s1: ");
  print_list(&s1);
  printf("s2: ");
  print_list(&s2);
  printf("dst: ");
  print_list(&dst);

  list_destroy(&s1);
  list_destroy(&s2);
  list_destroy(&dst);
}

int main() {
  /* test_list(); */
  test_merge_two_lists();

  return 0;
}
