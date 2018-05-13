#pragma once

typedef int DataType;

struct Matrix {
  int rows;
  int cols;
  int mode; // 0: row-major, 1: column-major
  DataType *buffer;
};

void matrix_init(struct Matrix *m, int rows, int cols, int mode);

void matrix_destroy(struct Matrix *m);

DataType matrix_get(struct Matrix *m, int row, int col);

void matrix_set(struct Matrix *m, int row, int col, DataType data);

void matrix_print(struct Matrix *m);

