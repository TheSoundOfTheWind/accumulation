#include <iostream>
double light_to_astronomical(double light);
int main(void) {
  using std::cout;
  using std::cin;
  using std::endl;

  double light = 0;
  double astronomical = 0;
  
  cout << "Enter the number of light years: ";
  cin >> light;
  astronomical = light_to_astronomical(light);
  cout <<  light << " light years = " << astronomical << " astronomical units." << endl;
  return 0;
}

double light_to_astronomical(double light) {
  double astronomical = 0;

  astronomical = 63240 * light;

  return astronomical;
}
