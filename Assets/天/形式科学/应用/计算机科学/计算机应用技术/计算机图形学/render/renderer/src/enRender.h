#ifndef ENRENDER_H
#define ENRENDER_H
#include <QGLWidget>
#include <GLES3/gl3.h>
class enRender {
 public:
  enRender();
  virtual ~enRender();
  
  // set methods
  // ---------------------------------------------------------
  bool init();
  void clean();
  void render();
 private:
  bool initVAO();
  bool initVBO();
  bool initIBO();
  void initOther();
  // ---------------------------------------------------------

 private:
  GLuint       m_vao;
  GLuint       m_vbo;
  GLuint       m_ibo;
};
#endif // ENRENDER_H
