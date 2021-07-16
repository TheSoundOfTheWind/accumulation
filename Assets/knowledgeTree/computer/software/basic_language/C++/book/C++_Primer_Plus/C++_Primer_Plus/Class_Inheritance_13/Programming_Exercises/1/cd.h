#include <cstdlib>
#include <cstring>
// base class
class Cd { // represents a CD disk
 private:
  char performers[50];
  char label[20];
  int selections;             // number of selections
  double playtime;            // playing time in minutes
 public:
  Cd(const char * s1, const char * s2, int n, double x);
  Cd(const Cd & d);
  Cd();
  virtual ~Cd() {
    memset(performers, 0, sizeof(performers));
    memset(label, 0, sizeof(label));
    selections = 0;
    playtime = 0.0;
  };
  virtual void Report() const;        // reports all CD data
  Cd & operator=(const Cd & d);
};


