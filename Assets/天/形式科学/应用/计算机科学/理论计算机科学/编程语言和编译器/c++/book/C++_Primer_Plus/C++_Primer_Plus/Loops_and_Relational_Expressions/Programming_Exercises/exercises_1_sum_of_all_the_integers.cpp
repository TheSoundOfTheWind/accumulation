#include <iostream>
int main()
{
  using namespace std;
  cout << "enter two integers: ";
  int first_num = 0;
  int second_num = 0;
  int sum = 0;
  cin >> first_num >> second_num;
  if (first_num >= second_num)
    {
      for (int i = second_num; i <= first_num; ++i)
	{
	  sum += i;
	}
    }
  else
    {
      for (int i = first_num; i <= second_num; ++i)
	{
	  sum += i;
	}
    }
  cout << "sum= " << sum << endl;
  
  return 0;
}
      
