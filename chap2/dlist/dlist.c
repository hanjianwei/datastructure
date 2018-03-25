#include "dlist.h"

#include <stdio.h>
#include <stdlib.h>

void dlist_init(struct DList *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

void dlist_destroy(struct DList *list) {
  while (dlist_size(list) > 0) {
    dlist_remove(list, list->tail);
  }

  dlist_init(list);
}

// TODO:
enum Status dlist_insert_after(struct DList *list, struct DListNode *node,
                               DataType data) {
  return STATUS_OK;
}

// TODO:
enum Status dlist_insert_before(struct DList *list, struct DListNode *node,
                                DataType data) {
  return STATUS_OK;
}

enum Status dlist_push_front(struct DList *list, DataType data) {
  return dlist_insert_before(list, list->head, data);
}

enum Status dlist_push_back(struct DList *list, DataType data) {
  return dlist_insert_after(list, list->tail, data);
}

// TODO:
enum Status dlist_remove(struct DList *list, struct DListNode *node) {
  return STATUS_OK;
}

enum Status dlist_pop_front(struct DList *list) {
  return dlist_remove(list, list->head);
}

enum Status dlist_pop_back(struct DList *list) {
  return dlist_remove(list, list->tail);
}

int dlist_size(struct DList *list) {
  return list->size;
}
