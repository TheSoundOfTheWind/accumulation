#include"golf.h"
int main()
{
  golf g;
  g.show();
  golf h("jinhailin", 4);
  h.show();
  golf k(h);
  k.show();
  return 0;
}
