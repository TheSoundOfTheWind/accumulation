#include <stdio.h>
#include "enRender.h"

enRender::enRender()
{
  m_scale = 1.0f;
  m_centerCoord = glm::vec3(0.0f, 0.0f, 0.0f);
  m_renderObjects.clear();
}
// -----------------------------------------------------------------------------
enRender::~enRender()
{
  
}
// -----------------------------------------------------------------------------
bool
enRender::init()
{
  m_shader.init();

  enEntity * entity1 = new enEntity();
  dbMesh * mesh1 = new dbMesh();
  //  mesh1->addCube(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f);
  // mesh1->addCube(-5.0f, -5.0f, -5.0f, 0.0f, 0.0f, 0.0f);
  mesh1->addCube(-5.0f, -5.0f, -5.0f, 0.0f, 0.0f, 0.0f);
  entity1->setMesh(mesh1);
  //entity1->setModelCoord(-0.25f, -0.25f, -0.25f);
  entity1->setColor(QColor("red"));
  entity1->init();
  //  entity1->setVisual(false);
  m_renderObjects.push_back(entity1);
  m_scale = 1.5;
  m_centerCoord = glm::vec3(2.5f, 2.5f, 2.5f);
  /*
  enEntity * entity2 = new enEntity();
  dbMesh * mesh2 = new dbMesh();
  mesh2->addCube(0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f);
  entity2->setMesh(mesh2);
  //  entity2->setModelCoord(0.25f, 0.25f, 0.25f);
  entity2->setColor(QColor("green"));
  entity2->init();
  m_renderObjects.push_back(entity2);
  */
  /*
  enEntity * entity1 = new enEntity();
  dbMesh * mesh1 = new dbMesh();
  glm::vec3 bl(-0.7, -0.5, -0.5);
  glm::vec3 br(0.7, 0.5, -0.5);
  glm::vec3 tl(-0.4, -0.3, 0.5);
  glm::vec3 tr(0.4, 0.3, 0.5);
  mesh1->addCube(bl, br, tl, tr);
  entity1->setMesh(mesh1);
  //entity1->setModelCoord(-0.25f, -0.25f, -0.25f);
  entity1->setColor(QColor("green"));
  entity1->init();
  m_renderObjects.push_back(entity1);
  */
  glEnable(GL_DEPTH_TEST);
  return true;
}
// -----------------------------------------------------------------------------
void 
enRender::clean()
{
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  // also clear the depth buffer now!
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
// -----------------------------------------------------------------------------
void 
enRender::render()
{
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::scale(model, glm::vec3(m_scale, m_scale, m_scale));
  model = glm::translate(model, m_centerCoord);
  for (auto & entity : m_renderObjects) {
    // set model cooord

    //    model = glm::translate(model, entity->getModelCoord());
    m_shader.updateModel(model);
    // set color
    const QColor & color = entity->getColor();
    m_shader.setVec3("objectColor",
		     color.redF(), color.greenF(), color.blueF());
    entity->render();
  } // for
}
// -----------------------------------------------------------------------------
glm::vec3
enRender::updateCenterCoord()
{
  
}
// -----------------------------------------------------------------------------
float
enRender::updateScale()
{

}
// -----------------------------------------------------------------------------
