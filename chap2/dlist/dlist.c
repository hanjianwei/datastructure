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

// TODO: DONE
enum Status dlist_insert_after(struct DList *list, struct DListNode *node,
                               DataType data) {
  if (node == NULL && dlist_size(list) != 0) {
    return STATUS_ERR_INVALID_RANGE;
  }

  struct DListNode *new_node = malloc(sizeof(struct DListNode));
  if (new_node == NULL) {
    return STATUS_ERR_ALLOC;
  }

  new_node->data = data;

  if (dlist_size(list) == 0) {
    // Handle insertion when the list is empty
    list->head = new_node;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_node;
  } else {
    new_node->next = node->next;
    new_node->prev = node;

    if (node->next == NULL) {
      list->tail = new_node;
    } else {
      node->next->prev = new_node;
    }

    node->next = new_node;
  }

  list->size++;
  return STATUS_OK;
}

// TODO: DONE
enum Status dlist_insert_before(struct DList *list, struct DListNode *node,
                                DataType data) {

  if (node == NULL && dlist_size(list) != 0) {
    return STATUS_ERR_INVALID_RANGE;
  }

  struct DListNode *new_node = malloc(sizeof(struct DListNode));
  if (new_node == NULL) {
    return STATUS_ERR_ALLOC;
  }

  new_node->data = data;
  if (dlist_size(list) == 0) {
    // Handle insertion when the list is empty
    list->head = new_node;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_node;
  } else {
    // Handle insertion when the list is not empty
    new_node->next = node;
    new_node->prev = node->prev;

    if (node->prev == NULL) {
      list->head = new_node;
    } else {
      node->prev->next = new_node;
    }

    node->prev = new_node;
  }

  list->size++;
  return STATUS_OK;
}

enum Status dlist_push_front(struct DList *list, DataType data) {
  return dlist_insert_before(list, list->head, data);
}

enum Status dlist_push_back(struct DList *list, DataType data) {
  return dlist_insert_after(list, list->tail, data);
}

// TODO: DONE
enum Status dlist_remove(struct DList *list, struct DListNode *node) {
  if (node == NULL || dlist_size(list) == 0) {
    return STATUS_ERR_INVALID_RANGE;
  }

  if (node == list->head) {
    // Remove the head from the list
    list->head = node->next;

    if (list->head == NULL) {
      list->tail = NULL;
    } else {
      node->next->prev = NULL;
    }
  } else {
    // Handle removal from other than the head of the list
    node->prev->next = node->next;
    if (node->next == NULL) {
      list->tail = node->prev;
    } else {
      node->next->prev = node->prev;
    }
  }

  free(node);
  list->size--;
  return STATUS_OK;
}

enum Status dlist_pop_front(struct DList *list) {
  return dlist_remove(list, list->head);
}

enum Status dlist_pop_back(struct DList *list) {
  return dlist_remove(list, list->tail);
}

int dlist_size(struct DList *list) { return list->size; }
