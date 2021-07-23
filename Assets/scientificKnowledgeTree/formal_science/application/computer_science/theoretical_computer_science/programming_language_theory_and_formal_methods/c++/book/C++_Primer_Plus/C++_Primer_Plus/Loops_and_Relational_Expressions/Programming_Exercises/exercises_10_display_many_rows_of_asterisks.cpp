#include <iostream>

int main()
{
  using namespace std;

  int rows = 0;

  cout << "Enter number of rows: ";
  cin >> rows;

  for(int i = 1; i <= rows; ++i)
    {
      for(int k = 0; k < (rows -i); ++k)
	cout << ". ";
      for(int j = 0; j < i; ++j)
	cout << "* ";
      cout << endl;
    }

  return 0;
}
