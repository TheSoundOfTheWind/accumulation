#ifndef ENENGINE_H
#define ENENGINE_H
#include "enRender.h"
#include <QGLWidget>
#include <glm/glm.hpp>
#include <GLES3/gl3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class enEngine {
 public:
  enEngine() {};
  virtual ~enEngine() {};
  
  void init();
  void render();
  void setViewPort(int width, int height);
 private:
  GLuint loadShaders(const char * vertexShaderSource, const char * fragmentShaderSource);

 private:
  int          m_width;
  int          m_height;
  enRender     m_render;
  GLuint       m_shaderProgramId;
};
#endif
