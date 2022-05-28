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
  void updateModel(glm::mat4 & mat);
  void updateView(glm::mat4 & mat);
  void updateProjection(glm::mat4 & mat);
  void pressW();
  void pressS();
  void pressA();
  void pressD();
  void moveMouse(float xpos, float ypos);
  void moveWheel(int delta);
  enCamera & camera() { return  m_camera; }
  // -----------------------------------------------------------------------------------

 private:
  int                m_width;
  int                m_height;
  enRender     m_render;
  enShader     m_shader;
  enCamera    m_camera;
  glm::mat4    m_model;
  glm::mat4    m_view;
  glm::mat4    m_projection;
  glm::mat4    m_clip;
};
#endif
