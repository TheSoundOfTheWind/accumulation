#include <iostream>
template <class T>
T large(T n1, T n2)
{
  return n1 > n2 ? n1 : n2;
}
int main()
{
  std::cout << large(1, 2) << std::endl;
  //  std::cout << large(1.2, 3) << std::endl;
  std::cout << large(3.2, 8.9) << std::endl;
  return 0;
}
