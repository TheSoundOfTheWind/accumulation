#include <iostream>
#include <cctype>
#include <string>
int main()
{
  using namespace std;
  cout << "Enter words (q to quit) :" << endl;
  string word;
  int vowels = 0;
  int consonants = 0;
  int others = 0;
  bool is_num = false;
  while(cin >> word)
    {
      if(word.size() == 1 and word[0] == 'q')
	break;
      for(char ch : word)
	{
	  if(isdigit(ch))
	    {
	      ++others;
	      is_num = true;
	      break;
	    }
	}
      if(is_num)
	{
	  is_num = false;
	  continue;
	}
      char ch = word[0];
      switch(ch)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	  ++vowels;
	  break;
	default:
	  ++consonants;
	}
    }
  cout << vowels << " words beginning with vowels" << endl;
  cout << consonants << " words beginning with consonants" << endl;
  cout << others << " others" << endl;
  
  return 0;
}
