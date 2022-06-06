#include <iostream>
#include <memory>
#include <GLES3/gl3.h>
#include <QGLContext>
#include <glm/glm.hpp>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QCoreApplication>

#include "enThread.h"
#include "mainWidget.h"

struct mainWidget::Data {
  std::shared_ptr<enThread> thread;
};

mainWidget::mainWidget(const QGLFormat & format, QWidget * parent):
  QGLWidget(format, parent),
  m_data(std::make_shared<Data>())
{
  setAutoBufferSwap(false);
}

mainWidget::~mainWidget()
{
  
}
// set methods
// -----------------------------------------------------------------------------
void
mainWidget::startThread()
{
  doneCurrent();
  m_data->thread = std::make_shared<enThread>(this->shared_from_this());
  QGLContext * ctx = context();
  if (nullptr == ctx) {
    printf("-E- No OpenGL context\n");
    return;
  }
  if (!ctx->isValid()) {
    printf("-E OpenGL context is not valid\n");
    return;
  }
  //  QCoreApplication::instance()->setAttribute(Qt::AA_DontCheckOpenGLContextThreadAffinity);
  ctx->moveToThread(m_data->thread.get());
  m_data->thread->start();
}
// -----------------------------------------------------------------------------
void
mainWidget::stopThread()
{
  if (m_data->thread) {
    m_data->thread->stop();
    m_data->thread.reset();
  }
}
// -----------------------------------------------------------------------------
void
mainWidget::resizeEvent(QResizeEvent* event)
{
  //  printf("resizeGL()\n");
    const QSize newSize = event->size();
    m_size = newSize;
    if (m_data->thread) {
        m_data->thread->setViewPortSize(
            newSize.width(),
            newSize.height());
    }
}
// -----------------------------------------------------------------------------
void
mainWidget::paintEvent(QPaintEvent * event)
{
  //  printf("paintEvent()\n");
  /*
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);
  this->swapBuffers();
  */
}
// -----------------------------------------------------------------------------
void
mainWidget::closeEvent(QCloseEvent* event)
{
  stopThread();
}
// -----------------------------------------------------------------------------
// mouse methods
void
mainWidget::mousePressEvent(QMouseEvent * event)
{
  m_startPoint = event->pos();
}
// -----------------------------------------------------------------------------
void
mainWidget::mouseMoveEvent(QMouseEvent * event)
{
  m_endPoint = event->pos();
  float x1 = -1.0 + 2.0*(m_startPoint.x()/float(m_size.width()));
  float y1 = 1.0 -2.0*(m_startPoint.y())/float(m_size.height());
  float x2 = -1.0 + 2.0*(m_endPoint.x()/float(m_size.width()));
  float y2 = 1.0 -2.0*(m_endPoint.y())/float(m_size.height());
  
  glm::vec2 prevMouse = glm::vec2(x1, y1);
  glm::vec2 curMouse = glm::vec2(x2, y2);
  m_engine.camera().processMouseMovement(prevMouse, curMouse);
  m_startPoint = m_endPoint;
}
// -----------------------------------------------------------------------------
void
mainWidget::mouseReleaseEvent(QMouseEvent * event )
{

}
// -----------------------------------------------------------------------------
// key methods
void
mainWidget::keyPressEvent(QKeyEvent * event)
{
  switch (event->key()) {
  case Qt::Key_W:
    {
      printf("key w\n");
      m_engine.camera().moveToIn();
    }
    break;
  case Qt::Key_S:
    {
      printf("key s\n");
      m_engine.camera().moveToOut();
    }
    break;
  case Qt::Key_A:
    {
      printf("key a\n");
      m_engine.camera().moveToLeft();
    }
    break;
  case Qt::Key_D:
    {
      printf("key d\n");
      m_engine.camera().moveToRight();
    }
    break;
  default:
    break;
  }
}
// -----------------------------------------------------------------------------
void
mainWidget::wheelEvent(QWheelEvent * event)
{
  m_engine.camera().zoom(event->delta());
}
