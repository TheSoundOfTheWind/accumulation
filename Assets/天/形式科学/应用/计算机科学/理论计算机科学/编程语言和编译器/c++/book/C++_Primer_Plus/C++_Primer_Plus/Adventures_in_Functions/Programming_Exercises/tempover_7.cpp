// tempover.cpp -- template overloading
#include <iostream>

template <typename T>        // template A
T ShowArray(T arr[], int n);

template <typename T>        // template B
T ShowArray(T * arr[], int n);
struct debts
{
  char name[50];
  double amount;
};

int main()
{
  using namespace std;
  int things[6] = {13, 31, 103, 301, 310, 130};
  struct debts mr_E[3] =
    {
      {"Ima Wolfe", 2400.0},
      {"Ura Foxe", 1300.0},
      {"Iby Stout", 1800.0}
    };
  double * pd[3];

  // set pointers to the amount members of the structures in mr_E
  for (int i = 0; i < 3; i++)
    pd[i] = &mr_E[i].amount;

  cout << "Listing Mr.E's sum of thing:\n";
  // things is an array of int
  int sum_i = ShowArray(things, 6);        // uses template A
  cout << "sum_i " << sum_i << endl;
  cout << "Listing Mr.E's sum of debts:\n";
  // pd is an array of pointers to double
  double sum_d = ShowArray(pd, 3);           // uses templates B (more specialized)
  cout << "sum_d " << sum_d << endl;
  
  return 0;
}

template <typename T>
T ShowArray(T arr[], int n)
{
  T sum = 0;
  std::cout << "template A\n";
  for (int i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}

template <typename T>
T ShowArray(T * arr[], int n)
{
  T sum = 0;
  std::cout << "template B\n";
  for (int i = 0; i < n; i++)
    sum += *arr[i];
  return sum;
}

