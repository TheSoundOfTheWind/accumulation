#ifndef ENENGINE_H
#define ENENGINE_H
#include "enRender.h"
#include "enShader.h"
#include "enCamera.h"
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class enEngine {
 public:
  enEngine();
  virtual ~enEngine();
  
  // set methods
  // ------------------------------------------------------------------------------------
  void init();
  void render();
  void setViewPort(int width, int height);
  enCamera & camera() { return  m_camera; }
  // -----------------------------------------------------------------------------------

 private:
  int                m_width;
  int                m_height;
  enRender     m_render;
  enCamera    m_camera;
};
#endif
