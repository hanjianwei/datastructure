#pragma once

#include "matrix.h"

typedef struct Matrix DlgMatrix;

#define dlg_matrix_init(m, r) matrix_init(m, r, r, 0)

#define dlg_matrix_destroy matrix_destroy

DataType dlg_matrix_get(DlgMatrix *m, int row, int col);

void dlg_matrix_set(DlgMatrix *m, int row, int col, DataType data);
