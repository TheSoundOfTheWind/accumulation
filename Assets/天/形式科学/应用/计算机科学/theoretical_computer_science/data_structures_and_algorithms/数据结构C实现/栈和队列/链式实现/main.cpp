#include <stdio.h>
#include "stack.h"

int main()
{
  Stack stack;
  initStack(stack);
  for (int i = 10; i >= 1; --i) {
    push(stack, i);
  }
  traverse(stack);
  printf("\n");

  printf("top \n");
  for(int i = 0; i < 5; ++i) {
    int e = 0;
    if (false == pop(stack, e))
      continue;
    printf("%d ", e);
  }
  printf("\n");

  if (false == empty(stack)) {
    printf("stack is no empty\n");
  }

  printf("length %d\n", length(stack));

  int e = 0;
  if (true == getTop(stack, e)) {
    printf("top %d\n", e);
  }

  clearStack(stack);
  traverse(stack);
  printf("\n");
  destroyStack(stack);

  return 0;
}
