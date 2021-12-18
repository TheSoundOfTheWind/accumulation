#include <iostream>
void display(std::string * str, int num = 0)
{
  static unsigned int N = 0;
  if(0 == num)
    {
      std::cout << *str << std::endl;
      N++;
    }
  else
    {
      for(int i = 0; i < N; ++i)
	std::cout << *str << std::endl;
    }
}
int main()
{
  std::string str = "jinhailin";
  display(&str);
  display(&str);
  display(&str,1);
  display(&str,0);  
  return 0;
}
