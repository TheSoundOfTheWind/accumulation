// static.cpp -- using a static local variable
#include <iostream>
#include <string>
// constants
const int ArSize = 10;

// function prototyp
void strcount(const char * str);

int main()
{
  using namespace std;
  std::string input;
  char next;

  cout << "Enter a line:\n";
  getline(cin, input);
  while(cin)
    {
      if(!input.empty())
	strcount(input.c_str());
      cout << "Enter next line (empty line to quit):\n";
      getline(cin, input);
    }
  cout << "Bye\n";

  return 0;
}

void strcount(const char * str)
{
  using namespace std;
  static int total = 0;           // static local variable
  int count = 0;                  // sutomatic local variable

  cout << "\"" <<  str << "\"contains ";
  while(*str++)
    count++;
  total += count;
  cout << count << " characters\n";
  cout << total << " characters total\n";
}
