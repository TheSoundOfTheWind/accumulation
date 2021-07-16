#include <iostream>
#include <string>
void str_to_upp(std::string & str)
{
  int i = 0;
  while(str[i])
    {
      str[i] = toupper(str[i]);
      i++;
    }
}
int main()
{
  std::string in_str;
  std::cout << "Enter a string (q to quit): ";
  std::getline(std::cin, in_str);
  while(in_str != "q")
    {
      str_to_upp(in_str);
      std::cout << in_str << std::endl;
      std::cout << "Next string (q to quit): ";
      std::getline(std::cin, in_str);
    }
  std::cout << "Bye." << std::endl;
  return 0;
}
