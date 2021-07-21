// string1_4.h -- fix and augmented string class definition
#ifndef STRING2_H
#define STRING2_H
#include <iostream>
using std::ostream;
using std::istream;

class String
{
 private:
  char * str;             // pointer to string
  int len;                // len of string
  static int num_strings; // number of object
  static const int CINLIM = 80; // cin input limit
 public:
  // constructors and others methods
  String(const char * s);       // constructor
  String();                     // defalut constructor
  String(const String &);       // copy constructor
  ~String();                    // destructor
  int length() const {return len;}
  // overloaded operator methods
  String & operator=(const String &);
  String & operator=(const char *);
  char & operator[](int i);
  const char & operator[] (int i) const;

  String & operator+(const String &);
  String & operator+(const char *);
  void stringlow();
  void stringup();
  int  has(const char &);
  
  // overloaded operator friends
  friend String & operator+(const char *, String &);
  friend bool operator<(const String & st, const String & st2);
  friend bool operator>(const String & st, const String & st2);
  friend bool operator==(const String & st, const String & st2);
  friend ostream & operator<<(ostream & os, const String & st);
  friend istream & operator>>(istream & is, String & st);
  // Static function
  static int HowMany();
};

#endif // STRING2_H
