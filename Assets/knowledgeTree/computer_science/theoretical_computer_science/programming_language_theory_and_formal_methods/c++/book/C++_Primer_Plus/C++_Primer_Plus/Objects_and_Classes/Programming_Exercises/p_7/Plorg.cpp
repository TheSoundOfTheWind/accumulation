#include "Plorg.h"
#include <string.h>
#include <iostream>
Plorg::Plorg()
{
  memset(m_name, 0, SIZE*sizeof(char));
  strcpy(m_name, "Plorga");
  m_ci = -1;
}

Plorg::Plorg(const char * name, int ci)
{
  memset(m_name, 0, SIZE*sizeof(char));
  strcpy(m_name, name);
  m_ci = ci;
}

void Plorg::set_ci(int ci)
{
  m_ci = ci;
}
void Plorg::report()
{
  std::cout << "name: " << m_name << " CI: " << m_ci << std::endl;
}
