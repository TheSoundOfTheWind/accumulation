#include <iostream>
void display1();
void display2();
int main(void) {
  display1();
  display1();
  display2();
  display2();
  return 0;
}

void display1() {
  using std::cout;
  using std::endl;
  cout << "Three bind mice" << endl;
}

void display2() {
  using std::cout;
  using std::endl;
  cout << "show how they run" << endl;
}
