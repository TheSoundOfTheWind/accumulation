#include <iostream>
#include <string>
int main() {
  using std::cout;
  using std::cin;
  using std::endl;
  using std::string;
  string first_name;
  string last_name;
  string third_string;

  cout << "Enter your first name: ";
  cin >> first_name;
  cout << "Enter your last name: ";
  cin >> last_name;

  third_string = last_name + ", " + first_name;

  cout << "Here's the information in a single string: ";
  cout << third_string << endl;
  
  return 0;
}
