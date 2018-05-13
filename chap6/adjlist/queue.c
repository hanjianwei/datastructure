#include "queue.h"

void queue_enqueue(Queue *q, DataType data) { list_push_back(q, data); }

DataType queue_dequeue(Queue *q) {
  DataType data = q->head->data;
  list_pop_front(q);

  return data;
}
