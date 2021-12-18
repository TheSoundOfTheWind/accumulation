#ifndef STACK_H_
#define STACK_H_
#include <stack>
#include <iostream>
struct customer {
  char fullname[35];
  double payment;
};
class Stack {
 private:
  double m_tol_pay;
  std::stack<customer> m_cus_stack;
 public:
  Stack();
  void push(const customer&);
  void pop();
  int size();
};
#endif /* STACK_H_ */
