<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "MathFunctions.h"

int main(int argc, char * argv[])
{
  if (argc < 3) {
    printf("Usage: %s base exponent \n", argv[0]);
    return 1;
  }

  double base = atof(argv[1]);
  int exponent = atoi(argv[2]);
  double result = power(base, exponent);
  printf("%g ^ %d is %g\n", base, exponent, result);

  return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include "MathFunctions.h"

int main(int argc, char * argv[])
{
  if (argc < 3) {
    printf("Usage: %s base exponent \n", argv[0]);
    return 1;
  }

  double base = atof(argv[1]);
  int exponent = atoi(argv[2]);
  double result = power(base, exponent);
  printf("%g ^ %d is %g\n", base, exponent, result);

  return 0;
}
>>>>>>> 1d751b2d5d0f314aae5ee85cadda02a076b13d0f
