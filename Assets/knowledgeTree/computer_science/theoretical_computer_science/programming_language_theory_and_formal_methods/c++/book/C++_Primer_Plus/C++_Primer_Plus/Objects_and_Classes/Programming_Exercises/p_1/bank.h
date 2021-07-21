#ifndef BANK_H_
#define BANK_H_
#include<string>
class Bank {
 private:
  std::string m_name;
  std::string m_number;
  double m_balance;

 public:
  Bank();
  ~Bank();
  void display();
  void deposit(const double money);
  void withdraw(const double money);
  void set_name(const std::string & name);
  void set_number(const std::string & num);
};

#endif
