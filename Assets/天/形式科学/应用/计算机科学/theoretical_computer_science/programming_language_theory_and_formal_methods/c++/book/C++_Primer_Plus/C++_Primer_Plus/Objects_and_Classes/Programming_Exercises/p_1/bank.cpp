#include "bank.h"
#include <iostream>
Bank::Bank()
{
  m_name = "";
  m_number = "";
  m_balance = 0.0;
}

Bank::~Bank()
{
}

void Bank::display()
{
  std::cout << "name " << m_name << std::endl;
  std::cout << "number " << m_number << std::endl;
  std::cout <<  "balance " << m_balance << std::endl;
}

void Bank::deposit(const double money)
{
  if(money < 0)
    std::cout << "deposit faild\n";
  m_balance += money;
}

void Bank::withdraw(const double money)
{
  if(money < 0)
    std::cout << "withdraw faild\n";
  m_balance -= money;
}

void Bank::set_name(const std::string & name)
{
  m_name = name;
}
void Bank::set_number(const std::string & num)
{
  m_number = num;
}
