// arrobj.cpp -- functions with array objects
#include <iostream>
#include <array>
#include <string>
// constant data
const int Seasons = 4;
const char * Snames[Seasons] =
  {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(double pa[Seasons]);

// function that uses array object without modifying it
void show(const double da[Seasons]);

int main()
{
  double expenses[Seasons];
  fill(expenses);
  show(expenses);
  return 0;
}

void fill(double pa[Seasons])
{
  using namespace std;
  for(int i = 0; i < Seasons; i++)
    {
      cout << "Enter " << Snames[i] << " expenses: ";
      cin >> pa[i];
    }
}

void show(const double da[Seasons])
{
  using namespace std;
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for(int i = 0; i < Seasons; i++)
    {
      cout << Snames[i] << ": $" << da[i] << endl;
      total += da[i];
    }
  cout << "Total Expression: $" << total << endl;
}
