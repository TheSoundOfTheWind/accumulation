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
  enEngine();
  virtual ~enEngine();
  
  // set methods
  // ------------------------------------------------------------------------------------
  void init();
  void render();
  void setViewPort(int width, int height);
 private:
  GLuint loadShaders(const char * vertexShaderSource, const char * fragmentShaderSource);
  // -----------------------------------------------------------------------------------

 private:
  int          m_width;
  int          m_height;
  enRender     m_render;
  glm::mat4    m_model;
  glm::mat4    m_view;
  glm::mat4    m_projection;
  glm::mat4    m_clip;
  GLuint       m_shaderProgramId;
};
#endif
