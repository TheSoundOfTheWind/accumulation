#include <cstdio>
#include "cd.h"
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
  memset(performers, '\0', sizeof performers);
  memset(label, '\0', sizeof(performers));
  strncpy(performers, s1, 50);
  strncpy(label, s2, 20);
  selections = n;
  playtime = x;
}
Cd::Cd(const Cd & d)
{
  strncpy(performers, d.performers, 50);
  strncpy(label, d.label, 20);
  selections = d.selections;
  playtime = d.playtime;
}
Cd::Cd()
{
  memset(performers, '\0', sizeof(performers));
  memset(label, '\0', sizeof(label));
  selections = 0;
  playtime = 0.0;
}
// other methods
void Cd::Report() const        // reports all CD data
{
  printf("performers: %s\n", performers);
  printf("label: %s\n", label);
  printf("selections: %d\n", selections);
  printf("playtime: %f\n", playtime);
}
Cd & Cd::operator=(const Cd & d)
{
  if (this == &d) {
    return *this;
  }
  memset(performers, '\0', sizeof(performers));
  memset(label, '\0', sizeof(label));
  strncpy(performers, d.performers, 50);
  strncpy(label, d.label, 20);
  selections = d.selections;
  playtime = d.playtime;

  return *this;
}
