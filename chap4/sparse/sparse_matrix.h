#include "list.h"

typedef struct List SparseMatrix;

void sparse_matrix_set(SparseMatrix *m, int row, int col, double value);

double sparse_matrix_get(SparseMatrix *m, int row, int col);
