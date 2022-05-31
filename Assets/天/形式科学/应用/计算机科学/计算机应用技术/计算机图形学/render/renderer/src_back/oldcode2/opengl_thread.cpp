/* ---------------------------------------------------------------- *
   Author: Kuumies <kuumies@gmail.com>
   Desc:   Implmentation of kuu::opengl::Thread class.
 * ---------------------------------------------------------------- */


#include <chrono>
#include <QMutex>
#include <iostream>
//#include <glm/gtx/transform.hpp>
//#include "opengl_quad.h"
#include "opengl_thread.h"

namespace kuu
{
namespace opengl
{

/* ---------------------------------------------------------------- *
   The data of the thread.
 * ---------------------------------------------------------------- */
struct Thread::Data
{
    Data(Widget::WeakPtr openglWidget)
        : openglWidget(openglWidget)
        , initialized(false)
        , render(true)
        , viewportWidth(720)
        , viewportHeight(576)
    {}

    Widget::WeakPtr openglWidget;
    bool initialized;
    bool render;
    int viewportWidth;
    int viewportHeight;
    QMutex mutex;
};

/* ---------------------------------------------------------------- *
   Constructs the thread.
 * -----------------------------------------------------------------*/
Thread::Thread(Widget::WeakPtr openglWidget)
    : d(std::make_shared<Data>(openglWidget))
{}

void Thread::setViewportSize(int width, int height)
{
    d->mutex.lock();
    d->viewportWidth  = width;
    d->viewportHeight = height;
    d->mutex.unlock();
}

/* ---------------------------------------------------------------- *
   Starts the rendering thread if it is not running already.
 * ---------------------------------------------------------------- */
void Thread::start()
{
    if (isRunning())
        return;

    d->render = true;
    QThread::start();
}

/* ---------------------------------------------------------------- *
   Stops the rendering thread from the run state to idle state.
 * ---------------------------------------------------------------- */
void Thread::stop()
{
    d->mutex.lock();
    d->render = false;
    d->mutex.unlock();

    quit();
    wait();
}

/* ---------------------------------------------------------------- *
   Runs the OpenGL rendering until the user stops it by calling
   stop() or the widget pointer goes invalid. If the operating
   system is Windows then the GLEW is initialized before rendering.
* ---------------------------------------------------------------- */
void Thread::run()
{

    // Render until the thread is stopped or widget is deleted.
    for(;;)
    {
        int w = 0, h = 0;
        bool render = true;

        d->mutex.lock();
        render = d->render;
        w = d->viewportWidth;
        h = d->viewportHeight;
        d->mutex.unlock();

        if (!render)
            break;

        // Get the widget pointer.
        Widget::Ptr widget = d->openglWidget.lock();
        if (!widget)
            break;

        // Make the widget context current.
        widget->makeCurrent();

        glViewport(0, 0, w, h);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);

        // Swap buffers and we're done.
        widget->swapBuffers();
        widget->doneCurrent();
    }
}

} // namespace opengl
} // namespace kuu
