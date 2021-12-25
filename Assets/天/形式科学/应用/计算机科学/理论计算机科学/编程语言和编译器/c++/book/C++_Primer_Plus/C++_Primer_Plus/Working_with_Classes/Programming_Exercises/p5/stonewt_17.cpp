// stonewt_17.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt_16.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, FORM form)
{
  stone = int (lbs) / Lbs_per_stn;       // integer division
  pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
  pounds = lbs;
  m_form = form;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, FORM form)
{
  stone = stn;
  pds_left = lbs;
  pounds = stn * Lbs_per_stn + lbs;
  m_form = form;
}

Stonewt::Stonewt(FORM form)            // default constructor, wt = 0
{
  stone = pounds = pds_left = 0;
  m_form = form;
}

Stonewt::~Stonewt()            // destructor
{
}

Stonewt Stonewt::operator+(const Stonewt & s) const
{
  return Stonewt(pounds + s.pounds, m_form);
}

Stonewt Stonewt::operator-(const Stonewt & s) const
{
  return Stonewt(pounds - s.pounds, m_form);
}

Stonewt Stonewt::operator*(const double & d) const
{
  return Stonewt(pounds * d, m_form);
}

Stonewt operator*(const double & d, const Stonewt & s)
{
  return s * d;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
  switch(s.m_form)
    {
    case STONE:
      os << "stone is " << s.stone << "\n";
      break;
    case INT_POUNDS:
      os << "int pounds is " << int(s.pounds) << "\n";
      break;
    case FLOAT_POUNDS:
      os << "float pounds is " << s.pounds << "\n";
      break;
    default:
      os << "unsupport the form\n";
      break;
    };
  return os;
}

