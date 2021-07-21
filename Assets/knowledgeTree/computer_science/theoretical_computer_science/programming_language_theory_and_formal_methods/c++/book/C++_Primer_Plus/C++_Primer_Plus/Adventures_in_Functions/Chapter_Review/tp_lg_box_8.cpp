#include <iostream>
struct box
{
  char maker[40];
  float height;
  float width;
  float length;
  float volum;
};
template <typename Type> float larger (Type , Type);
template <> float larger <box> (box box1,box  box2)
{
  float volum1 = box1.height * box1.width * box1.length;
  float volum2 = box2.height * box2.width * box2.length;
  return volum1 > volum2 ? volum1: volum2;
};
int main()
{
  box box1 = {"jin", 1, 2, 3, 0};
  box box2 = {"hai", 2, 3, 5, 0};
  std::cout << "larger volum of box is " << larger(box1, box2) << std::endl;
  return 0;
}

