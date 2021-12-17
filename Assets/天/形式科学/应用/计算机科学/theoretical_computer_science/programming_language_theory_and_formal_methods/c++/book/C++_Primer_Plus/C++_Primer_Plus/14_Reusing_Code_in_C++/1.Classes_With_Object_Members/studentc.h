// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H
#define STUDENTC_H
#include <iostream>
#include <string>
#include <valarray>

class Student
{
 private:
  typedef std::valarray<double> ArrayDb;
  std::string name;    // contained object
  ArrayDb scores;      // contained object


 public:
  Student();
  explicit Student(int n);
  explicit Student(const std::string & s);
  Student(const std::string & s, int n);
  Student(const std::string & s, const ArrayDb & a);
  Student(const char * str, const double  * pd, int n);
  ~Student() {}

  // get methods
  // -----------------------------------------------------------------------
 private:
  std::ostream & arr_out(std::ostream & os) const;
 public:
  double Average() const;
  const std::string & Name() const;
  double & operator[](int i);
  double operator[] (int i) const;
  // friends
  friend std::istream & operator>>(std::istream & is, Student & stu);
  friend std::istream & getline(std::istream & is, Student & stu);
  friend std::ostream & operator<<(std::ostream & os, const Student & stu);
  // -------------------------------------------------------------------------
};
#endif // STUDENTC_H
