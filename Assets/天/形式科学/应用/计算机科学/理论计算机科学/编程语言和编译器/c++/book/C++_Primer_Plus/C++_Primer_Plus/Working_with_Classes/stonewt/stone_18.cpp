// stone.cpp -- user-defined conversions
// compile with stonewt_18.cpp
#include <iostream>
#include "stonewt_16.h"
using std::cout;
void display(const Stonewt & st, int n);
int main()
{
  Stonewt incognito = 275;  // uses constructor to initialize
  Stonewt wolfe(285.7);     // same as Stonewt wolfe = 285.7
  Stonewt taft(21, 8);

  cout << "The celebrity weighed ";
  incognito.show_stn();
  cout << "The detective weighed ";
  wolfe.show_stn();
  cout << "The President weighed ";
  taft.show_lbs();
  incognito = 276.8;          // uses constructor for conversion
  taft = 325;                 // same as taft = Stonewt(325);
  cout << "After dinner, the celebrity weighted ";
  taft.show_lbs();
  display(taft, 2);
  cout << "The wrestler weighted even more.\n";
  display(422, 2);
  cout << "No stone left unearned\n";

  return 0;
}

void display(const Stonewt & st, int n)
{
  for (int i = 0; i < n; i++)
    {
      cout << "Wow! ";
      st.show_stn();
    }
}
