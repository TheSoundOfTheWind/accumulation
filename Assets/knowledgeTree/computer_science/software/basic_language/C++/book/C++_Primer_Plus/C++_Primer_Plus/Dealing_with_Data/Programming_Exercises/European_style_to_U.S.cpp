#include <iostream>
int main() {
  using namespace std;
  const double KM_TO_MILES = 62.14;
  const double GALLON_TO_LITERS = 3.875;

  double European_style;
  double gallon;
  double miles;
  cout << "Enter European oil consumption style in L/km: ";
  cin >> European_style;
  gallon = European_style/GALLON_TO_LITERS;
  miles = 62.14;
  cout << "U.S oil consumption style is ";
  cout << miles/gallon << " mpg" << endl;
  
  return 0;
}
	
