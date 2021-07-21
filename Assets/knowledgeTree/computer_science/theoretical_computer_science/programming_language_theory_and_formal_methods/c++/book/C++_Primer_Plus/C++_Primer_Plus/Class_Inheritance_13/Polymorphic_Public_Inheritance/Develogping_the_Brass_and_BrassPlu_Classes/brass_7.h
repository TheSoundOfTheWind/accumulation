// brass_7.h -- bank account classes
#ifndef BRASS_7_H
#define BRASS_7_H
#include <string>
// Brass Account Class
class Brass
{
 private:
  std::string fullName;
  long acctNum;
  double balance;
 public:
  Brass(const std::string & s = "Nullbody", long an = -1,
	double bal = 0.0);
  void Deposit(double amt);
  double Balance() const;
  virtual void Withdraw(double amt);
  virtual void ViewAcct() const;
  virtual ~Brass() {}
};
#endif // BRASS_7_H

// Brass Plus Account Class
class BrassPlus : public Brass
{
 private:
  double maxLoan;
  double rate;
  double owesBank;
 public:
  BrassPlus(const std::string & s = "Nullbody", long an = -1,
	    double bal = 0.0, double m1 = 500, double r = 0.11125);
  BrassPlus(const Brass & ba, double ml = 500,
	    double r = 0.11125);
  virtual void ViewAcct() const;
  virtual void Withdraw(double amt);
  void ResetMax(double m) {maxLoan = m;}
  void ResetRate(double r) {rate = r;};
  void ResetOwes()         {owesBank = 0;}
};
