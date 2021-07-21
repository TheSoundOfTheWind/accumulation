#include "golf.h"
#include <iostream>
#include <string.h>
golf::golf(const char * name, int hc)
{
  //  g.fullname = name;
  strcpy(fullname, name);
  handicap = hc;
}

golf::golf()
{
  std::cout << "Enter fullname and handicap: ";
  std::cin >> fullname;
  std::cin >> handicap;
}

golf::golf(const golf & g)
{
  strcpy((*this).fullname, g.fullname);
  (*this).handicap = g.handicap;
}

void golf::show()
{
  std::cout << fullname << " " << handicap << std::endl;
}



