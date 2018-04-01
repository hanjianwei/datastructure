#include "array.h"

enum Status array_init(Array *array, int size) {
  enum Status err = vector_init(array, size);
  array->size = size;
  return err;
}

DataType array_get(Array *array, int index) {
  return array->buffer[index];
}

void array_set(Array *array, int index, DataType data) {
  array->buffer[index] = data;
}
