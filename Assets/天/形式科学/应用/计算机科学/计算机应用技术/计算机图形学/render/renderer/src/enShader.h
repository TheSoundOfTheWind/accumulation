#ifndef ENSHADER_H
#define ENSHADER_H
#include <QGLWidget>
#include <GLES3/gl3.h>
class enShader {
 public:
  enShader();
  virtual ~enShader();
  // get methods
  // ---------------------------------------------------------------------------
  GLuint  getShaderId() const { return m_shaderProgramId; }
  // ---------------------------------------------------------------------------
  
  // set methods
  // ---------------------------------------------------------------------------
  void init();
  void use();

 private:
  GLuint loadShaders(const char * vertexShaderSource, const char * fragmentShaderSource);
  // ---------------------------------------------------------------------------  

 private:
  GLuint       m_shaderProgramId;  
};
#endif // ENSHADER_H
