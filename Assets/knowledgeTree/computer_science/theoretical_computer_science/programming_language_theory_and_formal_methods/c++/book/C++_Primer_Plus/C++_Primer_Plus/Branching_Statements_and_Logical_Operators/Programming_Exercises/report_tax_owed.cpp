#include <iostream>
int main()
{
  double incomes = 0;
  double tax = 0;
  std::cout << "Enter incomes: ";  
  while(std::cin >> incomes)
    {

      if(incomes < 0)
	break;
      else if(incomes < 5000)
	tax = 0;
      else if(incomes < 15000)
	tax = (incomes-5000)*(0.1);
      else if(incomes < 35000)
	tax = 10000*0.1 + (incomes-15000)*0.15;
      else 
	tax = 10000*0.1 + 20000*0.15 + (incomes-35000)*0.2;
      std::cout << "tax owed: " << tax << std::endl;
      std::cout << "Enter incomes: ";
    }
  std::cout << "Bye!" << std::endl;
  
  return 0;
}
