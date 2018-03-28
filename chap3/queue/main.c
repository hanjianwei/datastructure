#include "queue.h"

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
  Queue q;
  queue_init(&q);

  for (int i = 0; i < 5; i++) {
    queue_enqueue(&q, i);
  }

  print_list(&q);

  printf("Remove %d\n", queue_dequeue(&q));

  print_list(&q);

  printf("size: %d\n", queue_size(&q));

  queue_destroy(&q);

  return 0;
}
