#include <stdio.h>
#include <string>
#include <strings.h>
using namespace std;
//步骤1 创建一个接口
class Shape{
public:
  virtual void draw() = 0;
};

//步骤2 创建实现接口的实体类
class Rectangle : public Shape {
public:
  virtual void draw() {
    printf("Inside Rectangle::draw() methods.\n");
  }
};

class Square : public Shape{
public:
  virtual void draw() {
    printf("Inside Square::draw() method.\n");
  }
};

class Circle : public Shape {
public:
  virtual void draw() {
    printf("Inside Circle::draw() method.\n");
  }
};
//步骤3 创建一个工厂，生成基于给定信息的实体类对象
class ShapeFactory {
public:
  Shape * getShape(string shapeType) {
    if (true == shapeType.empty()) {
      return nullptr;
    } else if (strcasecmp(shapeType.c_str(), "circle") == 0) {
      return new Circle();
    } else if (strcasecmp(shapeType.c_str(), "rectangle") == 0) {
      return new Rectangle();
    } else if (strcasecmp(shapeType.c_str(), "square") == 0) {
      return new Square();
    }
    return nullptr;
  }
};


int main()
{
  ShapeFactory * shapeFactory = new ShapeFactory();

  // 获取Circle的对象，并调用它的draw方法
  Shape * shape1 = shapeFactory->getShape("circle");
  shape1->draw();
  delete shape1;

  //获取Rectangle 的对象,并调用它的draw方法
  Shape * shape2 = shapeFactory->getShape("rectangle");
  shape2->draw();
  delete shape2;

  //获取 Square 的对象,并调用它的 draw方法
  Shape * shape3 = shapeFactory->getShape("square");
  shape3->draw();
  delete shape3;
  return 0;
}

