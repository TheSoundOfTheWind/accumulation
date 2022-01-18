#include "vintagePort.h"
#include "cstring"
// set methods
// ------------------------------------------------------------------------
VintagePort::VintagePort():
  Port(),
  year(0)
{
  nickname = new char[5];
  strcpy(nickname, "none");
}
// ------------------------------------------------------------------------
VintagePort::VintagePort(const char * br, int b, const char * nn, int y):
  Port(br, "vintage", b),
  year(y)
{
  nickname = new char[strlen(nn)+1];
  strcpy(nickname, nn);
}
// ------------------------------------------------------------------------
VintagePort::VintagePort(const VintagePort & vp):
  Port(vp),
  year(vp.year)
{
  nickname = new char[strlen(vp.nickname)+1];
  strcpy(nickname, vp.nickname);
}
// ------------------------------------------------------------------------
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
  if (this == &vp) {
    return *this;
  }
  Port::operator=(vp);
  delete [] nickname;
  nickname = new char[strlen(vp.nickname)+1];
  strcpy(nickname, vp.nickname);
  year = vp.year;
}

// get methods
// ------------------------------------------------------------------------
void VintagePort::Show() const
{
  std::cout << "--VintagePort Show--" << std::endl;
  Port::Show();
  std::cout << "nickname:" << nickname << std::endl;
  std::cout << "year:" << year << std::endl;
}
// ------------------------------------------------------------------------
ostream & operator<<(ostream & os, const VintagePort & vp)
{
  os << (Port &) vp;
  os << " " << vp.nickname << " " << vp.year << std::endl;
}
