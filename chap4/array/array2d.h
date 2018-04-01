#pragma once

#include "array.h"

struct Array2D {
  int rows;
  int cols;
  Array buffer;
};

enum Status array2d_init(struct Array2D *array, int rows, int cols);

void array2d_destroy(struct Array2D *array);

DataType array2d_get(struct Array2D *array, int row, int col);

void array2d_set(struct Array2D *array, int row, int col, DataType data);
