// studentc.cpp -- Student class using containment
#include "studentc.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// ----------------------------------------------------------------------------------------------------------
Student::Student() :
  name("Null Student"),
  scores()
{

}
// ----------------------------------------------------------------------------------------------------------
Student::Student(const std::string & s):
  name(s),
  scores()
{

}
// ----------------------------------------------------------------------------------------------------------
Student::Student(int n) :
  name("Nully"),
  scores(n)
{

}
// ----------------------------------------------------------------------------------------------------------
Student::Student(const std::string & s, int n):
  name(s),
  scores(n)
{

}
// ----------------------------------------------------------------------------------------------------------
Student::Student(const std::string & s, const ArrayDb & a):
  name(s),
  scores(a)
{

}
// ----------------------------------------------------------------------------------------------------------
Student::Student(const char * str, const double  * pd, int n):
    name(str),
    scores(pd, n)
{

}
// get methods
// ----------------------------------------------------------------------------------------------------------
double Student::Average() const
{
  if (scores.size() > 0)
    return scores.sum()/scores.size();
  else
    return 0;
}
// ----------------------------------------------------------------------------------------------------------
const string & Student::Name() const
{
  return name;
}
// ----------------------------------------------------------------------------------------------------------
double & Student::operator[] (int i)
{
  return scores[i];       // use valarray<double>::operator[]()
}
// ----------------------------------------------------------------------------------------------------------
double Student::operator[](int i) const
{
  return scores[i];
}
// ----------------------------------------------------------------------------------------------------------
ostream & Student::arr_out(ostream & os) const
{
  int i;
  int lim = scores.size();
  if (lim > 0) {
    for (i = 0; i < lim; i++) {
      os << scores[i] << " ";
      if (i % 5 == 4)
	os << endl;
    }
    if (i % 5 != 0)
      os << endl;
  }
  else
    os << "empty array ";
  return os;
}
// ----------------------------------------------------------------------------------------------------------
istream & operator>>(istream & is, Student & stu)
{
  is >> stu.name;
  return is;
}
// ----------------------------------------------------------------------------------------------------------
istream & getline(istream & is, Student & stu)
{
  getline(is, stu.name);
  return is;
}
// ----------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & os, const Student & stu)
{
  os << "Scores for " << stu.name << ":\n";
  stu.arr_out(os);   // use private for scores
  return os;
}
// ----------------------------------------------------------------------------------------------------------
