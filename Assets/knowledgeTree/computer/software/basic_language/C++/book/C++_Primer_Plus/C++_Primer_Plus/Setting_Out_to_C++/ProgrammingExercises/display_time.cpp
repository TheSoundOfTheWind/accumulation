#include <iostream>
void display_time(int hours, int minutes);
int main(void) {
  using std::cout;
  using std::cin;
  using std::endl;

  int hours = 0;
  int minutes = 0;

  cout << "Enter the number of hours: ";
  cin >> hours;
  cout << "Enter the number of minutes: ";
  cin >> minutes;

  display_time(hours, minutes);
  
  return 0;
}

void display_time(int hours, int minutes) {
  using std::cout;
  using std::endl;

  cout << "Time: " << hours << ":" << minutes << endl;
}
