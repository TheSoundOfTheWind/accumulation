#include <iostream>
#include <stdlib.h>
double add(double, double);

double subtraction(double, double);

double multiplication(double, double);

double division(double, double);

double calculate(double, double, double (*pf)(double, double));

typedef double (* p_fun)(double, double);
int main()
{
  using namespace std;
  double num1, num2;
  cout << "Enter num1, num2: ";
  p_fun pa[4] = {add, subtraction, multiplication, division};
  while(cin >> num1 >> num2)
    {
      printf("%-15s%-15s%-15s%-15s\n", "add", "subtraction", "multiplication", "division");
      printf("%-15.6lf%-15.6lf%-15.6lf%-15.6lf\n", calculate(num1, num2, pa[0]) \
	     , calculate(num1, num2, pa[1])				\
	     , calculate(num1, num2, pa[2])				\
	     , calculate(num1, num2, pa[3]) );
      printf("Enter num1, num2: ");
    }
  return 0;
}

double add(double num1, double num2)
{
  return num1 + num2;
}

double subtraction(double num1, double num2)
{
  return num1 - num2;
}

double multiplication(double num1, double num2)
{
  return num1 * num2;
}

double division(double num1, double num2)
{
  return num1 / num2;
}


double calculate(double num1, double num2, double (*pf)(double, double))
{
  return (*pf)(num1, num2);
}
