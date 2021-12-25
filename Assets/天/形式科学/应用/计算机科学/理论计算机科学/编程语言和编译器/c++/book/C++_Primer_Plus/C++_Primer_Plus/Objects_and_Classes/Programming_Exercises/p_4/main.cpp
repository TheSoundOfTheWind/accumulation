#include "ns.h"
#include <algorithm>
int main()
{
  using namespace SALES;
  // sales1
  int ar_size = 3;
  double ar[ar_size] = {12, 13, 14};
  Sales s1(ar, ar_size);
  s1.showSales();
  //sales 2
  Sales s2(s1);
  s2.showSales();

  return 0;
}
