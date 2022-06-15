#include "enCamera.h"
enCamera::enCamera()
{
  m_cameraPos         = glm::vec3(0.0f, 0.0f, 20.0f);
  m_cameraTarget     = glm::vec3(0.0f, 0.0f, 0.0f);
  m_cameraDirection = glm::normalize(m_cameraPos - m_cameraTarget);
  glm::vec3 up           = glm::vec3(0.0f, 1.0f, 0.0f);
  m_cameraRight       = glm::normalize(glm::cross(up, m_cameraDirection));
  m_cameraUp           = glm::cross(m_cameraDirection, m_cameraRight);
  m_cameraFront       = glm::vec3(0.0f, 0.0f, -1.0f);
  m_viewMatrix          =  glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);  
  m_cameraSpeed = 1.0;

  m_fov                  = 45.0f;
}

enCamera::~enCamera()
{
  m_cameraPos         = glm::vec3(0.0f, 0.0f, 3.0f);
  m_cameraTarget     = glm::vec3(0.0f, 0.0f, 0.0f);
  m_cameraDirection = glm::normalize(m_cameraPos - m_cameraTarget);
  glm::vec3 up           = glm::vec3(0.0f, 1.0f, 0.0f);
  m_cameraRight       = glm::normalize(glm::cross(up, m_cameraDirection));
  m_cameraUp           = glm::cross(m_cameraDirection, m_cameraRight);
  
  m_cameraSpeed = 1.0;
  
  m_fov                  = 45.0f;
}

// get methods
// ---------------------------------------------------------------------------
glm::mat4
enCamera::getViewMatrix()
{
  //return glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);
  return m_viewMatrix;
}
// ---------------------------------------------------------------------------  

// set methods
// ---------------------------------------------------------------------------
void
enCamera::moveToIn()
{
  //  m_cameraPos += m_cameraSpeed * m_cameraFront;
}
// ---------------------------------------------------------------------------
void
enCamera::moveToOut()
{
  //  m_cameraPos -= m_cameraSpeed * m_cameraFront;
}
// ---------------------------------------------------------------------------
void
enCamera::moveToLeft()
{
  //  m_cameraPos -=  m_cameraRight * m_cameraSpeed;
}
// ---------------------------------------------------------------------------
void
enCamera::moveToRight()
{
  m_cameraPos += m_cameraRight * m_cameraSpeed;
}
void
enCamera::zoom(int delta)
{
  if (delta > 0) {
    m_fov += 1.0f;
  } else {
    m_fov -= 1.0f;
  }
}
// Processes input received from a mouse input system.
// -----------------------------------------------------------------------------
void
enCamera::processMouseMovement(glm::vec2 prevMouse, glm::vec2 curMouse)
{
  glm::vec3 p1 = screen_to_arcball( curMouse );
  glm::vec3 p2 = screen_to_arcball( prevMouse );
    
  // Rotate arcball to camera coordinates
  p1 = glm::vec3( glm::inverse(m_viewMatrix) * glm::vec4(p1, 0.0));
  p2 = glm::vec3( glm::inverse(m_viewMatrix) * glm::vec4(p2, 0.0));
    
  glm::vec3 axis = glm::cross(p1, p2);

  float angle = std::acos(glm::dot(p1,p2));

  if ( angle > 0.001f)
    {
      // Rotate
      m_cameraPos = rotate_axis_angle(m_cameraPos, axis, angle);
      m_cameraFront = rotate_axis_angle(m_cameraFront, axis, angle);
      m_cameraUp = rotate_axis_angle(m_cameraUp, axis, angle);

      m_viewMatrix =glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);  
    }
}
// -----------------------------------------------------------------------------
// Get Arcball coordinates from screen
glm::vec3
enCamera::screen_to_arcball(const glm::vec2 &p)
{
  const float dist = glm::dot(p, p);
  if (dist < 0.999f) 
    {
      // If we're on/in the sphere return the point on it
      return glm::vec3(p.x, p.y, std::sqrt(1.f - dist));
    } 
  else 
    {
      // otherwise we project the point onto the sphere
      const glm::vec2 proj = glm::normalize(p);
      return glm::vec3(proj.x, proj.y, 0.f);
    }
}
// -----------------------------------------------------------------------------
// Rotate vector given (angle,axis) using Rodrigues' formula
glm::vec3
enCamera::rotate_axis_angle(glm:: vec3 &vec, glm:: vec3 axis, float angle)
{
  axis = glm::normalize(axis);
  glm::vec3 cross_axis = glm::cross(axis, vec);
  vec = vec * std::cos(angle) + axis * glm::dot(axis,vec) * (1.0f - std::cos(angle)) + cross_axis * std::sin(angle); 
  return vec;
}
// -----------------------------------------------------------------------------
