#include <stdio.h>
#include "enRender.h"
unsigned int indices[] = {
  0, 1, 2, 3,
  4, 5, 6, 7,
  0, 3, 7, 4,
  0, 4, 5, 1,
  5, 1, 2, 6,
  6, 2, 3, 7
};

enRender::enRender()
{
  m_vao = 0;
  m_vbo = 0;
  m_ibo = 0;
}

enRender::~enRender()
{
  
}
// set methods
// ---------------------------------------------------------
bool
enRender::init()
{
  bool r_b = true;
  addCube(-0.5, -0.5, -0.5, 0.5, 0.5, 0.5);
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
  initOther();
  return r_b;
}
// ---------------------------------------------------------
bool
enRender::initVAO()
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
// ---------------------------------------------------------
bool
enRender::initVBO()
{
  bool r_b = true;
  GLint data = 0;
  float vertices[] = {
    -0.5f, 0.5f, -0.5f,
    0.5f, 0.5f, -0.5f, 
    0.5f,-0.5f, -0.5f, 
    -0.5f,  -0.5f, -0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f, 
    0.5f, -0.5f, 0.5f, 
    -0.5f,  -0.5f, 0.5f  
  }; 

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
  /*
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  */
  glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  printf("Vertex size %d\n", sizeof(Vertex));
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
  return r_b;
}
// ---------------------------------------------------------
bool
enRender::initIBO()
{
  bool r_b = true;
  GLint data = 0;
  unsigned int indices[] = {
    0, 1, 2, 3,
    4, 5, 6, 7,
    0, 3, 7, 4,
    0, 4, 5, 1,
    5, 1, 2, 6,
    6, 2, 3, 7
  };

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
  /*
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), 
	       indices, GL_STATIC_DRAW);
  */
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size()*sizeof(unsigned int), 
	       &m_indices[0], GL_STATIC_DRAW);
  return r_b;
}
// ---------------------------------------------------------
void 
enRender::initOther()
{
  // other
  glBindBuffer(GL_ARRAY_BUFFER, 0); 
  glBindVertexArray(0);
  glEnable(GL_DEPTH_TEST);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
// ---------------------------------------------------------
void 
enRender::clean()
{
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  // also clear the depth buffer now!
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //  glClear(GL_COLOR_BUFFER_BIT);
}
// ---------------------------------------------------------
void 
enRender::render()
{
  glBindVertexArray(m_vao);
  printf("indices size %d\n", m_indices.size());
  glDrawElements(GL_QUADS, m_indices.size(), GL_UNSIGNED_INT, 0);    
}
// add data
// -----------------------------------------------------------------------------
void
enRender::addCube(GLfloat x1, GLfloat y1, GLfloat z1,
	     GLfloat x2, GLfloat y2, GLfloat z2)
{
  if (x1 > x2 or y1 > y2 or z1 > z2) {
    printf("addCube faild\n");
    return;
  }
  unsigned int index = m_indices.size();

  // bottom
  m_vertices.push_back(Vertex(x1, y1, z1));
  m_vertices.push_back(Vertex(x1, y2, z1));
  m_vertices.push_back(Vertex(x2, y2, z1));
  m_vertices.push_back(Vertex(x2, y1, z1));
  m_indices.push_back(index);
  m_indices.push_back(index+1);
  m_indices.push_back(index+2);
  m_indices.push_back(index+3);  

  // top
  index += 4;  
  m_vertices.push_back(Vertex(x1, y1, z2));
  m_vertices.push_back(Vertex(x1, y2, z2));
  m_vertices.push_back(Vertex(x2, y2, z2));
  m_vertices.push_back(Vertex(x2, y1, z2));
  m_indices.push_back(index);
  m_indices.push_back(index+1);
  m_indices.push_back(index+2);
  m_indices.push_back(index+3);  

  // front
  index += 4;    
  m_vertices.push_back(Vertex(x1, y2, z1));
  m_vertices.push_back(Vertex(x1, y2, z2));
  m_vertices.push_back(Vertex(x2, y2, z2));
  m_vertices.push_back(Vertex(x2, y2, z1));
  m_indices.push_back(index);
  m_indices.push_back(index+1);
  m_indices.push_back(index+2);
  m_indices.push_back(index+3);  

  // back
  index += 4;      
  m_vertices.push_back(Vertex(x1, y1, z1));
  m_vertices.push_back(Vertex(x1, y1, z2));
  m_vertices.push_back(Vertex(x2, y1, z2));
  m_vertices.push_back(Vertex(x2, y1, z1));
  m_indices.push_back(index);
  m_indices.push_back(index+1);
  m_indices.push_back(index+2);
  m_indices.push_back(index+3);  

  // left
  index += 4;        
  m_vertices.push_back(Vertex(x1, y1, z1));
  m_vertices.push_back(Vertex(x1, y1, z2));
  m_vertices.push_back(Vertex(x1, y2, z2));
  m_vertices.push_back(Vertex(x1, y2, z1));
  m_indices.push_back(index);
  m_indices.push_back(index+1);
  m_indices.push_back(index+2);
  m_indices.push_back(index+3);  

  // right
  index += 4;          
  m_vertices.push_back(Vertex(x2, y1, z1));
  m_vertices.push_back(Vertex(x2, y1, z2));
  m_vertices.push_back(Vertex(x2, y2, z2));
  m_vertices.push_back(Vertex(x2, y2, z1));
  m_indices.push_back(index);
  m_indices.push_back(index+1);
  m_indices.push_back(index+2);
  m_indices.push_back(index+3);  

}  
// -----------------------------------------------------------------------------
void 
enRender::addNormal()
{
  
}
// -----------------------------------------------------------------------------
