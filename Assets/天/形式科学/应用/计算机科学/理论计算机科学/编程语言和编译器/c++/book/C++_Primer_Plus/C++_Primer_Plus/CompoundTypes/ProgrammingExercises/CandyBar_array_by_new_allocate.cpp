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

  CandyBar * snack = new CandyBar[3];
  (*snack) = {"jin",23,1};
  (*(snack+1)) = {"hai",43,2};
  (*(snack+2)) = {"lin",54,54};
  for(int i = 0; i< 3; i++) {
    cout << "CandyBar " << i+1 << endl;
    cout << "CandyBar brand name " << snack[i].brand_name << endl;
    cout << "CandyBar weight " << snack[i].weight << endl;
    cout << "CandyBar number of calories " << snack[i].num_of_calories << endl;
  }
  delete [] snack;
  return 0;
}
