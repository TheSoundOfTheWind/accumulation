#include <iostream>
#include <stdio.h>
using namespace std;
const int SLEN = 30;
struct student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicts and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);

// display() takes a student structs as an argument
// and displays its contents
void display1(student st);

// display2() takes the address of student structure as an
// argument and display the structure's contents
void display2(const student * ps);

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);

int main()
{
  using namespace std;
  cout << "Enter class size: ";
  int class_size;
  cin >> class_size;
  while (cin.get() != '\n')
    continue;

  student * ptr_stu = new student[class_size];
  int entered = getinfo(ptr_stu, class_size);
  for (int i = 0; i < entered; i++)
    {
      display1(ptr_stu[i]);
      display2(&ptr_stu[i]);
    }
  display3(ptr_stu, entered);
  delete [] ptr_stu;
  cout << "Done\n";
  
  return 0;
}

int getinfo(student pa[], int n)
{
  int i = 0;
  std::cout << "Enter fullname, hobby, ooplevel: " << std::endl;
  for (i; i < n; ++i)
    {
      if(!(cin >> pa[i].fullname >> pa[i].hobby >> pa[i].ooplevel))
	break;
    }
  return i;
}

void display1(student st)
{
  printf("%-12s%-12s%-12s\n", "fullname", "hobby", "ooplevel");
  printf("%-12s%-12s%-12d\n", st.fullname, st.hobby, st.ooplevel);
}

void display2(const student * ps)
{
  printf("%-12s%-12s%-12s\n", "fullname", "hobby", "ooplevel");
  printf("%-12s%-12s%-12d\n", ps->fullname, ps->hobby, ps->ooplevel);
}

void display3(const student pa[], int n)
{
  printf("%-12s%-12s%-12s\n", "fullname", "hobby", "ooplevel");  
  for(int i = 0; i < n; ++i)
    {
      printf("%-12s%-12s%-12d\n", pa[i].fullname, pa[i].hobby, pa[i].ooplevel);
    }
}
