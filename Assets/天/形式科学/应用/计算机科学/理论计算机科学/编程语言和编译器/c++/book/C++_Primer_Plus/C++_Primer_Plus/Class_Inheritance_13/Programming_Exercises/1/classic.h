#include "cd.h"
class Classic : public Cd
{
 private:
  char work[1024];

 public:
  Classic();
  Classic(const char * w, const char * s1, const char * s2, int n, double x);
  virtual ~Classic();
  // other methods
  Classic & operator=(const Classic & c);
  virtual void Report() const;
};
