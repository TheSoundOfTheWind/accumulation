#include "Str.h"
#include <stdio.h>
int main()
{
  char test[] = "test1";

  Str str(test);
  Str str2("test2");
  Str * s = new Str("test3");
  
  printf("str:%s\n", str.c_str());
  printf("str:%s\n", str2.c_str());
  printf("str:%s\n", s->c_str());

  delete s;

  return 0;
}
