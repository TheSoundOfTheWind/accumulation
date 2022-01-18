#include <iostream>

double converts(double furlongs);

int main() {
  using namespace std;

  double furlongs;

  cout << "furlongs: ";
  cin >> furlongs;
  cout << "yards: " << converts(furlongs) << endl;
  
  return 0;
}

double converts(double furlongs) {
  double fur = furlongs;
  return fur/220;
}
