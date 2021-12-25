// stone.cpp -- user-defined conversions
// compile with stonewt_18.cpp
#include <iostream>
#include "stonewt_16.h"
using std::cout;
int main()
{
  Stonewt s1(15.2, FLOAT_POUNDS);
  Stonewt s2(3.4, INT_POUNDS);
  Stonewt s3(19.56);
  cout << s1;
  cout << s2;
  cout << s3;
  cout << s1 + s2;
  cout << s1 - s2;
  cout << s1 * 2;
  cout << 2 * s1;
  return 0;
}

