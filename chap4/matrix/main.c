#include "matrix.h"

#include <stdio.h>

int main() {
  struct Matrix m;

  matrix_init(&m, 5, 5, 1);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix_set(&m, i, j, i + j);
    }
  }

  matrix_print(&m);
  matrix_destory(&m);
}
