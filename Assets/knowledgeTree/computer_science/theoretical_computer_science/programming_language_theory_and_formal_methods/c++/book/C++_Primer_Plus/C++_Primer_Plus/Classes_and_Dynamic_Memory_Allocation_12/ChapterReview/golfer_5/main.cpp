#include <stdio.h>
#include "golfer.h"
int main()
{
  Golfer nancy;
  Golfer lulu("Little Lulu");
  Golfer roy("Roy Hobbs", 12);
  Golfer * par = new Golfer;
  Golfer next = lulu;
  Golfer hazzard = "Weed Thwacker";
  *par = nancy;
  nancy = "Nancy Putter";

  return 0;
}
