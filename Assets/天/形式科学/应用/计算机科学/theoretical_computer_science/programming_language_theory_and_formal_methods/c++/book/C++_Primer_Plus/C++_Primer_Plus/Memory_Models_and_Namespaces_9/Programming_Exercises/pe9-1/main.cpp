#include "golf.h"
#include <stdio.h>
int main()
{
  const unsigned int SIZE = 3;
  golf golf_array[SIZE];
  do{
    if(SIZE == 0)
      break;
    setgolf(golf_array[0], "xiaoming", 100);
    for(int i = 1; i < SIZE; ++i)
      {
	setgolf(golf_array[i]);
      }
    for(int i = 0; i < SIZE; ++i)
      {
	showgolf(golf_array[i]);
      }
    handicap(golf_array[0], 99);
    for(int i = 0; i < SIZE; ++i)
      {
	showgolf(golf_array[i]);
      }
  }while(0);

  return 0;
}
