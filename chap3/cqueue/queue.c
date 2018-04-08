#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

void queue_init(struct Queue *q, int cap) {
  q->front = -1;
  q->rear = -1;
  vector_init(&q->data, cap);
}

void queue_destroy(struct Queue *q) {
  vector_destroy(&q->data);
  q->front = -1;
  q->rear = -1;
}

int queue_size(struct Queue *q) { return q->data.size; }

int queue_empty(struct Queue *q) { return q->data.size == 0; }

int queue_full(struct Queue *q) { return q->data.size == q->data.capacity; }

void queue_enqueue(struct Queue *q, DataType data) {
  q->rear = (q->rear + 1) % q->data.capacity;
  q->data.buffer[q->rear] = data;
  q->data.size++;
}

DataType queue_dequeue(struct Queue *q) {
  q->front = (q->front + 1) % q->data.capacity;
  q->data.size--;
  return q->data.buffer[q->front];
}
