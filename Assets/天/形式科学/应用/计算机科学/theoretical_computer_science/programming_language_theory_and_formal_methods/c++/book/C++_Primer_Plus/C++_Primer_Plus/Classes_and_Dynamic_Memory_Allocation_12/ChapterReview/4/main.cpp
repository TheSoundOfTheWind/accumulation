#include <iostream>
#include "nifty.h"

int main()
{
  nifty n1;
  std::cout << "test1 " << n1 << std::endl;
  char s[] = "jinhailin";
  nifty n2(s);
  std::cout << "test2 " << n2 << std::endl;

  return 0;
}
