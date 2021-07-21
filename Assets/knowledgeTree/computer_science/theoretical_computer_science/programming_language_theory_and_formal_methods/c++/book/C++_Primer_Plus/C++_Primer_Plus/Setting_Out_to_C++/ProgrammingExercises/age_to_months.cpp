#include <iostream>
int age_to_months(int age);
int main(void) {
  using std::cout;
  using std::endl;
  using std::cin;
  int age = 0;
  int months = 0;

  cout << "Enter your age: ";
  cin >> age;
  months = age_to_months(age);
  cout << "Your age in months is " << months << endl;
  
  return 0;
}

int age_to_months(int age) {
  int months = age*12;
  return months;
}
