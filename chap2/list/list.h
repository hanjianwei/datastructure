#ifndef DS_LIST_H_
#define DS_LIST_H_

typedef int elem_t;

struct list_node {
  elem_t data;
  struct list_node *next;
};

struct list {
  int size;
  struct list_node *head;
};

void list_init(struct list *l);

void list_destroy(struct list *l);

int list_size(struct list *l);

void list_print(struct list *l);

void list_push_front(struct list *l, elem_t value);

struct list_node* list_at(struct list *l, int i);

void list_insert_after(struct list *l, int i, elem_t value);

#endif // DS_LIST_H_
