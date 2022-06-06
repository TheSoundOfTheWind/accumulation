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

  shader.use();    

  shader.setVec3("lightPos", camera().cameraPos());
  shader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

  glm::mat4 view = m_camera.getViewMatrix();
  shader.updateView(view);

  glm::mat4 projection = glm::perspective(glm::radians(m_camera.zoom()), (float)m_width / (float)m_height, 0.1f, 1000.0f);
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
