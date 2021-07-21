#include <cstring>
#include <stdio.h>
#include "cow.h"


Cow::Cow():weight(0)
{
  printf("Cow()\n");
  memset(name, 0, sizeof name);
  hobby = new char[1];
  hobby[0] = '\0';
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
  printf("Cow(const char * nm, const char * ho, double wt)\n");
  memset(name, 0, sizeof(name));
  strncpy(name, nm, sizeof(name));
  hobby = new char[strlen(ho) + 1];
  strcpy(hobby, ho);
  hobby[strlen(ho)] = '\0';
  weight = wt;
}

Cow::Cow(const Cow & c)
{
  printf("Cow(const Cow & c)\n");
  memset(name, 0, sizeof(name));
  strcpy(name, c.name);
  hobby = new char[strlen(c.hobby)+1];
  strcpy(hobby, c.hobby);
  hobby[strlen(c.hobby)] = '\0';
  weight = c.weight;
}

Cow::~Cow()
{
  printf("~Cow()\n");
  memset(name, 0, sizeof(name));
  delete [] hobby;
  weight = 0;
}

Cow & Cow::operator=(const Cow & c)
{
  printf("operator=(const Cow & c)\n");
  if (hobby == c.hobby)
    return *this;
  delete [] hobby;
  memset(name, 0, sizeof(name));
  strncpy(name, c.name, sizeof(name));
  hobby = new char[strlen(c.hobby) + 1];
  strcpy(hobby, c.hobby);
  hobby[strlen(c.hobby)] = '\0';
  weight = c.weight;
  return *this;
}

void Cow::ShowCow() const            // display all cow data
{
  printf("----------------------------\n");
  printf("name: %s\n", name);
  printf("hobby: %s\n", hobby);
  printf("weight: %f\n", weight);
  printf("----------------------------\n");
}
