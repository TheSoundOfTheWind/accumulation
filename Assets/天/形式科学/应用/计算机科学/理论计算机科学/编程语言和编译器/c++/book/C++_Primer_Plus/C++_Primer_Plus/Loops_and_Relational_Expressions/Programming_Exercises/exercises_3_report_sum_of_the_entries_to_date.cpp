#include <iostream>
int main()
{
  using namespace std;
  
  double num = 0;
  double sum = 0;
  cout << "enter a numbers: ";
  cin >> num;
  while(num != 0)
    {
      sum += num;
      cout << "sum= " << sum << endl;
      cout << "enter a numbers: ";
      cin >> num;
    }
  cout << "Done!" << endl;
  
  return 0;
}
