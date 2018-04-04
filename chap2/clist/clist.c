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

// TODO: DONE
enum Status clist_insert_after(struct CList *list, struct CListNode *node,
                               DataType data) {
  struct CListNode *new_node = malloc(sizeof(struct CListNode));
  if (new_node == NULL) {
    return STATUS_ERR_ALLOC;
  }

  new_node->data = data;
  if (clist_size(list) == 0) {
    // Handle insertion when the list is empty
    new_node->next = new_node;
    list->head = new_node;
  } else {
    // Handle insertion when the list is not empty
    new_node->next = node->next;
    node->next = new_node;
  }

  list->size++;
  return STATUS_OK;
}

// TODO: DONE
enum Status clist_remove_after(struct CList *list, struct CListNode *node) {
  struct CListNode *old_node;

  if (clist_size(list) == 0) {
    return STATUS_ERR_INVALID_RANGE;
  }

  old_node = node->next;
  if (node->next == node) {
    // Remove the last node
    list->head = NULL;
  } else {
    // Remove other than the last node
    node->next = node->next->next;
    if (old_node == list->head) {
      // The removed one is the head
      list->head = old_node->next;
    }
  }

  free(old_node);
  list->size--;

  return STATUS_OK;
}

// Get list size
int clist_size(struct CList *list) { return list->size; }
