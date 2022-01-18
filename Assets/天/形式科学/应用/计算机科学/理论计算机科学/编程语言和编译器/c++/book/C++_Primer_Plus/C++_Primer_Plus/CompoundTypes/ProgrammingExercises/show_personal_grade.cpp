#include <iostream>
#include <string>
int main() {
  using namespace std;
  struct personal_grade {
    string first_name;
    string last_name;
    char grade;
    int age;
  };
  personal_grade one;
  cout << "What is your first name? ";
  getline(cin,one.first_name);
  cout << "What is your last name? ";
  getline(cin,one.last_name);
  cout << "What letter grade do you deserve? ";
  cin >> one.grade;
  cout << "What is your age? ";
  cin >> one.age;

  cout << "Name: " << one.last_name << ", " << one.first_name << endl;
  cout << "Grade: " << (char)(one.grade+1) << endl;
  cout << "Age: " << one.age << endl;
  
  return 0;
 }
