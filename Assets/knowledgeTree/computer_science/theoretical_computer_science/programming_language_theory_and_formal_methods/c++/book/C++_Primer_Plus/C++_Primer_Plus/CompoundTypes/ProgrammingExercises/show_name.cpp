#include <iostream>
#include <cstring>

int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  char first_name[100];
  char last_name[100];
  char third_string[200];
  memset(first_name,0,sizeof(first_name));
  memset(last_name,0,sizeof(last_name));
  memset(third_string,0,sizeof(third_string));
  
  cout << "Enter your first name: ";
  cin >> first_name;
  cout << "Enter your last name: ";
  cin >> last_name;
  strcat(third_string,last_name);
  strcat(third_string,", ");
  strcat(third_string,first_name);

  cout << "Here's the information in a single string: " << third_string << endl;
  
  return 0;
}
