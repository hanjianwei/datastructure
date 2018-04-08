#pragma once

#include "list.h"

typedef struct List Stack;

#define stack_init list_init

#define stack_destroy list_destroy

#define stack_size list_size

#define stack_empty(stack) ((stack)->size == 0)

#define stack_push list_push_front

#define stack_peek(stack) ((stack)->head->data)

DataType stack_pop(Stack *stack);
