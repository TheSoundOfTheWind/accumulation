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
  glm::mat4 getViewMatrix() const;
  float          zoom() const { return m_fov; };
  // ---------------------------------------------------------------------------  

  // set methods
  // ---------------------------------------------------------------------------
  void moveToIn();
  void moveToOut();
  void moveToLeft();
  void moveToRight();
  void rotate(float xpos, float ypos);
  void zoom(int delta);
  void setFirstMouse(bool firstmouse) { m_isFirstMouse = firstmouse; };
  // ---------------------------------------------------------------------------  
 private:
  // new
  glm::vec3     m_cameraPos;  
  glm::vec3     m_cameraTarget;
  glm::vec3     m_cameraDirection;
  glm::vec3     m_cameraUp;  
  glm::vec3     m_cameraRight;
  glm::vec3     m_cameraFront;
  float             m_cameraSpeed;
  
  float             m_yaw;
  float             m_pitch;
  bool             m_isFirstMouse;
  float             m_lastX;
  float             m_lastY;
  
  float             m_fov;
};
#endif // ENCAMERA_H
