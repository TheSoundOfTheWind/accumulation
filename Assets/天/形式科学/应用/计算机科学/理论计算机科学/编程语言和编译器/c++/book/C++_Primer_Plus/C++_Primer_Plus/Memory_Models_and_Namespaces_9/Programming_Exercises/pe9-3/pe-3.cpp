#include <iostream>
// for strcpy()
#include <string.h>
const unsigned int NUM = 2;
struct chaff{
  char dross[20];
  int slag;
};
void set(chaff &, const char *, const int);
void show(const chaff &);  
int main()
{

  unsigned int op = 0;
  chaff * p_ch = nullptr;
  // option static buffer or new 
  std::cout << "Enter your option(1 or 2): ";
  std::cin >> op;
  switch(op)
    {
      // static
    case 1:
      {
	const int BUF = 512;
	char buffer[BUF];
	p_ch = new (buffer)chaff[NUM];
      }
      break;
      // new
    case 2:
      {
	std::cout << "Enter buffer size: ";
	int size  = 0;
	std::cin >> size;
	char * buffer = new char[size];
	p_ch = new (buffer)chaff[NUM];
      }
      break;
    }

  // set chaff
  set(p_ch[0], "jin", 1);
  set(p_ch[1], "hai", 2);

  // show show
  for(int i = 0; i < NUM; i++)
    show(p_ch[i]);

  return 0;
}

void set(chaff &chaff, const char *dross, const int slag)
{
  strcpy(chaff.dross, dross);
  chaff.slag = slag;
}

void show(const chaff & chaff)
{
  std::cout << "dross: " << chaff.dross << "\t\t";
  std::cout << "slag: " << chaff.slag << '\n';
}

