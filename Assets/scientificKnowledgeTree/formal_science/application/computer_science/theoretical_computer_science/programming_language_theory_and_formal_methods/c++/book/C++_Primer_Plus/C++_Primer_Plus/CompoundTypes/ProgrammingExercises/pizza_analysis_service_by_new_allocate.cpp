#include <iostream>
#include <string>
int main() {
  using std::cout;
  using std::cin;
  using std::endl;
  using std::string;
  struct Pizza {
    string name_of_pizza_company;
    double diameter_of_pizza;
    double weight_of_pizza;
  };
  Pizza * pizza = new Pizza;
  cout << "\tpizza-analysis service" << endl;
  cout << "The diameter of the pizza: ";
  cin >> pizza->diameter_of_pizza;
  cout << "The name of the pizza company: ";
  cin >> pizza->name_of_pizza_company;
  cout << "The weight of the pizza: ";
  cin >> pizza->weight_of_pizza;

  cout << "\tdisplay pizza information" << endl;
  cout << "The name of the pizza company is " << pizza->name_of_pizza_company << endl;
  cout << "The diameter of the pizza is " << pizza->diameter_of_pizza << endl;
  cout << "The weight of the pizza is " << pizza->weight_of_pizza << endl;
  
  return 0;
}
