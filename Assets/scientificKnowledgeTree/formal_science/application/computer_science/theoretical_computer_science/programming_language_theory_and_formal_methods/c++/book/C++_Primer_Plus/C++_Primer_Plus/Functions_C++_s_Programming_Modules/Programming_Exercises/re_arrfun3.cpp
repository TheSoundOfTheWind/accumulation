// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;
#define It double *
// function prototypes
int fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end);       // don't change data
void revalue(double r, double * begin, double * end);
int main()
{
  using namespace std;
  double properties[Max];

  int size = fill_array(properties, properties + Max);
  show_array(properties, properties + size);

  if(size > 0)
    {
      cout << "Enter revaluation factor: ";
      double factor;
      while (!(cin >> factor))        // bad input
	{
	  cin.clear();
	  while (cin.get() != '\n')
	    continue;
	  cout << "Bad input; Please enter a number: ";
	}
      revalue(factor,properties,properties + size);
      show_array(properties,properties + size);
    }
  cout << "Done.\n";
  cin.get();
  cin.get();
  return 0;
}

int fill_array(double * begin, double * end)
{
  using namespace std;
  double temp;
  It it;
  int i = 0;
  for(it = begin; it != end;++i,it++)
    {
      cout << "Enter value #" << (i+1) << ": ";
      cin >> temp;
      if(!cin)          // bad input
	{
	  cin.clear();
	  while(cin.get() != '\n')
	    continue;
	  cout << "Bad input; input process terminated.\n";
	  break;
	}
      else if(temp < 0)
	break;
      (*it) = temp;
    }
  return i;
}

// the following function can use, but not alter
// the array whose address is ar
void show_array(const double * begin, const double * end)
{
  using namespace std;
  int i = 0;
  const It it = nullptr;
  for(it = begin; it != end; ++it, ++i)
    {
      cout << "Property #" << (i+1) << ": $";
      cout << (*it) << endl;
    }
}

// multiplies each element of ar[] by r
void revalue (double r, double * begin, double *end)
{
  It it = nullptr;
  for (it = begin; it != end; ++it)
    (*it) = r;
}
