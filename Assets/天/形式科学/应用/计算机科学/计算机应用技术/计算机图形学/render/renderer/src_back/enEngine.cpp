#include <GL/glu.h>
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

}

enEngine::~enEngine()
{

}

void
enEngine::init()
{
  printf("init()\n");
  if(!m_render.init()) {
    printf("-E- render init faild\n");
  }

  m_cubeShader.init(enShader::Cube);
  m_lightShader.init(enShader::Light);
}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  m_render.clean();  

  m_cubeShader.use();    
  m_cubeShader.setVec3("objectColor", 0.0f, 0.3f, 0.0f);
  /*
  glColor4f(0.0f, 0.3f, 0.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glm::mat4 projection = glm::perspective(glm::radians(m_camera.zoom()), (float)m_width / (float)m_height, 0.1f, 100.0f);  
  glLoadMatrixf(glm::value_ptr(projection));
  
  glMatrixMode(GL_MODELVIEW);
  glm::mat4 view = m_camera.getViewMatrix();
  glLoadMatrixf(glm::value_ptr(view));  
  */

  glm::mat4 view = m_camera.getViewMatrix();
  m_cubeShader.updateView(view);

  glm::mat4 projection = glm::perspective(glm::radians(m_camera.zoom()), (float)m_width / (float)m_height, 0.1f, 100.0f);  
  m_cubeShader.updateProjection(projection);

  glm::mat4 model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 1.0f, 1.0f));
  m_cubeShader.updateModel(model);  

  m_render.render();
  /*
  m_lightShader.use();  
  m_lightShader.updateView(view);
  m_lightShader.updateProjection(projection);  
  glm::vec3 lightPos(0.7f, 0.7f, 0.7f);
  model = glm::mat4(1.0f);
  model = glm::translate(model, lightPos);
  model = glm::scale(model, glm::vec3(0.2f));
  m_lightShader.updateModel(model);
  m_render.render();  
  */
}
//------------------------------------------------------------------------------
void
enEngine::setViewPort(int width, int height)
{
  m_width = width;
  m_height = height;
}
