#ifndef  ENCAMERA_H
#define ENCAMERA_H
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class enCamera {
 public:
  enCamera();
  virtual ~enCamera();

  // get methods
  // ---------------------------------------------------------------------------
  glm::mat4 getViewMatrix();
  float          zoom() const { return m_fov; };
  // ---------------------------------------------------------------------------  

  // set methods
  // ---------------------------------------------------------------------------
  void moveToIn();
  void moveToOut();
  void moveToLeft();
  void moveToRight();
  void zoom(int delta);
  void processMouseMovement(glm::vec2 prevMouse, glm::vec2 curMouse);
  glm::vec3 & cameraPos() { return m_cameraPos; }
  
 private:
  glm::vec3 screen_to_arcball(const glm::vec2 & p);
  glm::vec3 rotate_axis_angle(glm::vec3 & vec, glm::vec3 axis, float angle);
  // ---------------------------------------------------------------------------  
 private:
  // new
  glm::vec3     m_cameraPos;  
  glm::vec3     m_cameraTarget;
  glm::vec3     m_cameraDirection;
  glm::vec3     m_cameraUp;  
  glm::vec3     m_cameraRight;
  glm::vec3     m_cameraFront;
  glm::mat4    m_viewMatrix;
  float             m_cameraSpeed;
  
  float             m_fov;
};
#endif // ENCAMERA_H

