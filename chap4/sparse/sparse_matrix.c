#include "sparse_matrix.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int sparse_matrix_item_position_compare(struct Item *lhs, struct Item *rhs) {
  return lhs->row == rhs->row ? lhs->col - rhs->col : lhs->row - rhs->row;
}

void sparse_matrix_init(SparseMatrix *m, int rows, int cols) {
  list_init(m);
  m->rows = rows;
  m->cols = cols;
}

// Find previous and current position of (row, col)
void sparse_matrix_find(SparseMatrix *m, int row, int col,
                        struct ListNode **prev, struct ListNode **cur) {
  struct Item x = {.row = row, .col = col};
  *cur = m->head;
  *prev = NULL;

  while (*cur != NULL &&
         sparse_matrix_item_position_compare(&(*cur)->data, &x) < 0) {
    *prev = *cur;
    *cur = (*cur)->next;
  }

  if (*cur != NULL && ((*cur)->data.row != row || (*cur)->data.col != col)) {
    *cur = NULL;
  }
}

// TODO: DONE
// 将m的第row行第col列设置为value
// 如果下标越界返回 `STATUS_ERR_INVALID_RANGE`
enum Status sparse_matrix_set(SparseMatrix *m, int row, int col, double value) {
  if (row < 0 || row >= m->rows || col < 0 || col >= m->cols) {
    return STATUS_ERR_INVALID_RANGE;
  }

  struct ListNode *cur, *prev;
  sparse_matrix_find(m, row, col, &prev, &cur);

  if (cur != NULL) {
    // The item already exists
    if (value == 0) {
      // Remove zero item
      list_remove_after(m, prev);
    } else {
      cur->data.value = value;
    }
  } else if (value != 0) {
    struct Item data = {.row = row, .col = col, .value = value};
    list_insert_after(m, prev, data);
  }

  return STATUS_OK;
}

// TODO: DONE
// 返回m的第row行第col列
// 如果下标越界返回NAN
double sparse_matrix_get(SparseMatrix *m, int row, int col) {
  if (row < 0 || row >= m->rows || col < 0 || col >= m->cols) {
    return NAN;
  }

  struct ListNode *cur, *prev;
  sparse_matrix_find(m, row, col, &prev, &cur);

  if (cur == NULL) {
    return 0.0;
  } else {
    return cur->data.value;
  }
}

// TODO: DONE
// c = a + b
// 假设a，b有相同的行列
void sparse_matrix_add(SparseMatrix *c, SparseMatrix *a, SparseMatrix *b) {
  assert(a->rows == b->rows && a->cols == b->cols);

  struct ListNode *p = a->head;
  struct ListNode *q = b->head;

  while (p != NULL && q != NULL) {
    int comp = sparse_matrix_item_position_compare(&p->data, &q->data);
    if (comp < 0) {
      list_push_back(c, p->data);
      p = p->next;
    } else if (comp > 0) {
      list_push_back(c, q->data);
      q = q->next;
    } else {
      struct Item x = {.row = p->data.row,
                       .col = p->data.col,
                       p->data.value + q->data.value};

      if (x.value != 0) {
        list_push_back(c, x);
      }
      p = p->next;
      q = q->next;
    }
  }

  while (p != NULL) {
    list_push_back(c, p->data);
    p = p->next;
  }

  while (q != NULL) {
    list_push_back(c, q->data);
    q = q->next;
  }
}
