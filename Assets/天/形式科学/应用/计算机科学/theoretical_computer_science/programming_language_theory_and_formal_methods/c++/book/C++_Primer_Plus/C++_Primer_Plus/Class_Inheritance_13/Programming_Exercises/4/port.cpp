#include "port.h"
#include <cstring>

// set methods
// -----------------------------------------------------------------------------------------------------------------
Port::Port(const char * br, const char * st, int b):
  bottles(b)
{
  brand = new char[strlen(br)+1];
  strcpy(brand, br);
  strncpy(style, st, 20);
}  
// -----------------------------------------------------------------------------------------------------------------
Port::Port(const Port & p)
{
  brand = new char[strlen(p.brand)+1];
  strcpy(brand, p.brand);
  strncpy(style, p.style, 20);
  bottles = p.bottles;
}
// -----------------------------------------------------------------------------------------------------------------
Port & Port::operator=(const Port & p)
{
  delete [] brand;
  memset(style, 0, sizeof(style));
  brand = new char[strlen(p.brand)+1];
  strcpy(brand, p.brand);
  strncpy(style, p.style, 20);
  bottles = p.bottles;

  return *this;
}
// -----------------------------------------------------------------------------------------------------------------
Port & Port::operator+=(int b)
{
  bottles += b;

  return *this;
}
// -----------------------------------------------------------------------------------------------------------------
Port & Port::operator-=(int b)
{
  bottles -= b;

  return *this;
}
// -----------------------------------------------------------------------------------------------------------------

// get methods
// -----------------------------------------------------------------------------------------------------------------
void Port::Show() const
{
  std::cout << "--Port Show--" << std::endl;
  std::cout << "brand:" << brand << std::endl;
  std::cout << "syle:" << style << std::endl;
  std::cout << "bottles:" << bottles << std::endl;
}
// -----------------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & os, const Port & p)
{
  os << p.brand << " " << p.style << " " << p.bottles <<  " " << std::endl;

  return os;
}
// -----------------------------------------------------------------------------------------------------------------
