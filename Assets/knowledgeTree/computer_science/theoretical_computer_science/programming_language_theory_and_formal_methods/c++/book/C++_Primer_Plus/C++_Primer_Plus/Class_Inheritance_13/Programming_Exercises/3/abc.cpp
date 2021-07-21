#include "abc.h"
#include "stdio.h"
#include <cstdlib>
#include <cstring>
baseDMA::baseDMA(const char * l, int r)
{
  label = new char[std::strlen(l) + 1];
  std::strcpy(label, l);
  rating = r;
}
baseDMA::baseDMA(const baseDMA & rs)
{
  label = new char[std::strlen(rs.label)+1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
}
baseDMA::~baseDMA()
{
  delete label;
  rating = 0;
}
void baseDMA::view()
{
  printf("baseDMA view()\n");
  printf("label: %s\n", label);
  printf("rating: %d\n", rating);
}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
  if (this == &rs) {
    return *this;
  }
  delete label;
  label = new char[std::strlen(rs.label)];
  std::strcpy(label, rs.label);
  rating = rs.rating;

  return *this;
}
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
  os << "Label: " << rs.label << std::endl;
  os << "Rating: " << rs.rating << std::endl;
  return os;
}
// lacksDMA


lacksDMA::lacksDMA(const char * c, const char * l,
		   int r):
  baseDMA(l, r)
{
  strncpy(color, c, COL_LEN);
}
lacksDMA::lacksDMA(const char * c, const baseDMA & rs):
  baseDMA(rs)
{
  strncpy(color, c, COL_LEN);
}
lacksDMA::~lacksDMA()
{

}
void lacksDMA::view()
{
  printf("lacksDMA view()\n");
  baseDMA::view();
  printf("color:%s\n", color);
}
std::ostream & operator<<(std::ostream & os,
				 const lacksDMA & rs)
{
  os << (const baseDMA &) rs;
  os << "Color: " << rs.color << std::endl;
  return os;
}

hasDMA::hasDMA(const char * s, const char * c, const char * l,int r):
  lacksDMA(c, l, r)
{
  style = new char[strlen(s)+1];
  std::strcpy(style, s);
}


// hasDMA
hasDMA::hasDMA(const char * s, const lacksDMA & rs):
  lacksDMA(rs)
{
  style = new char[strlen(s)+1];
  std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs):
lacksDMA(hs)
{
  style = new char[strlen(hs.style)+1];
  std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
  delete [] style;
}
void hasDMA::view()
{
  printf("hasDMA view()\n");
  lacksDMA::view();
  printf("style: %s\n", style);
}
hasDMA & hasDMA::operator=(const hasDMA & rs)
{
  if(this == &rs) {
    return *this;
  }
  lacksDMA::operator=(rs);
  delete [] style;
  style = new char[strlen(rs.style)+1];
  std::strcpy(style, rs.style);

  return *this;
}
std::ostream & operator<<(std::ostream & os,
				 const hasDMA & rs)
{
  os << (const lacksDMA &) rs;
  os << "Style: " << rs.style << std::endl;
  return os;
}
