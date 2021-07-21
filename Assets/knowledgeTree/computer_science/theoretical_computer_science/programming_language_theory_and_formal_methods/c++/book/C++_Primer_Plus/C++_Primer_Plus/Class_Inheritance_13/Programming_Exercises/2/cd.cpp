#include <cstdio>
#include "cd.h"
Cd::Cd(const std::string & s1, const std::string & s2, int n, double x):
  performers(s1),
  label(s2),
  selections(n),
  playtime(x)
{
}
Cd::Cd(const Cd & d):
  performers(d.performers),
  label(d.label),
  selections(d.selections),
  playtime(d.playtime)
{
}
Cd::Cd()
{
  performers = "";
  label = "";
  selections = 0;
  playtime = 0.0;
}
// other methods
void Cd::Report() const        // reports all CD data
{
  printf("performers: %s\n", performers.c_str());
  printf("label: %s\n", label.c_str());
  printf("selections: %d\n", selections);
  printf("playtime: %f\n", playtime);
}
Cd & Cd::operator=(const Cd & d)
{
  if (this == &d) {
    return *this;
  }
  performers = d.performers;
  label = d.label;
  selections = d.selections;
  playtime = d.playtime;

  return *this;
}
