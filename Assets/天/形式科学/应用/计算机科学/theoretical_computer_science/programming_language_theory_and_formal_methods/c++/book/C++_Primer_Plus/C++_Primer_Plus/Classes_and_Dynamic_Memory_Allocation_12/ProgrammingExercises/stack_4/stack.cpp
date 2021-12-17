#include <stdio.h>
#include "stack.h"

Stack::Stack(int n):size(0)
{
  pitems = new Item[n];
  top = 0;
}

Stack::Stack(const Stack & st)
{
  top = st.top;
  pitems = new Item[MAX];
  for (int i = 0; i < top; ++i) {
    pitems[i] = st.pitems[i];
  }
}

Stack::~Stack()
{
  delete [] pitems;
  top = 0;
}

bool Stack::isempty() const
{
  return top == 0 ? true : false;
}

bool Stack::isfull() const
{
  return MAX == top ? true : false;
}

// push() returns false if stack already is full, true otherwise
bool Stack::push(const Item & item)        // add item to stack
{
  if (top < MAX) {
    pitems[top++] = item;
    size++;
    return true;
  }
  else {
    return false;
  }
}

// pop() return false if stack already is empty, true otherwise
bool Stack::pop(Item & item)                   // pop top into item
{
  if (top > 0)  {
    item = pitems[--top];
    size--;
    return true;
  }
  else {
    return false;
  }
}

Stack & Stack::operator=(const Stack & st)
{
  delete [] pitems;
  top = st.top;
  pitems = new Item[MAX];
  for (int i = 0; i < top; ++i) {
    pitems[i] = st.pitems[i];
  }
  return *this;
}
