#include "queue.h"

#include <stdio.h>

int main() {
  int i;
  struct Queue q;
  queue_init(&q, 10); // 大小为10的循环队列

  for (i = 0; i < 20; i++) {
    if (!queue_full(&q)) {
      printf("Put %d in queue\n", i);
      queue_enqueue(&q, i);
    } else {
      printf("Queue is full! drop %d\n", i);
    }
  }

  printf("Current size: %d\n", queue_size(&q));

  for (i = 0; i < 20; i++) {
    if (!queue_empty(&q)) {
      printf("Remove %d\n", queue_dequeue(&q));
    } else {
      printf("Queue is already empty\n");
    }
  }

  printf("Current size: %d\n", queue_size(&q));

  queue_destroy(&q);

  return 0;
}
