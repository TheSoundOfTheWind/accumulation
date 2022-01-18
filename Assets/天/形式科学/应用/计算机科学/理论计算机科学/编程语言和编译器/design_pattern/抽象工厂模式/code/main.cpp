#include <string>
#include <stdio.h>
#include <strings.h>

using namespace std;

// 步骤1 为形状创建一个接口
class Shape {
public:
  virtual void draw() = 0;
};


// 步骤2 创建实现接口的实体类

class Rectangle : public Shape {
public:
  virtual void draw() {
    printf("Inside Rectangle::draw() method.\n");
  }
};

class Square : public Shape {
public:
  virtual void draw() {
    printf("Inside Square::draw() method.\n");
  }
};

class Circle : public Shape {
  virtual void draw() {
    printf("Inside Circle::draw() method.\n");
  }
};

// 步骤3 为颜色创建一个接口
class Color {
public:
  virtual void fill() = 0;
};

// 步骤4 创建实现接口的实体类
class Red : public Color {
public:
  virtual void fill() {
    printf("Inside Red::fill() methods.\n");
  }
};

class Green : public Color {
public:
  virtual void fill() {
    printf("Inside Green::fill() method.\n");
  }
};

class Blue : public Color {
public:
  virtual void fill() {
    printf("Inside Blue::fill() method.\n");
  }
};

// 步骤5 为 Color 和 Shape 对象创建抽象类来获取工厂

class AbstracFactory {
public:
  virtual Color * getColor(string color) = 0;
  virtual Shape * getShape(string shape) = 0;
};

// 步骤6 扩展了AbstracFactory 的工厂类，基于给定信息生成实体类的对象

class ShapeFactory : public AbstracFactory {
public:
  virtual Shape * getShape(string shapeType) {
    if (true == shapeType.empty()) {
      return nullptr;
    }
    if (strcasecmp("circle", shapeType.c_str()) == 0) {
      return new Circle();
    } else if (strcasecmp("rectangle", shapeType.c_str()) == 0) {
      return new Rectangle();
    } else if (strcasecmp("square", shapeType.c_str()) == 0) {
      return new Square();
    }

    return nullptr;
  }

  virtual Color * getColor(string color) {
    return nullptr;
  }
};

class ColorFactory : public AbstracFactory  {
public:
  virtual Shape * getShape(string shapeType) {
    return nullptr;
  }

  virtual Color * getColor(string color) {
    if (true == color.empty()) {
      return nullptr;
    }
    if (strcasecmp("red", color.c_str()) == 0) {
      return new Red();
    } else if (strcasecmp("green", color.c_str()) == 0) {
      return new Green();
    } else if (strcasecmp("blue", color.c_str()) == 0) {
      return new Blue();
    }

    return nullptr;
  }
};

//

class FactoryProducer {
public:
  static AbstracFactory* getFactory(string choice) {
    if (strcasecmp("shape", choice.c_str()) == 0) {
      return new ShapeFactory();
    } else if (strcasecmp("color", choice.c_str()) == 0) {
      return new ColorFactory();
    }

    return nullptr;
  }
};

//


int main() {
  // 
  AbstracFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");

  Shape* shape1 = shapeFactory->getShape("CIRCLE");

  shape1->draw();

  Shape * shape2 = shapeFactory->getShape("RECTANGLE");

  shape2->draw();

  Shape * shape3 = shapeFactory->getShape("SQUARE");

  shape3->draw();

  AbstracFactory * colorFactory = FactoryProducer::getFactory("COLOR");

  Color * color1 = colorFactory->getColor("RED");

  color1->fill();

  Color * color2 = colorFactory->getColor("Green");

  color2->fill();

  Color * color3 = colorFactory->getColor("BLUE");

  color3->fill();

  return 0;
}

