#include "stack.h"
#include <string.h>
int main()
{
  Stack stack;
  char fullname[35];
  double payment;
  for(int i = 0; i < 3; ++i)
    {
      std::cout << "Enter " << i+1 << " customer fullname and payment\n";
      memset(fullname, 0, sizeof fullname / sizeof fullname[0]);
      std::cin >> fullname >> payment;
      customer cus;
      strcpy(cus.fullname, fullname);
      cus.payment = payment;
      stack.push(cus);
    }
  int size = stack.size();
  for (int i = 0; i < size; ++i)
    {
      stack.pop();
    }


  return 0;
}
