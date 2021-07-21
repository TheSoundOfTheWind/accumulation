#include "List.h"
#include <iostream>
int main()
{
  List l;
  l.add(321);
  l.add(32);
  if(l.empty())
    std::cout << "list is empty\n";
  l.visit();
  return 0;
}
