#include <iostream>
double harmonic(double , double );
int main()
{
  double x = 0;
  double y = 0;
  std::cout << "Enter x and y: ";
  while (std::cin >> x >> y)
    {
      if(x == 0 or y == 0)
	break;
      std::cout << "Harmonic mean is ";
      std::cout << harmonic(x,y) << std::endl;
      std::cout << "Enter x and y: ";
    }

  return 0;
}

double harmonic(double x, double y)
{
  return 2.0*x*y/(x+y);
}
