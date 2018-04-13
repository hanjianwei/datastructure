#include "list.h"

typedef struct List SparseMatrix;

void sparse_matrix_init(SparseMatrix *m, int rows, int cols);

#define sparse_matrix_destroy list_destroy

#define sparse_matrix_row(m) ((m)->data.row)

#define sparse_matrix_col(m) ((m)->data.col)

enum Status sparse_matrix_set(SparseMatrix *m, int row, int col, double value);

double sparse_matrix_get(SparseMatrix *m, int row, int col);

void sparse_matrix_add(SparseMatrix *c, SparseMatrix *a, SparseMatrix *b);
