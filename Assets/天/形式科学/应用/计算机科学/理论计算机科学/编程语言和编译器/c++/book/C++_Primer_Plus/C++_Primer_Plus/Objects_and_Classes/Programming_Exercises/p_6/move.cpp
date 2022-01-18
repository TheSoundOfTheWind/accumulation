#include "move.h"
#include <iostream>
Move::Move(double a, double b)
{
  x = a;
  y = b;
}

void Move::showmove() const
{
  std::cout << "x " << x << " y " << y << std::endl;
}

Move Move::add(const Move & m) const
{
  Move r_m;
  r_m.set_x(m.get_x());
  r_m.set_y(m.get_y());
  return r_m;
}

void Move::reset(double a, double b)
{
  x = a;
  y = b;
}

void Move::set_x(double x)
{
  this->x = x;
}

double Move::get_x() const
{
  return x;
}

void Move::set_y(double y)
{
  this->y = y;
}

double Move::get_y() const
{
  return y;
}
