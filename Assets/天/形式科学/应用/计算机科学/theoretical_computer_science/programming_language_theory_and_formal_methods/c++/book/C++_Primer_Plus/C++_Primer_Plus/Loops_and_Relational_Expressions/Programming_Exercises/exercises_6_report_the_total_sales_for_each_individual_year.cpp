#include <iostream>
const int years = 3;
const int months = 12;
int main()
{
  using namespace std;
  
  const string months_array[months] =
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
  double sales[years][months];
  // enter data to two-dimensional array
  for (int i = 0; i < years; ++i)
    {
      cout << "\t\tenter " << i+1 << " years data" << endl;
      for (int j = 0; j < months; ++j)
	{
	  cin >> sales[i][j];
	}
    }

  // format
  cout << "years\t";
  for(int i = 0; i < months; ++i)
    cout << months_array[i] << "\t";
  cout << "total sales" << "\t" << "total year sales" << endl;

  // display data
  double sum[years]={0};
  for(int i = 0; i < years; ++i)
    {
      cout << i+1 << "\t";
      for (int j = 0; j < months; ++j)
	{
	  cout << sales[i][j] << "\t";
	  sum[i] += sales[i][j];
	}
      cout << sum[i] << endl;
    }
  
  double sum_year_sales = 0;
  for(int i = 0; i < years; ++i)
    {
      sum_year_sales += sum[i];
    }
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << sum_year_sales << endl;
  
  return 0;
}
