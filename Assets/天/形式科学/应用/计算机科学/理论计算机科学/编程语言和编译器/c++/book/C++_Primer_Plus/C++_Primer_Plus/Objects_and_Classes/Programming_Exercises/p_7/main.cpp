#include "Plorg.h"
int main()
{
  Plorg p1;
  p1.report();
  Plorg p2("jinhailin", 1232);
  p2.report();
  p1.set_ci(312312);
  p1.report();
  return 0;
}
