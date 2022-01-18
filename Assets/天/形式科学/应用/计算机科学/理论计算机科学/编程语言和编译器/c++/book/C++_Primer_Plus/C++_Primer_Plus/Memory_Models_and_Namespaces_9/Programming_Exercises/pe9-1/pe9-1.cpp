#include "golf.h"
#include <iostream>
#include <string.h>
void setgolf(golf & g, const char * name, int hc)
{
  //  g.fullname = name;
  strcpy(g.fullname, name);
  g.handicap = hc;
}

int setgolf(golf & g)
{
  int r_int = 0;
  std::cout << "Enter fullname and handicap: ";
  if (std::cin >> g.fullname)
    r_int = 1;
  std::cin >> g.handicap;
  return r_int;
}

void handicap(golf & g, int hc)
{
  g.handicap = hc;
}

void showgolf(const golf & g)
{
  std::cout << "fullname: " << g.fullname
	    << '\t' << "handicap: " << g.handicap << '\n';
}

