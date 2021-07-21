#include <iostream>
long unsigned int factorial(long unsigned int);
int main()
{
  int n = 0;
  std::cout << "Enter number: ";
  while(std::cin >> n)
    {
      std::cout << "factorial is " << factorial(n) << std::endl;
      std::cout << "Enter number: ";
    }
  return 0;
}

long unsigned int factorial(long unsigned int n)
{
  if(n == 0 or n==1)
    return 1;
  return n*factorial(n-1);
}
