#include <cstring>
#include <cstdio>
#include "classic.h"
Classic::Classic():
  Cd()
{
  memset(work, '\0', sizeof(work));
}
Classic::Classic(const char * w, const char * s1, const char * s2, int n, double x):
  Cd(s1, s2, n, x)
{
  memset(work, '\0', sizeof(work));
  strncpy(work, w, sizeof(work));
}
Classic::~Classic()
{
  memset(work, '\0', sizeof(work));
}
Classic & Classic::operator=(const Classic & c)
{
  if (this == &c) {
    return *this;
  }
  Cd::operator=(c);
  memset(work, '\0', sizeof(work));
  strncpy(work, c.work, sizeof(work));

  return *this;
}
void Classic::Report() const
{
  Cd::Report();
  printf("primary work: %s\n", work);
}
