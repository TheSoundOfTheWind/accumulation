#ifndef ENENGINE_H
#define ENENGINE_H
#include "enRender.h"
#include "enShader.h"
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
  void updateModel(glm::mat4 & mat);
  void updateView(glm::mat4 & mat);
  void updateProjection(glm::mat4 & mat);
  void pressW();
  void pressS();
  void pressA();
  void pressD();
  void moveMouse(float xoffset, float yoffset);
  void moveWheel(int delta);
  // -----------------------------------------------------------------------------------

 private:
  int                m_width;
  int                m_height;
  enRender     m_render;
  enShader     m_shader;
  glm::mat4    m_model;
  glm::mat4    m_view;
  glm::mat4    m_projection;
  glm::mat4    m_clip;

  glm::vec3     m_cameraPos;
  glm::vec3     m_cameraFront;
  glm::vec3     m_cameraUp;
  float             m_cameraSpeed;

  float             m_yaw;
  float             m_pitch;
  float             m_fov;
};
#endif
