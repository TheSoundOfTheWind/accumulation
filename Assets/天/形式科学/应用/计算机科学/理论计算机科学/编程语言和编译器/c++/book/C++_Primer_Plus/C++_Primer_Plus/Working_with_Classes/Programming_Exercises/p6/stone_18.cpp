// stone.cpp -- user-defined conversions
// compile with stonewt_18.cpp
#include <iostream>
#include "stonewt_16.h"
#include <algorithm>
#include <vector>

using std::cout;
using std::endl; 

int main()
{
  Stonewt s[6] = {(12*14),(10*14),(18*14)};
  for(int i = 0; i < 3; ++i)
    {
      s[i+3] = s[i];
    }
  std::vector<Stonewt> s_vec(s, s+6);
  std::sort(s_vec.begin(), s_vec.end());
  cout << "smallest is " << s_vec.front() << endl;
  cout << "largest is " << s_vec.back() << endl;
  int num = 0;
  Stonewt s11(11*14);
  for (auto s : s_vec)
    {
      if(s >= s11)
	{
	  num++;
	}
    }
  cout << num << " elements are greater or equal to 11 stone\n";

  cout << "******** test ********\n";
  Stonewt t1(1.0), t2(2.0), t3(1.0);
  cout << "test ==\n";
  if (t1 == t2)
    cout << "error in ==\n";
  else
    cout << "pass in ==\n";
  if (t1 == t3)
    cout << "pass in ==\n";
  else
    cout << "error in ==\n";
  cout << "\n";
    
  cout << "test !=\n";
  if (!(t1 != t2))
    cout << "error in !=\n";
  else
    cout << "pass in !=\n";
  if (!(t1 != t3))
    cout << "pass in !=\n";
  else
    cout << "error in !=\n";
  cout << "\n";
    
  cout << "test >\n";
  if (t1 > t2)
    cout << "error in >\n";
  else
    cout << "pass in >\n";
  if (t2 > t3)
    cout << "pass in >\n";
  else
    cout << "error in >\n";
  cout << "\n";

  cout << "test <\n";
  if (t2 < t1)
    cout << "error in <\n";
  else
    cout << "pass in <\n";
  if (t1 < t2)
    cout << "pass in <\n";
  else
    cout << "error in <\n";
  cout << "\n";
    
  cout << "test >=\n";
  if (t1 >= t2)
    cout << "error in >=\n";
  else
    cout << "pass in >=\n";
  if (t2 >= t1)
    cout << "pass in >=\n";
  else
    cout << "error in >=\n";
  if (t3 >= t1)
    cout << "pass in >=\n";
  else
    cout << "error in >=\n";
  cout << "\n";
    
  cout << "test <=\n";
  if (t2 <= t1)
    cout << "error in <=\n";
  else
    cout << "pass in <=\n";
  if (t1 <= t2)
    cout << "pass in <=\n";
  else
    cout << "error in <=\n";
  if (t1 <= t3)
    cout << "pass in <=\n";
  else
    cout << "error in <=\n";
  cout << "\n";
      
  return 1;
}

