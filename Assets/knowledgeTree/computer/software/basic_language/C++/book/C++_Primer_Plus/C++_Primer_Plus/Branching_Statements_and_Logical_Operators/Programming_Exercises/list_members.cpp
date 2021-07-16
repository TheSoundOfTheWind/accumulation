#include <iostream>
int main()
{
  using namespace std;
  const int strsize = 100;
  // Benevolent Order of Programmers name structure:
  struct bop {
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // = fullname, 1 = title, 2 = bopname
  };

  struct bop array_bop[3] = {
    {"zhangsan","teacher","san",2},
    {"lisi","driver","laoli",1},
    {"wangwu","master","xiaowang",0}
  };
  cout << "Benevolent Order of Programmers Report" << endl;
  cout << "a. display by name          b. display by title"<< endl;
  cout << "c. display by bopname       d. display by preference"<< endl;
  cout << "q. quit" << endl;

  char ch;
  cout << "Enter your choice: ";

  // array_bop length
  int length = sizeof(array_bop)/sizeof(array_bop[0]);
  while(true)
    {
      while(!(cin >> ch))
	{
	  cin.clear();
	  while(cin.get() != '\n')
	    continue;
	  cout << "Next choice: ";
	}
      if(ch == 'q')
 	{
	  cout << "Bye!" << endl;
	  break;
	}
      switch(ch)
	{
	case 'a':
	  {
	    for (int i = 0; i < length; ++i)
	      cout << array_bop[i].fullname << endl;
	  }
	  break;
	case 'b':
	  {
	    for (int i = 0; i < length; ++i)
	      cout << array_bop[i].title << endl;
	  }

	  break;
	case 'c':
	  {
	    for (int i = 0; i < length; ++i)
	      cout << array_bop[i].bopname << endl;
	  }
	  break;
	case 'd':
	  {
	    for (int i = 0; i < length; ++i)
	      {
		switch(array_bop[i].preference)
		  {
		  case 0:
		    cout << array_bop[i].fullname << endl;
		    break;
		  case 1:
		    cout << array_bop[i].title << endl;
		    break;
		  case 2:
		    cout << array_bop[i].bopname << endl;
		    break;
		  default:
		    cout << "\t\terror\n";
		    break;
		  }
	      }
	  }
	  break;
	default:
	  cout << "Next choice: ";
	  break;
	}
    }
  return 0;
}
