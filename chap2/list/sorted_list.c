#include "sorted_list.h"
#include <stdio.h>

// Move node from head of src to tail of dst
void move_node(struct List *src, struct List *dst) {
  if (src->size == 0) {
    return;
  }

  if (dst->size == 0) {
    dst->head = src->head;
  } else {
    dst->tail->next = src->head;
  }

  dst->tail = src->head;
  src->head = src->head->next;
  dst->tail->next = NULL;
  src->size--;
  dst->size++;
}

void move_list(struct List *src, struct List *dst) {
  if (dst->size == 0) {
    dst->head = src->head;
  } else {
    dst->tail->next = src->head;
  }
  dst->tail = src->tail;
  dst->size += src->size;

  src->head = NULL;
  src->tail = NULL;
  src->size = 0;
}

// TODO:
enum Status merge_sorted_lists(struct List *dst, struct List *src1,
                               struct List *src2) {
  while (src1->head != NULL && src2->head != NULL) {
    if (src1->head->data < src2->head->data) {
      move_node(src1, dst);
    } else {
      move_node(src2, dst);
    }
  }

  if (src1->head != NULL) {
    move_list(src1, dst);
  } else {
    move_list(src2, dst);
  }

  return STATUS_OK;
}

// TODO:
enum Status merge_multiple_lists(struct List *dst, struct List **srcs, int n) {
  return STATUS_OK;
}
