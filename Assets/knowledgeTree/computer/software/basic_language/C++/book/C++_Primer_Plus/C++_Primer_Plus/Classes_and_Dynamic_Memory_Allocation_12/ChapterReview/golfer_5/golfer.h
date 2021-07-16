class Golfer
{
 private:
  char * fullname; // points to string containing golfer's name
  int games;       // holds number of golf games played
  int * scores;    // points to first element of array of golf scores

 public:
  Golfer();
  Golfer(const char * name, int g = 0);
  Golfer & operator=(const Golfer &);
  // creates empty dynamic array of g elements if g > 0
  Golfer(const Golfer & g);
  ~Golfer();
};

