#include <iostream>
int main() {
  using namespace std;
  const int ft_to_in = 12;
  const double in_to_m = 0.0254;
  const double kg_to_lb = 2.2;

  double feet;
  double inches;
  double pounds;

  cout << "Enter your height in feet:_\b";
  cin >> feet;
  cout <<"in inches:__\b\b";
  cin >> inches;
  cout << "Enter your weight:";
  cin >> pounds;

  double height = ((feet*ft_to_in)+inches)*in_to_m;
  double weight = pounds/kg_to_lb;

  cout << "Your BMI is ";
  cout << weight/(height*height) << endl;
  
  return 0;
}
