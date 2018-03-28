#pragma once

#include "list.h"

typedef struct List Queue;

#define queue_init list_init

#define queue_destroy list_destroy

#define queue_size list_size

#define queue_empty(queue) ((queue)->size == 0)

#define queue_front(queue) (queue)->head

#define queue_rear(queue) (queue)->tail

void queue_enqueue(Queue *q, DataType data);

DataType queue_dequeue(Queue *q);
