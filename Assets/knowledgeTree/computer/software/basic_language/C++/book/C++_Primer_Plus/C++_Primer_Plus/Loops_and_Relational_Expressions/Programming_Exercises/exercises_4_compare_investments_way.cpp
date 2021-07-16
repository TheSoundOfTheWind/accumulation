#include <iostream>

const double BALANCE = 100;
int main()
{
  using namespace std;
  double d_invests = BALANCE;
  double c_invests = BALANCE;
  int i = 0;
  do
    {
      d_invests += BALANCE * 0.10;
      c_invests += c_invests * 0.05;
      ++i;
    }
  while(c_invests <= d_invests);

  cout << "Name" << '\t' << "years" << '\t' << "investments" << endl;
  cout << "Daphne" << '\t' << i << '\t' << d_invests << endl;
  cout << "Cleo" << '\t' << i << '\t' << c_invests << endl;
  
  return 0;
}
