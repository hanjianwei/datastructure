#include "clist.h"

#include <stdio.h>
#include <stdlib.h>

void clist_init(struct CList *list) {
  list->size = 0;
  list->head = NULL;
}

void clist_destroy(struct CList *list) {
  while (clist_size(list) > 0) {
    clist_remove_after(list, list->head);
  }
}

// TODO:
enum Status clist_insert_after(struct CList *list, struct CListNode *node,
                               DataType data) {
  return STATUS_OK;
}

// TODO:
enum Status clist_remove_after(struct CList *list, struct CListNode *node) {
  return STATUS_OK;
}

// Get list size
int clist_size(struct CList *list) { return list->size; }
