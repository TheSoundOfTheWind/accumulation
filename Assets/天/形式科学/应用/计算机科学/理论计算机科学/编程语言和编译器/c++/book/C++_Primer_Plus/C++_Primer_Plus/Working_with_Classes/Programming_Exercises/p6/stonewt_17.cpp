// stonewt_17.cpp -- Stonewt methods
#include <iostream>
#include "stonewt_16.h"
using std::cout;
// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
  stone = int (lbs) / Lbs_per_stn;       // integer division
  pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
  pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
  stone = stn;
  pds_left = lbs;
  pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()            // default constructor, wt = 0
{
  stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()            // destructor
{
}

bool Stonewt::operator==(const Stonewt & s) const
{
  return pounds == s.pounds;
}

bool Stonewt::operator!=(const Stonewt & s) const
{
  return pounds != s.pounds;
}

bool Stonewt::operator>(const Stonewt & s) const
{
  return pounds > s.pounds;
}

bool Stonewt::operator<(const Stonewt & s) const
{
  return pounds < s.pounds;
}

bool Stonewt::operator>=(const Stonewt & s) const
{
  return pounds >= s.pounds;
}

bool Stonewt::operator<=(const Stonewt & s) const
{
  return pounds <= s.pounds;
}


std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
  os << "int pounds is " << int(s.pounds) << "\n";
  return os;
}

