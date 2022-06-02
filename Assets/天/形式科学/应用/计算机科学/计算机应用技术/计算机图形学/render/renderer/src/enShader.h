#ifndef ENSHADER_H
#define ENSHADER_H
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class enShader {
 public:
  enShader();
  virtual ~enShader();

  // set methods
  // ---------------------------------------------------------------------------
  void init(); 
  void use();
  void setVec3(const GLchar * name, glm::vec3 & vec);  
  void setVec3(const GLchar * name, GLfloat v0, GLfloat v1, GLfloat v2);
  void setMat4(const GLchar * name, glm::mat4 & mat);
  void updateModel(glm::mat4 & mat);
  void updateView(glm::mat4 & mat);
  void updateProjection(glm::mat4 & mat);

 private:
  GLuint loadShaders(const char * vertexShaderSource, const char * fragmentShaderSource);
  // ---------------------------------------------------------------------------  

 private:
  GLuint          m_shaderProgramId;
  glm::mat4    m_model;
  glm::mat4    m_view;
  glm::mat4    m_projection;
  glm::mat4    m_clip;
};
#endif // ENSHADER_H
