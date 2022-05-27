#include <iostream>
#include "enEngine.h"

// Vertex Array Object, VAO
// Vertex Buffer Object, VBO
// Element Buffer Object, EBO/IBO

// -----------------------------------------------------------------------------

glm::vec3 cubePositions[] = {
  glm::vec3(0.0f, 0.0f, 0.0f),
  glm::vec3(2.0f, 5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f)
};
enEngine::enEngine()
{
  // make sure to initialize matrix to identity matrix first
  m_model          = glm::mat4(1.0f); 
  m_view             = glm::mat4(1.0f);
  m_projection     = glm::mat4(1.0f);
  m_clip               = m_model*m_view*m_model;  

  m_cameraPos    = glm::vec3(0.0f, 0.0f, 3.0f);
  m_cameraFront  = glm::vec3(0.0f, 0.0f, -1.0f);
  m_cameraUp      = glm::vec3(0.0f, 1.0f, 0.0f);
  m_cameraSpeed = 1.0;

  m_yaw                = -90.0f;
  m_pitch               = 0.0f;
  m_fov                  = 45.0f;
}

enEngine::~enEngine()
{

}

void
enEngine::init()
{
  if(!m_render.init()) {
    printf("-E- render init faild\n");
  }
  m_model = glm::rotate(m_model, glm::radians(-55.0f), glm::vec3(0.2f, 0.3f, 0.0f));
  updateModel(m_model);

  //  m_view  = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
  m_view = glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);
  updateView(m_view);

  m_projection = glm::perspective(glm::radians(m_fov), (float)m_width / (float)m_height, 0.1f, 100.0f);
  updateProjection(m_projection);
  m_shader.init();
}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  m_shader.use();
  int vertexColorLocation = glGetUniformLocation(m_shader.getShaderId(), "ourColor");
  glUniform4f(vertexColorLocation, 0.0f, 0.3f, 0.0f, 1.0f);
  m_view = glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);
  updateView(m_view);
  m_projection = glm::perspective(glm::radians(m_fov), (float)m_width / (float)m_height, 0.1f, 100.0f);
  updateProjection(m_projection);
  m_render.clean();

  for(unsigned int i = 0; i < 3; ++i)  {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, cubePositions[i]);
    updateModel(model);
    unsigned int clipLoc  = glGetUniformLocation(m_shader.getShaderId(), "clip");
    glUniformMatrix4fv(clipLoc, 1, GL_FALSE, glm::value_ptr(m_clip));
    float angle = 20.0f*i;
    m_render.render();
  }
}
//------------------------------------------------------------------------------
void
enEngine::setViewPort(int width, int height)
{
  m_width = width;
  m_height = height;
}
// -----------------------------------------------------------------------------
void
enEngine::updateModel(glm::mat4 & mat)
{
  m_clip = m_projection*m_view*mat;
}
// -----------------------------------------------------------------------------
void
enEngine::updateView(glm::mat4 & mat)
{
  m_clip = m_projection*mat*m_model;
}
// -----------------------------------------------------------------------------
void
enEngine::updateProjection(glm::mat4 & mat)
{
  m_clip = mat*m_view*m_model;
}
//------------------------------------------------------------------------------
void
enEngine::pressW()
{
  m_cameraPos += m_cameraSpeed * m_cameraFront;
}
//------------------------------------------------------------------------------
void
enEngine::pressS()
{
  m_cameraPos -= m_cameraSpeed * m_cameraFront;
}
//------------------------------------------------------------------------------
void
enEngine::pressA()
{
  m_cameraPos -= glm::normalize(glm::cross(m_cameraFront,
					   m_cameraUp)) * m_cameraSpeed;
}
//------------------------------------------------------------------------------
void
enEngine::pressD()
{
  m_cameraPos += glm::normalize(glm::cross(m_cameraFront,
					   m_cameraUp)) * m_cameraSpeed;
}
//------------------------------------------------------------------------------
void
enEngine::moveMouse(float xoffset, float yoffset)
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
  m_cameraFront = glm::normalize(front);
}
//------------------------------------------------------------------------------
void
enEngine::moveWheel(int delta)
{
  if (delta > 0) {
    m_fov += 1.0f;
  } else {
    m_fov -= 1.0f;
  }
}
