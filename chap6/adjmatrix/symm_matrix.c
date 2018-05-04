#include "symm_matrix.h"

int symm_matrix_coord_to_index(SymmMatrix *m, int row, int col) {
  return row >= col ? col + row * (row + 1) / 2
                    : symm_matrix_coord_to_index(m, col, row);
}

DataType symm_matrix_get(SymmMatrix *m, int row, int col) {
  return m->buffer[symm_matrix_coord_to_index(m, row, col)];
}

void symm_matrix_set(SymmMatrix *m, int row, int col, DataType data) {
  m->buffer[symm_matrix_coord_to_index(m, row, col)] = data;
}
