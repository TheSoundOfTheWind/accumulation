#pragma once
#include <QThread>
#include "mainWidget.h"
class enThread : public QThread
{
  Q_OBJECT
 public:
  // Constructs the thread from the widget.
  enThread(std::weak_ptr<mainWidget> widget);
  ~enThread();
    // Sets the viewport size
    void setViewPortSize(int w, int h);

    // Starts the rendering thread.
    void start();

    // Stops the rendering thread.
    void stop();

protected:
    virtual void run();

private:
    struct Data;
    std::shared_ptr<Data> m_data;
};

