#include <iostream>
const int months =12;
int main()
{
  using namespace std;

  const string  month[months] =
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
  int sales[months];

  for (int i = 0; i < months; ++i)
    {
      cout  << "enter" << "\t" << month[i] << "\t" << "sales" << "\t";
      cin >> sales[i];
    }
  int total_sales = 0;
  for(int j = 0;j < months;++j)
    total_sales += sales[j];

  for(int i = 0;i < months; ++i)
      cout << month[i] << "\t";

  cout << "total sales" << endl;

  for(int i = 0;i < months; ++i)
    cout << sales[i] << "\t";

  cout << total_sales << endl;

  return 0;
}
