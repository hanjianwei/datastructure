#pragma once

#include "vector.h"

typedef struct Vector Array;

enum Status array_init(Array *array, int size);

#define array_destroy vector_destroy

DataType array_get(Array *array, int index);

void array_set(Array *array, int index, DataType data);
