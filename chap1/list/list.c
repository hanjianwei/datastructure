#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void list_init(struct list *l) {
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
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

void list_push_front(struct list *l, int value) {
  struct list_node *p = (struct list_node *)malloc(sizeof(struct list_node));

  if (p == NULL) {
    printf("List Allocate Failed\n");
    return;
  }

  p->data = value;

  if (l->head == NULL) {
    p->next = NULL;
    l->tail = p;
  } else {
    p->next = l->head;
  }

  l->head = p;
  l->size++;
}
