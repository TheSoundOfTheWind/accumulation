//randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>        // rand(), srand() prototypes
#include <ctime>          // time() prototype
#include "vect_13.h"

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
  ofstream out("out.txt");
  cout << "Enter target distance (q to quit): ";
  while (cin >> target)
    {
      cout << "Enter step length: ";
      if (!(cin >> dstep))
	break;
      if(!out.is_open())
	break;
      out << "Target Disrance: " << target << ", Step Size: " << dstep << '\n';
      while(result.magval() < target)
	{
	  direction = rand() %360;
	  step.reset(dstep, direction, Vector::POL);
	  result = result + step;
	  result.rect_mode();
	  out << steps << ": " << result << '\n';
	  steps++;
	}
      out << "After " << steps << " steps, the subject "
	"has the following location:\n";
      out << result << endl;
      result.polar_mode();
      out << " or\n" <<result << endl;
      out << "Average outward distance per step = "
	   << result.magval()/steps << endl;
      steps = 0;
      result.reset(0.0, 0.0);
      cout << "Enter target distance (q to quit): ";
    }
  cout << "Bye!\n";
  cin.clear();
  while(cin.get() != '\n')
    continue;

  return 0;
}
