#include "person.h"
Person::Person(const std::string & ln, const char * fn)
{
  lname = ln;
  strcpy(fname, fn);
}
void Person::Show() const
{
  if(0 == strlen(fname) && true == lname.empty())
    std::cout << "fname and lname is empty\n";
  else if (0 == strlen(fname) && false == lname.empty())
    std::cout << "fname is empty\n";
  else if (strlen(fname) > 0 && true == lname.empty())
    std::cout << "lname is empty\n";
  else
    std::cout << fname << " " << lname << std::endl; 
}

void Person::FormalShow() const
{
  if(0 == strlen(fname) && true == lname.empty())
    std::cout << "fname and lname is empty\n";
  else if (0 == strlen(fname) && false == lname.empty())
    std::cout << "fname is empty\n";
  else if (strlen(fname) > 0 && true == lname.empty())
    std::cout << "lname is empty\n";
  else
    std::cout << lname << ", " << fname << std::endl;
}

