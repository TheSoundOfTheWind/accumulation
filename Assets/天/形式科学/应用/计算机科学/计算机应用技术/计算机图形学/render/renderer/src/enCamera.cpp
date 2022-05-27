#include "enCamera.h"
enCamera::enCamera()
{
  m_cameraPos    = glm::vec3(0.0f, 0.0f, 3.0f);
  m_cameraFront  = glm::vec3(0.0f, 0.0f, -1.0f);
  m_cameraUp      = glm::vec3(0.0f, 1.0f, 0.0f);
  m_cameraSpeed = 1.0;

  m_yaw                = -90.0f;
  m_pitch               = 0.0f;

  m_fov                  = 45.0f;
}

enCamera::~enCamera()
{
  m_cameraPos    = glm::vec3(0.0f, 0.0f, 3.0f);
  m_cameraFront  = glm::vec3(0.0f, 0.0f, -1.0f);
  m_cameraUp      = glm::vec3(0.0f, 1.0f, 0.0f);
  m_cameraSpeed = 1.0;

  m_yaw                = -90.0f;
  m_pitch               = 0.0f;

  m_fov                  = 45.0f;
}

// get methods
// ---------------------------------------------------------------------------
glm::mat4
enCamera::getViewMatrix() const
{
  return glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);
}
// ---------------------------------------------------------------------------  

// set methods
// ---------------------------------------------------------------------------
void
enCamera::moveToIn()
{
  m_cameraPos += m_cameraSpeed * m_cameraFront;
}
// ---------------------------------------------------------------------------
void
enCamera::moveToout()
{
  m_cameraPos -= m_cameraSpeed * m_cameraFront;
}
// ---------------------------------------------------------------------------
void
enCamera::moveToLeft()
{
  m_cameraPos -= glm::normalize(glm::cross(m_cameraFront,
					   m_cameraUp)) * m_cameraSpeed;
}
// ---------------------------------------------------------------------------
void
enCamera::moveToRight()
{
  m_cameraPos += glm::normalize(glm::cross(m_cameraFront,
					   m_cameraUp)) * m_cameraSpeed;
}
// ---------------------------------------------------------------------------
void
enCamera::rotate(float xoffset, float yoffset)
{
  float sensitivity = 0.1f;
  xoffset *= sensitivity;
  yoffset *= sensitivity;
  
  m_yaw += xoffset;
  m_pitch += yoffset;

  if (m_pitch > 89.0f)  {
    m_pitch = 89.0f;
  }
  if (m_pitch < -89.0f) {
    m_pitch = -89.0f;
  }
  glm::vec3 front;
  front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
  front.y = sin(glm::radians(m_pitch));
  front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
  printf("x %f y %f z %f\n", front.x, front.y, front.z);
  m_cameraFront = glm::normalize(front);
}
// ---------------------------------------------------------------------------
void
enCamera::zoom(int delta)
{
  if (delta > 0) {
    m_fov += 1.0f;
  } else {
    m_fov -= 1.0f;
  }
}
// ---------------------------------------------------------------------------  


