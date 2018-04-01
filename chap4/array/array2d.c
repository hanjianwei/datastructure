#include "array2d.h"

enum Status array2d_init(struct Array2D *array, int rows, int cols) {
  array->rows = rows;
  array->cols = cols;
  return array_init(&array->buffer, rows * cols);
}

void array2d_destroy(struct Array2D *array) { array_destroy(&array->buffer); }

DataType array2d_get(struct Array2D *array, int row, int col) {
  return array_get(&array->buffer, row * array->cols + col);
}

void array2d_set(struct Array2D *array, int row, int col, DataType data) {
  array_set(&array->buffer, row * array->cols + col, data);
}
