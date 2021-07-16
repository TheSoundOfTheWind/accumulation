#include <iostream>

class nifty
{
 private:
  // data
  char * personality;
  int talents;
 public:
  // methods
  nifty();
  nifty(char * s);
  friend std::ostream & operator<<(std::ostream & os, const nifty & n);
};
