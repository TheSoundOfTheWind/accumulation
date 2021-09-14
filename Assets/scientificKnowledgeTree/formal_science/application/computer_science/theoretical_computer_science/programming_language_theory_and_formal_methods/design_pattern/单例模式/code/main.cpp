#include <stdio.h>

class SingleObject {
public:
  static SingleObject*  getInstance() {
    if (nullptr == m_singleObject) {
      m_singleObject = new SingleObject();
    }
    return m_singleObject;
  }

  void showMessage() {
    printf("Hello World\n");
  }
private:
  SingleObject() {} 
private:
  static SingleObject * m_singleObject;
};

SingleObject * SingleObject::m_singleObject = nullptr;

int main()
{
  SingleObject * singleObject = SingleObject::getInstance();
  singleObject->showMessage();
  return 0;
}
