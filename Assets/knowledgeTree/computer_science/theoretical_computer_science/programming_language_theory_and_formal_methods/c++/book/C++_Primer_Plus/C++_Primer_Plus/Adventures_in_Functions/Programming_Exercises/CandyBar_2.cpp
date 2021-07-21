#include <iostream>
#include <stdio.h>
#include <string>
struct CandyBar
{
  std::string brand_name;
  double weight;
  int calories_num;
};

void set_CandyBar(CandyBar & candyBar, const char * brand_name = "Millennium",
		  double weight = 2.85, int calories_num = 350);  

void set_CandyBar(CandyBar & candyBar, const char * brand_name,
		  double weight, int calories_num)
{
  candyBar.brand_name = std::string(brand_name);
  candyBar.weight = weight;
  candyBar.calories_num = calories_num;
}

void displays(const CandyBar & c)
{
  printf("brand_name=%-12s ,weight=%-12f ,calories_num=%-12d\n",
	 c.brand_name.c_str(), c.weight, c.calories_num);
}

int main()
{
  CandyBar c;
  set_CandyBar(c,"jinhailin");
  displays(c);
}

