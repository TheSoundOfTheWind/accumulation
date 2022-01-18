#include "List.h"
#include <iostream>
List::List()
{
  len = 0;
}

void List::add(const Item & i)
{
  if (len < MAX)
    items[len++] = i;
}

bool List::empty()
{
  if(0 == len)
    return true;
  else
    return false;
}

bool List::full()
{
  if(MAX == len)
    return true;
  else
    return false;
}

void List::visit()
{
  for(int i = 0; i < len; ++i)
    std::cout << "item " << items[i]
	      << std::endl;
}
