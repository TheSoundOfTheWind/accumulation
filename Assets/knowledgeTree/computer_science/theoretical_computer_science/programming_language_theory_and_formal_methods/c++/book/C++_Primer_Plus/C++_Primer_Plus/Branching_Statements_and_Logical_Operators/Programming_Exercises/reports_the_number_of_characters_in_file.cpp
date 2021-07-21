#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
int main()
{
  using namespace std;
  char file_name[50]={0};
  cout << "Enter name of data file: ";
  cin.getline(file_name,50);
  fstream file;
  file.open(file_name);
  if(!file.is_open())
    {
      cout << "Could not open the file " << file_name << endl;
      cout << "Program terminating.\n";
      exit(EXIT_FAILURE);
    }
  int sum = 0;
  char ch;
  while(file >> ch)
    ++sum;
  if(sum == 0)
    {
      cout << "Now data processed.\n" << endl;
    }
  cout << "Number of characters is" << sum << endl;
  return 0;
}
