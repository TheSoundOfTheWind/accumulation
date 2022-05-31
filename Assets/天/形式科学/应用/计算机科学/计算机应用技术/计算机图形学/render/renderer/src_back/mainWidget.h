#pragma once
#include "enEngine.h"
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

   // get methods
   // --------------------------------------------------------------------------

   // --------------------------------------------------------------------------   
   
   // set methods
   // --------------------------------------------------------------------------
   // Starts the rendering thread.
    void startThread();

    // Stops the rendering thread.
    void stopThread();

    enEngine & getEngine() { return m_engine; }
protected:
    void resizeEvent(QResizeEvent* event);
    void paintEvent(QPaintEvent* event);
    void closeEvent(QCloseEvent* event);
    // mouse methods
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    // key methods
    void keyPressEvent(QKeyEvent *);
    // wheel methods
    void wheelEvent(QWheelEvent *);
   // --------------------------------------------------------------------------
private:
    struct Data;
    std::shared_ptr<Data> m_data;

    enEngine                      m_engine;

    bool                              m_isMove;
    QPoint                          m_startPoint;
    QPoint                          m_endPoint;
    int                                m_lastX;
    int                                m_lastY;
    bool                              m_isFirstMouse;
};
