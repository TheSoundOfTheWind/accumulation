#include <iostream>
#include <string>
#include "abc.h"

const int CLIENTS = 4;

int main()
{
  using std::cin;
  using std::cout;
  using std::endl;

  Abc *p_clients[CLIENTS];
  std::string temp;

  int kind = 0;
  std::string label;
  int rate;
  std::string color;
  std::string style;
  for (int i = 0; i < CLIENTS; ++i) {
    std::cout << "kind:";
    std::cin >> kind;
    if (1 == kind) {
      std::cout << "label:";
      std::cin >> label;
      std::cout << "rating:";
      std::cin >> rate;
      p_clients[i] = new baseDMA(label.c_str(), rate);
    }
    if (2 == kind) {
      std::cout << "label:";
      std::cin >> label;
      std::cout << "rating:";
      std::cin >> rate;
      std::cout << "color:";
      std::cin >> color;
      p_clients[i] = new lacksDMA(color.c_str(), label.c_str(), rate);
    }
    if (3 == kind) {
      std::cout << "label:";
      std::cin >> label;
      std::cout << "rating:";
      std::cin >> rate;
      std::cout << "color:";
      std::cin >> color;
      std::cout << "style:";
      std::cin >> style;
      p_clients[i] = new hasDMA(style.c_str(), color.c_str(), label.c_str(), rate);
    }
  }

  for (int i = 0; i < CLIENTS; ++i) {
    p_clients[i]->view();
    delete p_clients[i];
  }
  
  return 0;
}
