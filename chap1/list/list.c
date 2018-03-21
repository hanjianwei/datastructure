#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void list_init(struct list *l) {
  l->size = 0;
  l->head = NULL;
}

void list_destroy(struct list *l) {
  struct list_node *p = l->head;
  struct list_node *q;

  while (p) {
    q = p->next;
    free(p);
    p = q;
  }

  list_init(l);
}

int list_size(struct list *l) {
  struct list_node *p = l->head;
  int n = 0;

  while (p) {
    n++;
    p = p->next;
  }

  return n;
}

void list_print(struct list *l) {
  struct list_node *p = l->head;

  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }

  printf("\n");
}

void list_insert_after_node(struct list_node *node, elem_t value) {
  struct list_node *p;

  if (node == NULL) {
    printf("Can not insert after null pointer\n");
    return;
  }

  p = (struct list_node *)malloc(sizeof(struct list_node));
  p->data = value;
  p->next = node->next;
  node->next = p;
}

void list_push_front(struct list *l, elem_t value) {
  struct list_node *p = (struct list_node *)malloc(sizeof(struct list_node));

  if (p == NULL) {
    printf("List Allocate Failed\n");
    return;
  }

  p->data = value;

  if (l->head == NULL) {
    p->next = NULL;
  } else {
    p->next = l->head;
  }

  l->head = p;
  l->size++;
}

struct list_node* list_at(struct list *l, int i) {
  int n = 0;
  struct list_node *p = l->head;

  while (p != NULL && n != i) {
    p = p->next;
    n++;
  }

  return p;
}

void list_insert_after(struct list *l, int i, elem_t value) {
  struct list_node *node = list_at(l, i);

  if (node == NULL) {
    printf("i-th node not found\n");
    return;
  } else {
    list_insert_after_node(node, value);
    l->size++;
  }
}
