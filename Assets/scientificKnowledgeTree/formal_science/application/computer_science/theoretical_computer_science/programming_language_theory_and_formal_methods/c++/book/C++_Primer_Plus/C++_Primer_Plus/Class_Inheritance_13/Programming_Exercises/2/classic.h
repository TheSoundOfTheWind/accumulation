#include "cd.h"
class Classic : public Cd
{
 private:
  std::string work;

 public:
  Classic();
  Classic(const std::string & w, const std::string & s1, const std::string & s2, int n, double x);
  virtual ~Classic();
  // other methods
  Classic & operator=(const Classic & c);
  virtual void Report() const;
};
