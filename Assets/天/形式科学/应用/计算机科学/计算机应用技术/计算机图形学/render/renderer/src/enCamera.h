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
  void moveToout();
  void moveToLeft();
  void moveToRight();
  void rotate(float xoffset, float yoffset);
  void zoom(int delta);
  // ---------------------------------------------------------------------------  
 private:
  glm::vec3     m_cameraPos;
  glm::vec3     m_cameraFront;
  glm::vec3     m_cameraUp;
  float             m_cameraSpeed;
  
  float             m_yaw;
  float             m_pitch;
  float             m_fov;
};
#endif // ENCAMERA_H
