#include "queue.h"

#include <stdio.h>

int main() {
  int i;
  Queue q;
  queue_init(&q, 10); // 大小为10的循环队列

  for (i = 0; i < 20; i++) {
    queue_enqueue(&q, i);
  }

  for (i = 0; i < 20; i++) {
    printf("Remove %d\n", queue_dequeue(&q));
  }

  printf("size: %d\n", queue_size(&q));

  queue_destroy(&q);

  return 0;
}
