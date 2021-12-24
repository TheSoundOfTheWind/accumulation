// vegnews_3.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad_1.h"

void callme1(StringBad &);     // pass by reference
void callme2(StringBad);       // pass by value

int main()
{
  using std::endl;
  {
    cout << "Starting an inner block.\n";
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");
    cout << endl;
    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    cout << endl;
    callme1(headline1);
    cout << endl;
    cout << "headline1: " << headline1 << endl;
    cout << endl;
    callme2(headline2);
    cout << endl;
    cout << "headline2: " << headline2 << endl;
    cout << endl;
    cout << "Initialize one object ot another:\n";
    StringBad sailor = sports;
    cout << "sailor: " << sailor << endl;
    cout << endl;
    cout << "Assign one object to another:\n";
    StringBad knot;
    cout << endl;
    knot = headline1;
    cout << endl;
    cout << "knot: " << knot << endl;
    cout << "Exiting the block.\n";
  }

  cout << "End of main()\n";
  
  return 0;
}

void callme1(StringBad & rsb)
{
  cout << "String passed by reference:\n";
  cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
  cout << "String passed by value:\n";
  cout << "   \"" << sb << "\"\n";
}
