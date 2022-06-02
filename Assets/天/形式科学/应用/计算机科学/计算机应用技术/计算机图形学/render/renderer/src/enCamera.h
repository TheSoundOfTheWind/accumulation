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
  void rotate(float xpos, float ypos);
  void rotate2(float xpos, float ypos);
  void zoom(int delta);
  void setFirstMouse(bool firstmouse) { m_isFirstMouse = firstmouse; };
  void processMouseMovement(glm::vec2 prevMouse, glm::vec2 curMouse);
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
  
  float             m_yaw;
  float             m_pitch;
  bool             m_isFirstMouse;
  float             m_lastX;
  float             m_lastY;
  
  float             m_fov;
};
#endif // ENCAMERA_H
