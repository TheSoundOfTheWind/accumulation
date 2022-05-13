#include <iostream>
#include <memory>
#include <GLES3/gl3.h>
#include <QGLContext>
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
  printf("resizeGL()\n");
    const QSize newSize = event->size();
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
  printf("paintEvent()\n");
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
mainWidget::closeEvent(QCloseEvent* even)
{
  stopThread();
}
// -----------------------------------------------------------------------------
