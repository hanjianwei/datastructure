#pragma once

#include "vector.h"

struct Queue {
  int front;
  int rear;
  struct Vector data;
};

void queue_init(struct Queue *, int);

void queue_destroy(struct Queue *);

int queue_size(struct Queue *);

int queue_empty(struct Queue *);

int queue_full(struct Queue *);

void queue_enqueue(struct Queue *q, DataType data);

DataType queue_dequeue(struct Queue *);
