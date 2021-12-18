#include <stdio.h>
#include "stack.h"
// get mothods
// -----------------------------------------------------------------------------
bool empty(const Stack & stack)
{
  return stack.base == stack.top;
}

int length(const Stack & stack)
{
  return stack.top-stack.base;
}

bool getTop(const  Stack & stack, ElemType & e)
{
  if (stack.top == stack.base) {
    return false;
  }
  e = *stack.top;

  return true;
}

void traverse(const Stack & stack)
{
  ElemType * top = stack.top;
  while(top != stack.base) {
    printf("%d ", *(--top));
  }
}
// -----------------------------------------------------------------------------

// set methods
// -----------------------------------------------------------------------------
bool initStack(Stack & stack)
{
  stack.base = new ElemType[STACKSIZE];
  stack.top = stack.base;
  stack.stacksize = STACKSIZE;
}

bool destroyStack(Stack & stack)
{
  delete [] stack.base;
  stack.base = nullptr;
  stack.top    = nullptr;
  stack.stacksize = STACKSIZE;  
}

bool clearStack(Stack & stack)
{
  stack.top = stack.base;
  stack.stacksize = STACKSIZE;    
}

bool pop(Stack & stack, ElemType & e)
{
  bool r_b = false;
  if (stack.top != stack.base) {
    e = *--stack.top;
    r_b = true;
  }

  return r_b;
}

bool push(Stack & stack, const ElemType & e)
{
  bool r_b = true;
  if ((stack.top - stack.base) == STACKSIZE)  {
    r_b = false;
  }
  *stack.top = e;
  stack.top ++;
  return r_b;
}
// -----------------------------------------------------------------------------
