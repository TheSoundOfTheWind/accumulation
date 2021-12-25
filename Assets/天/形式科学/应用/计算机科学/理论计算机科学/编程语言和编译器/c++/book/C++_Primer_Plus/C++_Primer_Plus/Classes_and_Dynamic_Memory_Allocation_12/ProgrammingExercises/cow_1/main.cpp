#include "cow.h"

int main()
{
  Cow c1;
  c1.ShowCow();
  Cow c2("Tom", "reading", 56.8);
  c2.ShowCow();
  Cow c3(c2);
  c3.ShowCow();
  c1 = c3;
  c1.ShowCow();
  Cow c4 = c2;
  c4.ShowCow();
  return 0;
}
