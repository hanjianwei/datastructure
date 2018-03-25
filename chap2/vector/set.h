#pragma once

#include "vector.h"

/* Set operations */
void vector_union(struct Vector *c, struct Vector *a, struct Vector *b);
void vector_intersection(struct Vector *c, struct Vector *a, struct Vector *b);
