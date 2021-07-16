// strngbad_2.cpp -- StringBad class methods
#include <cstring>             // string.h for some
#include "strngbad_1.h"
using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char * s)
{
  len = std::strlen(s);    // set size
  str = new char[len+1];   // allot storage
  std::strcpy(str, s);     // initialize pointer
  num_strings++;
  cout << num_strings << ": \"" << str
       << "\" char * s object created\n";   // FYI
}
StringBad::StringBad()     // default constructor
{
  len = 4;
  str = new char[4];
  num_strings++;
  cout << num_strings << ": \"" << str
       << "\" default object created\n";   // FYI
}

StringBad::~StringBad()     // necessary destructor
{
  cout << "\"" << str << "\" object deleted, ";   // FYI
  --num_strings;            // required
  cout << num_strings << " left\n"; // FYI
  delete [] str;            // required
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
  os << st.str;
  return os;
}
