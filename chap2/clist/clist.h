#pragma once

#include "common.h"

typedef double DataType;

struct CListNode {
  DataType data;
  struct CListNode *next;
};

struct CList {
  int size;
  struct CListNode *head;
};

// Init a list
void clist_init(struct CList *list);
// Destroy a list
void clist_destroy(struct CList *list);

// Insert `data` after node `node`
enum Status clist_insert_after(struct CList *list, struct CListNode *node,
                               DataType data);

// Remove the node after `node`
enum Status clist_remove_after(struct CList *list, struct CListNode *node);

// Get list size
int clist_size(struct CList *list);
