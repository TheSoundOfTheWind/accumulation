#include <iostream>
void input_array(double [],int size);
void display_array(const double [],int size);
double verage_array(const double [],int size);
const int SIZE = 10;
int main()
{
  double scores[SIZE];
  input_array(scores,SIZE);
  display_array(scores,SIZE);
  std::cout << "scores average is " << verage_array(scores,SIZE) << std::endl;
  return 0;
}

void input_array(double scores[],int size)
{
  for(int i = 0; i < size; ++i)
    scores[i] = -1;
  std::cout << "Enter scores and terminate with -1"<< std::endl;
  double score = 0;
  for(int i = 0; i < size; ++i)
    {
      std::cout << i+1 << " score: ";
      std::cin >> score;
      if(score == -1)
	break;
      else
	  scores[i] = score;
    }
}

void display_array(const double scores[],int size)
{
  std::cout << "display array" << std::endl;
  for(int i = 0; i < size; ++i)
    {
      if(scores[i] == -1)
	break;
      std::cout << i+1 << " score: " << scores[i] << std::endl;
    }
}

double verage_array(const double scores[], int size)
{
  int i = 0;
  double total = 0;
  for (i = 0; i < size; ++i)
    {
      if(scores[i] == -1)
	break;
      total += scores[i];
    }
  return total/i;
}

