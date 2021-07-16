#include <iostream>
const unsigned int SIZE = 5;
template <typename T> T max5(T array[SIZE])
{
  T max;
  if (SIZE > 0)
    max = array[0];
  for(int i = 1; i < SIZE; ++i)
    {
      max = max > array[i] ? max : array[i];
    }
  return max;
}
int main()
{
  int array_int[5] = {1, 2, 9, -1, 0};
  std::cout << "array_int max is " << max5(array_int) << std::endl;

  double array_double[5] = {1.2, 5.8, 9.8, -5.2, 8.9};
  std::cout << "array_double max is " << max5(array_double) << std::endl;

  return 0;
}
