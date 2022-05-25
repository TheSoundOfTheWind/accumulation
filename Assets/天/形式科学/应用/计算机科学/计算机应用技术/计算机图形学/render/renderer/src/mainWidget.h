#pragma once

//#include <GLES3/gl3.h>
#include <memory>
#include <QtOpenGL/QGLWidget>
class mainWidget
    : public QGLWidget
    , public std::enable_shared_from_this<mainWidget>
{
  //  Q_OBJECT
 public:
    // Constructs the widget.
   mainWidget(const QGLFormat& openglFormat, QWidget * parent = nullptr);
   ~mainWidget();

   // Starts the rendering thread.
    void startThread();

    // Stops the rendering thread.
    void stopThread();

protected:
    void resizeEvent(QResizeEvent* event);
    void paintEvent(QPaintEvent* event);
    void closeEvent(QCloseEvent* event);

private:
    struct Data;
    std::shared_ptr<Data> m_data;
};
