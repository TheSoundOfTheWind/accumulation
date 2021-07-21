#include "bank.h"
int main()
{
  Bank bank;
  bank.set_name("jinhailin");
  bank.set_number("542354354");
  bank.display();
  bank.deposit(32.3);
  bank.display();  
  bank.withdraw(2.3);
  bank.display();
  return 0;
}
