#include "stack.h"
#include <iostream>
Stack::Stack()
{
  m_tol_pay = 0;
}
void Stack::push(const customer& cus)
{
  m_cus_stack.push(cus);
}
void Stack::pop()
{
  m_tol_pay += m_cus_stack.top().payment;
  m_cus_stack.pop();
  std::cout << "totall payment is " << m_tol_pay << std::endl;
}

int Stack::size()
{
  return m_cus_stack.size();
}
