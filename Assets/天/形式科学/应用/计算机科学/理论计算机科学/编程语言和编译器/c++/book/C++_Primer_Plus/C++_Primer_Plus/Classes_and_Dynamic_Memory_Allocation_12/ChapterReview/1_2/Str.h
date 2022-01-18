
class Str {
 public:
  Str();
  Str(const char * s);
  ~Str();

  //display
  const char * c_str();
 private:
  char * str;
  int len;
};
