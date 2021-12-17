//randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>        // rand(), srand() prototypes
#include <ctime>          // time() prototype
#include "vect_13.h"
#include <algorithm>
#include <vector>
int main()
{
  using namespace std;
  using VECTOR::Vector;
  srand(time(0));         // seed random-number generator

  double direction;
  Vector step;
  Vector result (0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
  unsigned int trials_num = 0;
  cout << "Enter target distance and number of trials (q to quit): ";
  while (cin >> target and cin >> trials_num)
    {
      cout << "Enter step length: ";
      if (!(cin >> dstep))
	break;
      int sum_steps = 0;
      std::vector<int> steps_list;
      for (unsigned int i = 0; i < trials_num; ++i)
	{
	  while(result.magval() < target)
	    {
	      direction = rand() %360;
	      step.reset(dstep, direction, Vector::POL);
	      result = result + step;
	      steps++;
	    }
	  steps_list.push_back(steps);
	  sum_steps += steps;
	  result.reset(0.0, 0.0);
	  steps = 0;
	}
      std::sort(steps_list.begin(), steps_list.end());
      int h_steps = steps_list.back();
      int l_steps = steps_list.front();
      int a_steps = sum_steps / trials_num;
      cout << "highest steps : " << h_steps << " lowest steps : " << l_steps
	   << " average steps : " << a_steps << std::endl;
      cout << "Enter target distance and number of trials (q to quit): ";
    }
  cout << "Bye!\n";
  cin.clear();
  while(cin.get() != '\n')
    continue;

  return 0;
}
