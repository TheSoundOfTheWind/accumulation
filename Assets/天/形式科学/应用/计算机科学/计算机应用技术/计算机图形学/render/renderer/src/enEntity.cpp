#include "enEntity.h"
// -----------------------------------------------------------------------------
enEntity::enEntity()
{
  m_visual = true;
}
// -----------------------------------------------------------------------------
enEntity::~enEntity()
{

}
// set methods
// -----------------------------------------------------------------------------
bool
enEntity::init()
{
  bool r_b = true;
  if (!initVAO()) {
    printf("-E- init VAO faild\n");
    r_b = false;
  }
  if (!initVBO()) {
    printf("-E- init VBO faild\n");
    r_b = false;
  }
  if (!initIBO()) {
    printf("-E- init IBO faild\n");
    r_b = false;
  }
  return r_b;
}
// -----------------------------------------------------------------------------
bool
enEntity::initVAO()
{
  bool r_b = true;
  GLint data = 0;    
  glGenVertexArrays(1, &m_vao);
  if (0 == m_vao) {
    printf("-E- Failed to generate VAO\n");
    r_b = false;
  }
  glBindVertexArray(m_vao);
  glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &data);
  if (data != m_vao) {
    printf("-E- Failed to bind VAO\n");
    r_b = false;
  }
  return r_b;
}
// -----------------------------------------------------------------------------
bool
enEntity::initVBO()
{
  bool r_b = true;
  GLint data = 0;
  glGenBuffers(1, &m_vbo);
  if (0 == m_vbo) {
    printf("-E- Failed to generate VBO\n");
    r_b = false;
  }
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &data);
  if (data != m_vbo) {
    printf("-E- Failed to bind VBO\n");
    r_b = false;
  }
  glBufferData(GL_ARRAY_BUFFER,
	       m_mesh->getVertices().size()*sizeof(Vertex),
	       &m_mesh->getVertices()[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
  return r_b;
}
// -----------------------------------------------------------------------------
bool
enEntity::initIBO()
{
  bool r_b = true;
  GLint data = 0;
  glGenBuffers(1, &m_ibo);
  if (0 == m_ibo) {
    printf("-E- Failed to generate IBO\n");
    r_b = false;
  }
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
  glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &data);
  if (data != m_ibo) {
    printf("Failed to bind IBO");
    r_b = false;
  }
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
	       m_mesh->getIndices().size()*sizeof(Index), 
	       &m_mesh->getIndices()[0], GL_STATIC_DRAW);
  return r_b;
}
// -----------------------------------------------------------------------------
void
enEntity::render()
{
  if (m_visual) {
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(m_vao);
    glDrawElements(GL_QUADS, m_mesh->getIndices().size()*4, GL_UNSIGNED_INT, 0);
  }
}
// -----------------------------------------------------------------------------
