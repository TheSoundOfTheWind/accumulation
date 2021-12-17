#pragma once
#include <ostream>
#include <istream>
class complex
{
 private:
  // real number
  double m_r;
  // imaginary number
  double m_i;
 public:
  complex()
  {
    m_r = 0;
    m_i = 0;
  }
  complex(const double & r, const double & i)
  {
    m_r = r;
    m_i = i;
  }
  // complex + complex
  complex operator+(const complex & c) const;

  // complex - complex
  complex operator-(const complex & c) const;

  // complex * complex
  complex operator*(const complex & c) const;

  // complex * num
  complex operator*(const double & n) const;

  // num * complex
  friend complex operator*(const double & n, const complex & c);

  // ~a
  complex operator~() const;

  // <<
  friend std::ostream & operator<<(std::ostream & os, const complex & c);

  // >>
  friend std::istream & operator>>(std::istream & is,complex & c);
};
