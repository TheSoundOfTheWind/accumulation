#include <iostream>
#include <string>

int main() {
  using std::cout;
  using std::string;
  using std::endl;

  struct CandyBar {
    string brand_name;
    double weight;
    int num_of_calories;
  };
  CandyBar snack = {"Mocha Munch",2.3,350};

  cout << "CandyBar brand name " << snack.brand_name << endl;
  cout << "CandyBar weight " << snack.weight << endl;
  cout << "CandyBar num of calories " << snack.num_of_calories << endl;
  
  return 0;
}
