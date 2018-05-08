#include "heap.h"
#include "btree.h"

enum Status heap_init(Heap *h) {
  enum Status st = vector_init(h, 10);
  // Index 0 is not used
  h->size = 1;
  return st;
}

void heap_rebuild(Heap *h) {
  int n = heap_size(h);

  for (int i = n / 2; i > 0; i--) {
    heap_adjust(h, i);
  }
}

int heap_size(Heap *h) { return h->size - 1; }

void heap_adjust(Heap *h, int node) {
  int n = heap_size(h);

  if (node > n / 2) {
    // node has no children
    return;
  }

  // Choose smaller child
  int left = 2 * node;
  int right = 2 * node + 1;
  int small =
      (right <= n && h->buffer[right]->freq < h->buffer[left]->freq ? right
                                                                    : left);

  // Swap
  if (h->buffer[node]->freq > h->buffer[small]->freq) {
    SWAP(h->buffer[node], h->buffer[small], DataType);
    heap_adjust(h, small);
  }
}

DataType heap_pop(Heap *h) {
  DataType smallest = h->buffer[1];

  // Put last node to heap top
  int n = heap_size(h);
  h->buffer[1] = h->buffer[n];
  h->size--;

  // Adjust heap
  heap_adjust(h, 1);

  return smallest;
}

DataType heap_top(Heap *h) { return h->buffer[1]; }

void heap_insert(Heap *h, DataType data) {
  vector_push_back(h, data);

  int pos = heap_size(h);

  while (pos > 1 && h->buffer[pos / 2] > data) {
    h->buffer[pos] = h->buffer[pos / 2];
  }

  h->buffer[pos] = data;
}
