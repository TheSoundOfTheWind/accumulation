#ifndef ENENGINE_H
#define ENENGINE_H
#include <GLES3/gl3.h>
#include <QGLWidget>
//#include <gl.h>
//#include <glu.h>
//#include <glext.h>
//#include <glm.hpp>

class enEngine {
 public:
  enEngine() {};
  virtual ~enEngine() {};
  
  void init();
  void render();
  void setViewPort(int width, int height);
 private:
  GLuint loadShaders(const char * vertexShaderSource, const char * fragmentShaderSource);

 private:
  int          m_width;
  int          m_height;
  GLuint    m_vao;
  GLuint    m_vbo;
  GLuint    m_ibo;
  GLuint    m_shaderProgramId;
};
#endif
