#ifndef DS_VECTOR_H_
#define DS_VECTOR_H_

struct vector {
  int capacity;
  int size;
  int *data;
};

void vector_new(struct vector *vec, int cap);

void vector_destory(struct vector *vec);

void vector_print(struct vector *vec);

void vector_insert(struct vector *vec, int pos, int value);

void vector_push_back(struct vector *vec, int value);

void vector_push_front(struct vector *vec, int value);

void vector_remove_at(struct vector *vec, int pos);

void vector_pop_front(struct vector *vec);

void vector_pop_back(struct vector *vec);

int vector_find_first(struct vector *vec, int value);

int vector_find_next(struct vector *vec, int value, int start_pos);

void vector_delete_value(struct vector *vec, int value);

void vector_union(struct vector *c, struct vector *a, struct vector *b);

/* Methods to be implemented */
void vector_reverse(struct vector *vec);

void vector_swap(struct vector *a, struct vector *b);

void vector_shrink_to_fit(struct vector *vec);

int at(struct vector *vec, int index);

#endif /* DS_VECTOR_H_ */
