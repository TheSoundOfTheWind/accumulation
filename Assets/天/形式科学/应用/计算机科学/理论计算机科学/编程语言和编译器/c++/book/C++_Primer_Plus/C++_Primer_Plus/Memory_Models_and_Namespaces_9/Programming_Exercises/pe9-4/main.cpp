#include "ns.h"
int main()
{
  using namespace SALES;
  // sales1
  Sales s1;
  int ar_size = 3;
  double ar[ar_size] = {12, 13, 14};
  setSales(s1, ar, ar_size);
  showSales(s1);

  //sales 2
  Sales s2;
  setSales(s2);
  showSales(s2);
  
  return 0;
}
