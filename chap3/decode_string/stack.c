#include "stack.h"

ListDataType stack_pop(Stack *stack) {
  ListDataType data = stack_peek(stack);
  list_pop_front(stack);

  return data;
}
