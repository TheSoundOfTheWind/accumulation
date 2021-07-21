#include "ns.h"
#include <algorithm>
#include <iostream>
#include <vector>
namespace SALES{
void setSales(Sales & s, const double ar[], int n)
{
  do
    {
      // check n value
      if (n < 0)
	break;

      // get min item size
      unsigned int min = (n > 4)?4:n;

      // set sales
      for(int i = 0; i < min; ++i)
	{
	  s.sales[i] = ar[i];
	}

      // get average
      double total = 0;
      for(int i = 0; i < min; ++i)
	total += s.sales[i];
      s.average = total / min;

      // get max
      std::vector<double> temp;
      for(int i = 0; i < min; ++i)
	temp.push_back(s.sales[i]);
      std::sort(temp.begin(), temp.end());
      s.max = temp.at(min-1);

      // get min
      s.min = temp.at(0);
    }while(0);
}

void setSales(Sales & s)
{
  std::cout << "Enter 4 quarters interactively: ";
  for (int i = 0; i < 4; ++i)
    std::cin >> s.sales[i];
  const unsigned int size = 4;
  // get average
  double total = 0;
  for(int i = 0; i < size; ++i)
    total += s.sales[i];
  s.average = total / size;

  // get max
  std::vector<double> temp;
  for(int i = 0; i < size; ++i)
    temp.push_back(s.sales[i]);
  std::sort(temp.begin(), temp.end());
  s.max = temp.at(size-1);

  // get min
  s.min = temp.at(0);
}

void showSales(const Sales & s)
{
  std::cout << "average: " << s.average << " max: "
	    << s.max << " min " << s.min << '\n';
}
};
