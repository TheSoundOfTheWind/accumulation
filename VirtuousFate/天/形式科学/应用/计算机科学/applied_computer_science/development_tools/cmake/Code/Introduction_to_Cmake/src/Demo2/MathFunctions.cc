<<<<<<< HEAD
#include "MathFunctions.h"

double power(double base, int exponent)
{
  int result = base;
  int i;

  if (exponent == 0) {
    return 1;
  }

  for (i = 1; i < exponent; ++i) {
    result = result * base;
  }

  return result;
}
=======
#include "MathFunctions.h"

double power(double base, int exponent)
{
  int result = base;
  int i;

  if (exponent == 0) {
    return 1;
  }

  for (i = 1; i < exponent; ++i) {
    result = result * base;
  }

  return result;
}
>>>>>>> 1d751b2d5d0f314aae5ee85cadda02a076b13d0f
