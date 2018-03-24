#pragma once

#include "vector.h"

/* Set operations */
void vector_union(struct vector *c, struct vector *a, struct vector *b);
void vector_intersection(struct vector *c, struct vector *a, struct vector *b);
