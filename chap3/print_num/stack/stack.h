#pragma once

#include "vector.h"

typedef struct Vector Stack;

#define stack_init vector_init

#define stack_destroy vector_destroy

#define stack_size vector_size

#define stack_empty(stack) ((stack)->size == 0)

#define stack_push vector_push_back

#define stack_peek(stack) (stack)->buffer[(stack)->size - 1]

DataType stack_pop(Stack *stack);
