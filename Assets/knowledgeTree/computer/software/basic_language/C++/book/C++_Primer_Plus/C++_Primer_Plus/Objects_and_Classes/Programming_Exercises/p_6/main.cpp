#include "move.h"
int main()
{
  Move m1;
  m1.set_x(12.232);
  m1.set_y(12.321);
  m1.showmove();
  m1.reset(1.2, 43.432);
  m1.showmove();
  Move m2(312.312, 3213.321);
  m2.showmove();
  Move m3 = m1;
  m3.showmove();
  return 0;
}
