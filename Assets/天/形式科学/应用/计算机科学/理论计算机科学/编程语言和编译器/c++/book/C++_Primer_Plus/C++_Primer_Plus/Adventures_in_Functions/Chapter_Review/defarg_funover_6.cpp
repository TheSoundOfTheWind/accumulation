#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
// return the mass of an object having a desity of
// density and a volume of volume
double mass(double density, double volume = 1.0);

// function overloading
void repeat(unsigned int times, std::string str);
void repeat(std::string str);

// function overload
int average(int n1, int n2);
double average(double n1, double n2);

// function overload
char * mangle(char * str);
int main()
{
  // std::cout << mass(12.4, 2.0) << std::endl;
  // std::cout << mass(12.3) << std::endl;
  // repeat(10, "I'm OK");
  // repeat("But you're kind of stupid");
  // std::cout << average(3, 6) << std::endl;
  // std::cout << average(3.0, 6.0) << std::endl;
  char ch1 = mangle("I'm glad to meet you");
  const char * str = mangle("I'm glad to meet you");
  std::cout << ch1 << std::endl;
  std::cout << str << std::endl;
  return 0;
}

double mass(double density, double volume)
{
  return (density * volume);
};

void repeat(unsigned int times, std::string str)
{
  for (int i = 0; i < times; ++i)
    {
      std::cout << str << std::endl;
    }
}

void repeat(std::string str)
{
  const unsigned int NUM = 5;
  for (int i = 0; i < NUM; ++i)
    {
      std::cout << str << std::endl;
    }
}

int average(int n1, int n2)
{
  return ((n1 + n2) / 2);
}


double average(double n1, double n2)
{
  return ((n1 + n2) / 2);
}

const char * mangle(char * str)
{
  return str;
};

char * mangle(char * str)
{
  return &str[0];
};
