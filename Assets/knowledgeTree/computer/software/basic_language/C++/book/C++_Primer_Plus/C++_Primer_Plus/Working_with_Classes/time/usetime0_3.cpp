// usetime0.cpp -- using the first draft of the Time class
// compile usetime0_3.cpp and mytime0_2.cpp together
#include <iostream>
#include "mytime0_1.h"

int main()
{
  using std::cout;
  using std::endl;
  Time planning;
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;

  cout << "planning time = ";
  planning.Show();
  cout << endl;

  cout << "coding time = ";
  coding.Show();
  cout << endl;

  cout << "fixing time = ";
  fixing.Show();
  cout << endl;

  total = coding.Sum(fixing);
  cout << "coding.sum(fixing) = ";
  total.Show();
  cout << endl;

  return 0;
}
