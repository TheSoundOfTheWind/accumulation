#include <cstring>
#include <cctype>
#include "string2.h"


int String::num_strings = 0;

// constructors and others methods
String::String(const char * s)       // constructor
{
  len = strlen(s);
  str = new char[len+1];
  strcpy(str, s);
  str[len] = '\0';

  num_strings++;
}

String::String()                     // defalut constructor
{
  len = 0;
  str = new char[1];
  str[0] = '\0';

  num_strings++;
}

String::String(const String & s)       // copy constructor
{
  len = s.len;
  str = new char[len+1];
  strcpy(str, s.str);
  str[len] = '\0';

  num_strings++;
}

String::~String()                    // destructor
{
  --num_strings;
  len = 0;
  delete [] str;
}

// overloaded operator methods
String & String::operator=(const String & s)
{
  if (this == &s)
    return *this;
  len = s.len;
  delete [] str;
  str = new char[len+1];
  strcpy(str, s.str);
  str[len] = '\0';

  return *this;
}

String & String::operator=(const char * c)
{
  len = strlen(c);
  delete [] str;
  str = new char[len+1];
  strcpy(str, c);
  str[len] = '\0';

  return *this;
}

char & String::operator[](int i)
{
  if (i < 0 or i > len) {
    printf("error with [] operator\n");
    return str[len];
  }
  return str[i];
}

const char & String::operator[] (int i) const
{
  if (i < 0 or i > len) {
    printf("error with [] operator\n");
    return str[len];
  }
  return str[i];
}

String & String::operator+(const String & s)
{
  len = len + s.len;
  char * str_t = str;
  str = new char[len+1];
  strcat(str, str_t);
  delete [] str_t;
  strcat(str, s.str);
  str[len] = '\0';

  return *this;
}

String & String::operator+(const char * c)
{
  len = len + strlen(c);
  char * str_t = str;
  str = new char[len+1];
  strcat(str, str_t);
  delete [] str_t;
  strcat(str, c);
  str[len] = '\0';

  return *this;
}

String & operator+(const char * c, String & s)
{
  s.len = s.len + strlen(c);
  char * str_t = s.str;
  s.str = new char[s.len+1];
  strcat(s.str, c);
  strcat(s.str, str_t);
  delete [] str_t;
  s.str[s.len] = '\0';

  return s;
}

void String::stringlow()
{
  for (int i = 0; i < len; ++i) {
    str[i] = tolower(str[i]);
  }
}

void String::stringup()
{
  for (int i = 0; i < len; ++i) {
    str[i] = toupper(str[i]);
  }
}

int String::has(const char & c)
{
  int num = 0;
  for (int i = 0; i < len; ++i) {
    if (c == str[i]) {
      num++;
    }
  }

  return num;
}
  
// overloaded operator friends
bool operator<(const String & st, const String & st2)
{
  bool b_r = false;
  int len = st.len < st2.len ? st.len : st2.len;
  for (int i = 0; i < len; ++i) {
    if (st.str[i] < st2.str[i]) {
      b_r = true;
      break;
    }
  }

  return b_r;
}

bool operator>(const String & st, const String & st2)
{
  bool b_r = false;
  int len = st.len < st2.len ? st.len : st2.len;
  for (int i = 0; i < len; ++i) {
    if (st.str[i] > st2.str[i]) {
      b_r = true;
      break;
    }
  }

  return b_r;
}

bool operator==(const String & st, const String & st2)
{
  bool b_r = true;
  do {
    if (st.len != st2.len) {
      b_r = false;
      break;
    }

    for (int i = 0; i < st.len; ++i) {
      if (st.str[i] != st2.str[i]) {
	b_r = false;
	break;
      }
    }
  }while(0);

  return b_r;
}

ostream & operator<<(ostream & os, const String & st)
{
  os << st.str;
  return os;
}

istream & operator>>(istream & is, String & st)
{
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is)
    st = temp;
  while (is && is.get() != '\n')
    continue;

  return is;
}

// Static function
int String::HowMany()
{
  return num_strings;
}
