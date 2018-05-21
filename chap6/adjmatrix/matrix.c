#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix_init(struct Matrix *m, int rows, int cols, enum MatrixMode mode) {
  m->rows = rows;
  m->cols = cols;
  m->mode = mode;
  m->buffer = malloc(sizeof(DataType) * rows * cols);
  memset(m->buffer, 0, sizeof(DataType) * rows * cols);
}

void matrix_destroy(struct Matrix *m) {
  if (m->buffer != NULL) {
    free(m->buffer);
    m->buffer = NULL;
    m->rows = 0;
    m->cols = 0;
    m->mode = ROW_MAJOR;
  }
}

int matrix_coord_to_index(struct Matrix *m, int row, int col) {
  return m->mode == ROW_MAJOR ? col + row * m->cols : row + col * m->rows;
}

DataType matrix_get(struct Matrix *m, int row, int col) {
  return m->buffer[matrix_coord_to_index(m, row, col)];
}

void matrix_set(struct Matrix *m, int row, int col, DataType data) {
  m->buffer[matrix_coord_to_index(m, row, col)] = data;
}

void matrix_print(struct Matrix *m) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%5d", matrix_get(m, i, j));
    }
    printf("\n");
  }
}
