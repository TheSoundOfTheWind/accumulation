#include <iostream>
double celsius_to_fahrenheit(double celsius);

int main(void) {
  using std::cout;
  using std::cin;
  using std::endl;
  double celsius = 0;
  double fahrenheit = 0;

  cout << "Please enter a Celsius value: ";
  cin >> celsius;
  fahrenheit = celsius_to_fahrenheit(celsius);
  cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit" << endl;
  
  return 0;
}

double celsius_to_fahrenheit(double celsius) {
  double fahrenheit = 0;
  fahrenheit = 1.8 * celsius + 32.0;

  return fahrenheit;
}
