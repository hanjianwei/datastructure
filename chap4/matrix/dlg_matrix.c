#include "dlg_matrix.h"

int dlg_matrix_coord_to_index(DlgMatrix *m, int row, int col) {
  if (col - row > 1 || col - row < -1) {
    return -1;
  }

  return 2 * row + col;
}

DataType dlg_matrix_get(DlgMatrix *m, int row, int col) {
  int index = dlg_matrix_coord_to_index(m, row, col);
  return index < 0 ? 0 : m->buffer[index];
}

void dlg_matrix_set(DlgMatrix *m, int row, int col, DataType data) {
  int index = dlg_matrix_coord_to_index(m, row, col);
  if (index >= 0) {
    m->buffer[dlg_matrix_coord_to_index(m, row, col)] = data;
  }
}
