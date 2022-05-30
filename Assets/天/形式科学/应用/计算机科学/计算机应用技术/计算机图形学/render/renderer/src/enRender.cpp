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
  glDrawElements(GL_POLYGON, 24, GL_UNSIGNED_INT, 0);    
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
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  
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
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), 
	       indices, GL_STATIC_DRAW);
  
  return r_b;
}
// ---------------------------------------------------------
void 
enRender::initOther()
{
  // other
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0); 
  glBindVertexArray(0);
  glEnable(GL_DEPTH_TEST);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
