#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include "mainWidget.h"
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  // Create the OpenGL format without fixed pipeline
  QGLFormat openglFormat;
  openglFormat.setVersion(2, 1);
  openglFormat.setProfile(QGLFormat::CoreProfile);
  openglFormat.setDoubleBuffer(true);
  openglFormat.setSampleBuffers(true);

  // Create the OpenGL widget
  std::shared_ptr<mainWidget> widget = std::make_shared<mainWidget>(openglFormat);
  // widget->resize(1800, 1112);
  widget->show();
  widget->startThread();
  return app.exec();
}
