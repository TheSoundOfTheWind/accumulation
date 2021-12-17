#include <iostream>
#include <cstring>
int main()
{
  using namespace std;

  string key = "done";
  string word;
  cout << "Enter words (to stop, type the word done): " << endl;
  int num = -1;

  do
    {
      cin >> word;
      ++num;
    }
  while(word != key);

  cout << "You entered a total of " << num << " words." << endl;
  
  return 0;
}
