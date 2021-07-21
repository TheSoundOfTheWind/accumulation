#include "ns.h"
#include <iostream>
#include <vector>
#include <algorithm>
namespace SALES{
  Sales::Sales(const double ar[], int n)
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
	    m_sales[i] = ar[i];
	  }

	// get average
	double total = 0;
	for(int i = 0; i < min; ++i)
	  total += m_sales[i];
	m_average = total / min;

	// get max
	std::vector<double> temp;
	for(int i = 0; i < min; ++i)
	  temp.push_back(m_sales[i]);
	std::sort(temp.begin(), temp.end());
	m_max = temp.at(min-1);

	// get min
	m_min = temp.at(0);
      }while(0);
  }

  Sales::Sales(Sales & s)
  {
    for(int i = 0; i < QUARTERS; ++i)
      {
	this->m_sales[i] = *(s.get_sales()+i);
      }
    this->m_average = s.get_average();
    this->m_max = s.get_max();
    this->m_min = s.get_min();
  }

  void Sales::showSales()
  {
    std::cout << "average: " << m_average << " max: "
	      << m_max << " min " << m_min << '\n';
  }

  const double * Sales::get_sales()
  {
    return m_sales;
  }

  const double Sales::get_average()
  {
    return m_average;
  }

  const double Sales::get_max()
  {
    return m_max;
  }

  const double Sales::get_min()
  {
    return m_min;
  }

};
