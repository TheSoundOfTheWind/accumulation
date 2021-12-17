#include <iostream>
int main() {
  using namespace std;
  const int Degrees_to_minutes = 60;
  const int Minutes_to_second = 60;
  unsigned int degrees;
  unsigned int minutes;
  unsigned int seconds;
  double total;
  cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
  cout << "First, enter the degrees: ";
  cin >> degrees;
  cout << "Next, enter the minutes of arc: ";
  cin >> minutes;
  cout << "Finaly, enter the seconds of arc: ";
  cin >> seconds;
  total = degrees + (minutes/60.0) + (seconds/60.0/60.0);
  cout << degrees << " degrees, " << minutes << " minutes, "
       << seconds << " seconds = " << total << " degrees"
       << endl;
  return 0;
}
