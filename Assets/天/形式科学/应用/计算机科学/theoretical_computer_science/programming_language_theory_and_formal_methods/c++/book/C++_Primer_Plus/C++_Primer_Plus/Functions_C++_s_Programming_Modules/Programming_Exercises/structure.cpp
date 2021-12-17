#include <iostream>
struct box
{
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};
void display_box(box );
void set_volume(box *);
int main()
{
  box b = {"hljin",2,4,2,0};
  display_box(b);
  set_volume(&b);
  display_box(b);
  return 0;
}

void display_box(box b)
{
  std::cout << "--------display box--------" << std::endl;
  std::cout << "box maker: " << b.maker << std::endl;
  std::cout << "box height: " << b.height << std::endl;
  std::cout << "box width: " << b.width << std::endl;
  std::cout << "box length: " << b.length << std::endl;
  std::cout << "box volume: " << b.volume << std::endl;
}

void set_volume(box * b)
{
  float volume = (b->height)*(b->width)*(b->length);
  b->volume = volume;
}

