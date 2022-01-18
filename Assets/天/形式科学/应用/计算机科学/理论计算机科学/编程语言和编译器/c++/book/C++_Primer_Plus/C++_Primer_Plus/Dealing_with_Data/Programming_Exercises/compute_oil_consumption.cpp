#include <iostream>
int main() {
  using namespace std;
  int kilometers;
  int liters;
  cout << "Enter your driven distance in kilometers: ";
  cin >> kilometers;
  cout << "Enter your oil consumption in liters: ";
  cin >> liters;
  cout << "your oil consumption is " << double(liters)/kilometers*100 << " liters per 100 kilometers" << endl;
  return 0;
}
