#include "port.h"
class VintagePort : public Port // style necessarily = "vintage"
{
 private:
  char * nickname;
  int year;
 public:
  // set methods
  // ------------------------------------------------------------------------
  VintagePort();
  VintagePort(const char * br, int b, const char * nn, int y);
  VintagePort(const VintagePort & vp);
  ~VintagePort() { delete [] nickname;}
  VintagePort & operator=(const VintagePort & vp);
  // ------------------------------------------------------------------------

  // get methods
  // ------------------------------------------------------------------------
  void Show() const;
  friend ostream & operator<<(ostream & os, const VintagePort & vp);
  // ------------------------------------------------------------------------
};
