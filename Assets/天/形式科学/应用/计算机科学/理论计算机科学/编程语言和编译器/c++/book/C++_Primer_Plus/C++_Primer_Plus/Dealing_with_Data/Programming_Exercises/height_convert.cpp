#include <iostream>
int main() {
  using std::cout;
  using std::endl;
  using std::cin;
  const int ft_to_in = 12;
  unsigned int height;
  cout << "Enter your height in inches:__\b\b";
  cin >> height;
  cout << "Your height is " << height/ft_to_in << " feet " <<
    height%ft_to_in << " inches" << endl;
  
  return 0;
}
