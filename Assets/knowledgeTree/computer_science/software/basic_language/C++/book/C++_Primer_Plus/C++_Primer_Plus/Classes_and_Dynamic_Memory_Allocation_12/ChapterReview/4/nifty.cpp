#include <string.h>
#include "nifty.h"

nifty::nifty()
{
  personality = new char[1];
  personality[0] = '\0';
  talents = 0;
}

nifty::nifty(char * s)
{
  personality = new char[strlen(s)+1];
  strcpy(personality, s);
  talents = strlen(s);
}

std::ostream & operator<<(std::ostream & os, const nifty & n)
{
  os << n.personality;
  return os;
}
