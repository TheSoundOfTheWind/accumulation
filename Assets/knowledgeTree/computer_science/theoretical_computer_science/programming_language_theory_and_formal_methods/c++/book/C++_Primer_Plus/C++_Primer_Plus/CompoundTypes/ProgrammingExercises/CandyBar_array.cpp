#include <iostream>
#include <string>
int main() {
  using std::cout;
  using std::cin;
  using std::endl;
  using std::string;

  struct CandyBar {
    string brand_name;
    double weight;
    int num_of_calories;
  };

  CandyBar snack[3] = {{"Mocha Munch",2.3,350},{"jin",4.3,300},{"hailin",5.1,250}};
  for(int i = 0; i< 3; i++) {
    cout << "CandyBar " << i+1 << endl;
    cout << "CandyBar brand name " << snack[i].brand_name << endl;
    cout << "CandyBar weight " << snack[i].weight << endl;
    cout << "CandyBar number of calories " << snack[i].num_of_calories << endl;
  }
  
  return 0;
}
