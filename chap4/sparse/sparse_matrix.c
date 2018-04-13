#include "sparse_matrix.h"
#include <math.h>

int sparse_matrix_item_position_compare(struct Item *lhs, struct Item *rhs) {
  return lhs->row == rhs->row ? lhs->col - rhs->col : lhs->row - rhs->row;
}

void sparse_matrix_init(SparseMatrix *m, int rows, int cols) {
  list_init(m);
  m->rows = rows;
  m->cols = cols;
}

// TODO:
// 将m的第row行第col列设置为value
// 如果下标越界返回 `STATUS_ERR_INVALID_RANGE`
enum Status sparse_matrix_set(SparseMatrix *m, int row, int col, double value) {
  return STATUS_OK;
}

// TODO:
// 返回m的第row行第col列
// 如果下标越界返回NAN
double sparse_matrix_get(SparseMatrix *m, int row, int col) { return NAN; }

// TODO:
// c = a + b
// 假设a，b有相同的行列
void sparse_matrix_add(SparseMatrix *c, SparseMatrix *a, SparseMatrix *b) {}
