#include "sparse_matrix.h"

#include <stdio.h>
#include <stdlib.h>

void print_matrix(SparseMatrix *m) {
  int rows = m->rows;
  int cols = m->cols;

  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%5.1f ", sparse_matrix_get(m, i, j));
    }
    printf("\n");
  }
}

int main() {
  SparseMatrix a, b, c;

  sparse_matrix_init(&a, 5, 5);
  sparse_matrix_init(&b, 5, 5);
  sparse_matrix_init(&c, 5, 5);

  // Create matrix a
  sparse_matrix_set(&a, 0, 0, 1.0);
  sparse_matrix_set(&a, 2, 1, 2.0);
  sparse_matrix_set(&a, 3, 4, 0.0);
  sparse_matrix_set(&a, 1, 3, 3.0);
  sparse_matrix_set(&a, 4, 4, 4.0);

  // Create matrix b
  sparse_matrix_set(&b, 0, 0, -1.0);
  sparse_matrix_set(&b, 2, 1, 1.0);
  sparse_matrix_set(&b, 3, 3, 2.0);
  sparse_matrix_set(&b, 1, 3, 5.0);
  sparse_matrix_set(&b, 4, 3, 4.0);

  // c = a + b
  sparse_matrix_add(&c, &a, &b);

  print_matrix(&a);
  print_matrix(&b);
  print_matrix(&c);

  sparse_matrix_destroy(&a);
  sparse_matrix_destroy(&b);
  sparse_matrix_destroy(&c);

  return 0;
}
