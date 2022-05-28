#include <iostream>
#include <memory>
#include <GLES3/gl3.h>
#include <QGLContext>
#include <QMouseEvent>
#include <QCoreApplication>
#include <QResizeEvent>
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
  m_lastX = 0;
  m_lastY = 0;
  m_isFirstMouse = true;
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
    if (m_data->thread) {
        m_data->thread->setViewPortSize(
            newSize.width(),
            newSize.height());
    }
    m_lastX = newSize.width()/2;
    m_lastY = newSize.height()/2;
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
  m_isMove = false;
  m_startPoint = event->pos();
  m_engine.camera().rotate(m_startPoint.x(), m_startPoint.y());  
}
// -----------------------------------------------------------------------------
void
mainWidget::mouseMoveEvent(QMouseEvent * event)
{
  m_isMove = true;
  m_endPoint = event->pos();
  m_engine.camera().rotate(m_endPoint.x(), m_endPoint.y());
}
// -----------------------------------------------------------------------------
void
mainWidget::mouseReleaseEvent(QMouseEvent * event )
{
  if (!m_isMove) {
    return;
  }
  m_engine.camera().setFirstMouse(true);
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
