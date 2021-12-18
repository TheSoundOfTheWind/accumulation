#include <iostream>
#include <cstring>
int main()
{
  using namespace std;

  char key[] = "done";
  char word[100];
  cout << "Enter words (to stop, type the word done): ";
  int num = -1;

  do
    {
      cin >> word;
      ++num;
    }
  while(strcmp(key,word) != 0);

  cout << "You entered a total of " << num << " words." << endl;
  
  return 0;
}
