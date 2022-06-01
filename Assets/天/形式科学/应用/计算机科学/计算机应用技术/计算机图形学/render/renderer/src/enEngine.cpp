#include <iostream>
#include "enEngine.h"

// -----------------------------------------------------------------------------
enEngine::enEngine()
{

}
// -----------------------------------------------------------------------------
enEngine::~enEngine()
{

}
// -----------------------------------------------------------------------------
void
enEngine::init()
{
  printf("init()\n");
  if(!m_render.init()) {
    printf("-E- render init faild\n");
  }
}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  m_render.clean();
  enShader & shader = m_render.shader();
  glm::vec3 lightPos(0.7f, -0.7f, 0.7f);
  glm::vec3 cubePos(-0.5f, 0.5f, -0.5f);
  shader.use();    

  shader.setVec3("lightPos", lightPos);
  shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
  glm::mat4 view = m_camera.getViewMatrix();
  shader.updateView(view);
  glm::mat4 projection = glm::perspective(glm::radians(m_camera.zoom()), (float)m_width / (float)m_height, 0.1f, 100.0f);
  shader.updateProjection(projection);
  m_render.render();  
}
//------------------------------------------------------------------------------
void
enEngine::setViewPort(int width, int height)
{
  m_width = width;
  m_height = height;
}
//------------------------------------------------------------------------------
