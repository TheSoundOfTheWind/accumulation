#include <iostream>
#include "person.h"
int main()
{
  using namespace std;
  Person one;
  Person two("Smythecraft");
  Person three("Dimwiddy", "Sam");

  one.Show();
  one.FormalShow();
  cout << endl;

  two.Show();
  two.FormalShow();
  cout << endl;

  three.Show();
  three.FormalShow();
}
