#include <cstring>
#include <cstdio>
#include "classic.h"
Classic::Classic():
  Cd(),
  work("")
{

}
Classic::Classic(const std::string & w, const std::string & s1, const std::string & s2, int n, double x):
  Cd(s1, s2, n, x),
  work(w)
{
}
Classic::~Classic()
{
  work = "";
}
Classic & Classic::operator=(const Classic & c)
{
  if (this == &c) {
    return *this;
  }
  Cd::operator=(c);
  work = c.work;

  return *this;
}
void Classic::Report() const
{
  Cd::Report();
  printf("primary work: %s\n", work.c_str());
}
