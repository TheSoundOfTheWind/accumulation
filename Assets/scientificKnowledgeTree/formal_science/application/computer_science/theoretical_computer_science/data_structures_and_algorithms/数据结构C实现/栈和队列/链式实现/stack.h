#ifndef STACK_H
#define STACK_H
typedef int ElemType;

const int STACKSIZE = 100;

typedef struct {
  ElemType * base;
  ElemType * top;
  int              stacksize;
} Stack;

// get mothods
// -----------------------------------------------------------------------------
bool         empty(const Stack &);
int            length(const Stack &);
bool         getTop(const  Stack &, ElemType &);
void          traverse(const Stack &);
// -----------------------------------------------------------------------------

// set methods
// -----------------------------------------------------------------------------
bool         initStack(Stack &);
bool         destroyStack(Stack &);
bool         clearStack(Stack &);
bool         pop(Stack &, ElemType & e);
bool         push(Stack &, const ElemType &);
// -----------------------------------------------------------------------------

#endif // STACK_H
