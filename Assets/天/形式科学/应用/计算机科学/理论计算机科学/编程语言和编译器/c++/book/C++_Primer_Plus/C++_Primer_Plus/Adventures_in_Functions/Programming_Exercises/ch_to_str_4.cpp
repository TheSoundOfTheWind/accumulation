#include <iostream>
using namespace std;
#include <cstring>    // for strlen(), strcpy()
struct stringy {
  char * str;         // points to a string
  int ct;             // length of string (no counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy & stry,const char *);
void show(const char * str, unsigned int n = 1);
void show(const stringy & str, unsigned int n = 1);
int main()
{
  stringy beany = {0};
  char testing[] = "Reality isn't what it used to be.";
  set(beany, testing); // first argument iss
  show(beany);
  show(beany, 2);
  testing[0] = 'D';
  testing[1] = 'u';
  show(testing);
  show(testing, 3);
  show("Done!");
  
  return 0;
}

void set(stringy & stry,const char * str)
{
  static int a = 0;
  unsigned int len = std::strlen(str);
  if(a == 1 and std::strlen(stry.str) > 0)
    delete [] stry.str;
  stry.str = new char[len+1];
  std::strcpy(stry.str, str);
  stry.ct = len;
  a=1;
}

void show(const char * str, unsigned int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << str << std::endl;
}

void show(const stringy & str, unsigned int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << str.str << std::endl;
}
