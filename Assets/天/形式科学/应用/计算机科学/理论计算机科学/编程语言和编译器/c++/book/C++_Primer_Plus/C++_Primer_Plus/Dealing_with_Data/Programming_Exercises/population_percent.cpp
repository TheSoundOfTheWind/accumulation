#include <iostream>
int main() {
  using namespace std;
  long long world_population;
  long long China_population;

  cout << "Enter the world's population: ";
  cin >> world_population;
  cout << "Enter the population of the China: ";
  cin >> China_population;
  cout << "The population of the China is " << double(China_population)/double(world_population)*100 << "% of the world population." << endl;
  
}
