// formore.cpp -- more looping with for
#include <iostream>
const int value=100;
int main() {
  long double factorials = 1;


  for (int i = 2; i < value; i++)
    factorials = i * factorials;
  std::cout << value << "! = " << factorials << std::endl;

  return 0;
}
