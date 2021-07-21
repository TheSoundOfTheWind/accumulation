#include <iostream>
#include <vector>
int main()
{
  struct contributor{
    std::string name;
    double contribution;
  };
  typedef struct contributor con;
  int num = 0;
  std::cout << "Enter the number of contributors ";
  std::cin >> num;
  std::vector<con> * users = new std::vector<con>(num);
  for(auto it = users->begin();it != users->end();++it)
    {
      std::cout << "name ";
      std::cin.get();
      std::cin >> (*it).name;
      std::cout << "contributors ";
      std::cin.get();
      std::cin >> (*it).contribution;
    }
  
  bool display_grand = false;
  bool display_patron = false;
  for(auto it = users->begin();it != users->end(); ++it)
    {
      if((*it).contribution > 10000)
	{
	  if(!display_grand)
	    {
	      display_grand = true;
	      std::cout << "Grand Patrons" << std::endl;
	    }
	  std::cout << (*it).name << " " << (*it).contribution << std::endl;
	}
      else
	{
	  if (!display_patron)
	    {
	      display_patron = true;
	      std::cout << "Patrons" << std::endl;
	    }
	  std::cout << (*it).name << " " << (*it).contribution << std::endl;
	}
    }
  if (!display_grand)
    std::cout << "Grand Patrons none" << std::endl;
  if (!display_patron)
    std::cout << "Patrons none" << std::endl;
  return 0;
}
