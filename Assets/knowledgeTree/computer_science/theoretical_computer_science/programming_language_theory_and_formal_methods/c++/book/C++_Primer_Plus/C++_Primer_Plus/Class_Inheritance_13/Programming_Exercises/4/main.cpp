#include "vintagePort.h"
int main()
{
  Port * port = new Port("hai", "a", 21);
  Port port2 = (*port);
  port2 += 4;
  port2 -= 2;
  port2.Show();

  Port * port3 = new VintagePort("lin", 232, "jjj", 12);
  (*port3) += 100;
  port3->Show();

  return 0;
}
