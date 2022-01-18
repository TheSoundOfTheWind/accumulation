#include <cstdlib>
#include <string>
#include <cstring>
// base class
class Cd { // represents a CD disk
 private:
  std::string performers;
  std::string label;
  int selections;             // number of selections
  double playtime;            // playing time in minutes

 public:
  Cd(const std::string & s1, const std::string & s2, int n, double x);
  Cd(const Cd & d);
  Cd();
  virtual ~Cd() {
    performers = "";
    label = "";
    selections = 0;
    playtime = 0.0;
  };
  virtual void Report() const;        // reports all CD data
  Cd & operator=(const Cd & d);
};


