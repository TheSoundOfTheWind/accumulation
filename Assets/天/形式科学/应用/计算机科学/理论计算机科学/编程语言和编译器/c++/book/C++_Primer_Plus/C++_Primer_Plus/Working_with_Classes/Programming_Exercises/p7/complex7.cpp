#include "complex7.h"
#include <iostream>
// complex + complex
complex complex::operator+(const complex & c) const
{
  return complex(m_r + c.m_r, m_i + c.m_i);
}

// complex - complex
complex complex::operator-(const complex & c) const
{
  return complex(m_r - c.m_r, m_i - c.m_i);
}

// complex * complex
complex complex::operator*(const complex & c) const
{
  return complex((m_r * c.m_r) - (m_i * c.m_i), (m_r * c.m_i) + (m_i * c.m_r));
}

// complex * num
complex complex::operator*(const double & n) const
{
  return complex(m_r * n, m_i * n);
}

// num * complex
complex operator*(const double & n, const complex & c)
{
  return c * n;
}

// ~a
complex complex::operator~() const
{
  return complex(m_r, -m_i);
}

// <<
std::ostream & operator<<(std::ostream & os, const complex & c)
{
  os << "(" << c.m_r << "," << c.m_i << "i)\n";
  return os;
}

// >>
std::istream & operator>>(std::istream & is, complex & c)
{
  std::cout << "real: ";
  if(!(is >> c.m_r))
    return is;
  std::cout << "imaginary: ";
	       is >> c.m_i;
  return is;
}
