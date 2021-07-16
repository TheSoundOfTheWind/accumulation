#include "Str.h"
#include <string.h>
#include <stdio.h>
Str::Str()
{
  len = 0;
  str = new char[1];
  str[0] = '\0';
}

Str::Str(const char * s)
{
  len = strlen(s);
  str = new char[len+1];
  strcpy(str, s);
  str[len] = '\0';
}

Str::~Str()
{
  delete [] str;
}

const char * Str::c_str()
{
  return str;
}

