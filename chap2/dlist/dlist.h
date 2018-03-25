#pragma once

#include "common.h"

typedef double DataType;

struct DListNode {
  DataType data;
  struct DListNode *prev;
  struct DListNode *next;
};

struct DList {
  int size;
  struct DListNode *head;
  struct DListNode *tail;
};

// Init a list
void dlist_init(struct DList *list);
// Destroy a list
void dlist_destroy(struct DList *list);

// Insert `data` after node `node`
enum Status dlist_insert_after(struct DList *list, struct DListNode *node,
                               DataType data);
// Insert `data` before node `node`
enum Status dlist_insert_before(struct DList *list, struct DListNode *node,
                                DataType data);
// Insert `data` at front of `list`
enum Status dlist_push_front(struct DList *list, DataType data);
enum Status dlist_push_back(struct DList *list, DataType data);

// Remove the node `node`
enum Status dlist_remove(struct DList *list, struct DListNode *node);
// Remove the first node
enum Status dlist_pop_front(struct DList *list);
// Remove the last node
enum Status dlist_pop_back(struct DList *list);

// Get list size
int dlist_size(struct DList *list);
