#include <string.h>
#include <stdio.h>
template <typename T> T maxn(T array[], unsigned int n);
template <>  char * maxn<char *> (char * array[], unsigned int n);
int main()
{
  int i_arr[6] = {1, 8, 3, 0, 5, 6};
  double d_arr[4] = {2.3, 8.9, 0.9, 3.4};
  const char * c_arr[5] = {"jin", "hailin", "huang", "qingqing", "I love you"};

  int i_max = maxn(i_arr, 6);
  double d_max = maxn(d_arr, 4);
  const char * c_max = maxn(c_arr, 5);
  printf("i_max= %d, d_max= %f, c_max= %s\n",i_max, d_max, c_max);
  return 0;
}

template <typename T> T maxn(T array[], unsigned int n)
{
  T max = 0;
  if(n > 0)
    max = array[0];
  for (int i = 1; i < n; ++i)
    max = max > array[i] ? max : array[i];
  return max;
}
template <>  char * maxn<char *> (char * array[], unsigned int n)
{
  unsigned int len = 0;
  char * r_ch = nullptr;
  do {
    if(n <= 0)
      break;
    len = strlen(array[0]);
    r_ch = array[0];
    unsigned int t_len;
    for (int i = 1; i < n; ++i)
      {
	t_len = strlen(array[i]);
	if(t_len > len)
	  {
	    len = t_len;
	    r_ch = array[i];
	  }
      }
  }while(0);
  return r_ch;
}
