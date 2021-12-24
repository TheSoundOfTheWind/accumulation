#include <iostream>
#include <cctype>
int main()
{
  using namespace std;
  char ch;
  while ((ch = cin.get()) != '@')
    {
      if(!isdigit(ch))
	{
	  if(islower(ch))
	    ch = toupper(ch);
	  else if(isupper(ch))
	    ch = tolower(ch);
	  cout << ch;
	}
    }
  return 0;
}
