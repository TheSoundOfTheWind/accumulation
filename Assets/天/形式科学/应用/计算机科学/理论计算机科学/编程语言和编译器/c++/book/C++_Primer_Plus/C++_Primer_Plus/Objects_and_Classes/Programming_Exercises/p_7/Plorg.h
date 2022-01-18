#ifndef PLORG_H_
#define PLORG_H_
const short SIZE = 19;
class Plorg {
 private:
  char m_name[SIZE];
  int m_ci;
 public:
  Plorg();
  Plorg(const char * name, int ci);
  void set_ci(int ci);
  void report();
};
#endif
