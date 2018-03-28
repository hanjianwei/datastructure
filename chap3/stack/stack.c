#include "stack.h"


DataType stack_pop(Stack *stack) {
  DataType data = stack_peek(stack);
  vector_pop_back(stack);

  return data;
}
