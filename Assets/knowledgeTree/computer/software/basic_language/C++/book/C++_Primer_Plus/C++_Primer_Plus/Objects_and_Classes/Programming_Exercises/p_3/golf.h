#ifndef GOLF_H_
#define GOLF_H_
const int Len = 40;
class golf {
 private:
  char fullname[Len];
  int handicap;
 public:
  golf(const char * name, int hc);
  golf();
  golf(const golf & g);
  void show();
};
#endif /* GOLF_H_ */
