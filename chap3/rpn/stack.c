#include "stack.h"

DataType stack_pop(Stack *stack) {
  DataType data = stack_peek(stack);
  list_pop_front(stack);

  return data;
}
