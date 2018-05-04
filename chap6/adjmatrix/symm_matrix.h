#pragma once

#include "matrix.h"

typedef struct Matrix SymmMatrix;

#define symm_matrix_init(m, r) matrix_init(m, r, r, 0)

#define symm_matrix_destroy matrix_destroy

DataType symm_matrix_get(SymmMatrix *m, int row, int col);

void symm_matrix_set(SymmMatrix *m, int row, int col, DataType data);
