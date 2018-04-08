#include "queue.h"
#include <stdlib.h>

void queue_enqueue(Queue *q, DataType data) { list_push_back(q, data); }

DataType queue_dequeue(Queue *q) {
  DataType data = q->head->data;
  list_pop_front(q);

  return data;
}

void queue_copy_init(Queue *q, Queue *from) {
  queue_init(q);
  if (from == NULL) {
    return;
  }

  for (struct ListNode *p = from->head; p != NULL; p = p->next) {
    queue_enqueue(q, p->data);
  }
}
