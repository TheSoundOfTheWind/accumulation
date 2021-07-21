#include <iostream>
#include <cctype>
#include <array>
int main()
{
  using namespace std;
  double myarray[10]={0};

  for (int i = 0; i < 10; ++i)
    {
      cout << "number #" << i+1 << ": ";
      while (!(cin >> myarray[i]))
	{
	  cin.clear();
	  while(cin.get() != '\n')
	    continue;
	  cout << "Please enter a number: ";
	}
    }
  double sum = 0;
  for (auto it = myarray.begin(); it != myarray.end(); ++it)
    {
      sum += *it;
    }
  double average = sum / myarray.size();
  cout << "The average of the number is " << average << endl;
  int numbers = 0;
  for (auto it = myarray.begin(); it != myarray.end(); ++it)
    {
      if((*it) > average)
	numbers++;
    }
  cout << "Have " << numbers << " numbers larger than the average" << endl;
  
  return 0;
}
