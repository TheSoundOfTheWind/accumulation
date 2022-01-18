// arrobj.cpp -- functions with array objects
#include <iostream>
#include <array>
#include <string>
// constant data
const int Seasons = 4;
const char * Snames[Seasons] =
  {"Spring", "Summer", "Fall", "Winter"};
struct expenses_struct{
  double expenses[Seasons];
};
// function to modify array object
void fill(expenses_struct & pa);

// function that uses array object without modifying it
void show(const expenses_struct da);

int main()
{
  expenses_struct expenses;
  fill(expenses);
  show(expenses);
  return 0;
}

void fill(expenses_struct & pa)
{
  using namespace std;
  for(int i = 0; i < Seasons; i++)
    {
      cout << "Enter " << Snames[i] << " expenses: ";
      cin >> pa.expenses[i];
    }
}

void show(const expenses_struct da)
{
  using namespace std;
  double total = 0.0;
  cout << "\nEXPENSES\n";
  for(int i = 0; i < Seasons; i++)
    {
      cout << Snames[i] << ": $" << da.expenses[i] << endl;
      total += da.expenses[i];
    }
  cout << "Total Expression: $" << total << endl;
}
