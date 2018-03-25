#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void list_init(struct List *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

void list_destroy(struct List *list) {
  while (list_size(list) > 0) {
    list_remove_after(list, NULL);
  }
}

enum Status list_insert_after(struct List *list, struct ListNode *node,
                              DataType data) {
  struct ListNode *new_node = malloc(sizeof(struct ListNode));

  if (new_node == NULL) {
    return STATUS_ERR_ALLOC;
  }

  new_node->data = data;

  if (node == NULL) {
    // Insertion at the head of the list
    if (list_size(list) == 0) {
      list->tail = new_node;
    }

    new_node->next = list->head;
    list->head = new_node;
  } else {
    // Insertion at somewhere other than at the head
    if (node->next == NULL) {
      list->tail = new_node;
    }

    new_node->next = node->next;
    node->next = new_node;
  }

  list->size++;

  return STATUS_OK;
}

enum Status list_push_front(struct List *list, DataType data) {
  return list_insert_after(list, NULL, data);
}

enum Status list_push_back(struct List *list, DataType data) {
  return list_insert_after(list, list->tail, data);
}

enum Status list_remove_after(struct List *list, struct ListNode *node) {
  struct ListNode *old_node;

  // Empty list
  if (list_size(list) == 0) {
    return STATUS_ERR_INVALID_RANGE;
  }

  if (node == NULL) {
    // Remove from the head of the list
    old_node = list->head;
    list->head = list->head->next;

    if (list_size(list) == 1) {
      list->tail = NULL;
    }
  } else {
    // Remove from somewhere other than the head
    if (node->next == NULL) {
      return STATUS_ERR_INVALID_RANGE;
    }

    old_node = node->next;
    node->next = node->next->next;

    if (node->next == NULL) {
      list->tail = node;
    }
  }

  free(old_node);
  list->size--;

  return STATUS_OK;
}

enum Status list_pop_front(struct List *list) {
  return list_remove_after(list, NULL);
}

int list_size(struct List *list) {
  return list->size;
  // The commented is an O(n) method
  /*
  struct ListNode *p = list->head;
  int n = 0;

  while (p) {
    n++;
    p = p->next;
  }

  return n;
  */
}

struct ListNode *list_at(struct List *list, int i) {
  int n = 0;
  struct ListNode *p = list->head;

  while (p != NULL && n != i) {
    p = p->next;
    n++;
  }

  return p;
}
