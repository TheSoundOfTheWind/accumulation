// instr2_string -- reading more than one word with getline
#include <iostream>
#include <string>
int main() {
  using namespace std;
  string name;
  string dessert;

  cout << "Enter your name:\n";
  getline(cin,name);
  cout << "Enter your favorite dessert:\n";
  getline(cin,dessert);
  cout << "I have some delicious " << dessert;
  cout << " for you, " << name  << ".\n";

  return 0;
}
