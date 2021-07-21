#include <iostream>
#include <string>
#include <cstring>
int main()
{
  using namespace std;
  struct Car
  {
    string make;
    int year;
  };

  cout << "How many cars do you wish to catalog? ";
  int cars = 0;
  cin >> cars;
  Car * car = new Car[cars];
  for(int i = 0; i < cars; ++i)
    {
      cout << "Car #" << i+1 << ":" << endl;
      cout << "Please enter the make: ";
      cin.get();
      getline(cin,car[i].make);
      cout << "Please enter the year made: ";
      cin >> car[i].year;
    }

  cout << "Here is your collection:" << endl;
  for (int i = 0; i < cars; ++i)
    {
      cout << car[i].year << " " << car[i].make << endl;
    }

  delete [] car;
  return 0;
}
