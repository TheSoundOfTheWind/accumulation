#include <iostream>
#include <vector>
#include <fstream>
int main()
{
  struct contributor{
    std::string name;
    double contribution;
  };
  typedef struct contributor con;
  int num = 0;
  std::string line;
  std::ifstream infile("txt");
  std::getline(infile,line);
  std::cout << line << std::endl;
  num = std::stoi(line);
  std::vector<con> * users = new std::vector<con>(num);
  for(auto it = users->begin();it != users->end();++it)
    {
      std::string line;
      std::getline(infile,line);
      (*it).name = line;
      std::cout << "name " << (*it).name << std::endl;
      std::getline(infile,line);
      (*it).contribution = std::stod(line);

    }
  infile.close();
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
