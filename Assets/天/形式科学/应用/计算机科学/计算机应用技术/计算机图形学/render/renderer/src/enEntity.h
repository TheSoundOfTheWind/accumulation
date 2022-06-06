#ifndef ENENTITY_H
#define ENENTITY_H
#include <QColor>
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "dbMesh.h"

// Vertex Array Object, VAO
// Vertex Buffer Object, VBO
// Element Buffer Object, EBO/IBO

class enEntity {
 public:
  enEntity();
  virtual ~enEntity();

  // get methods
  // ---------------------------------------------------------------------------
  const glm::vec3 & getModelCoord() const { return m_modelCoord; }
  const QColor &     getColor() const { return m_color; }
  // ---------------------------------------------------------------------------

  // set methods
  // ---------------------------------------------------------------------------
  bool init();
  void setMesh(dbMesh * mesh) { m_mesh = mesh; }
  void setModelCoord(const GLfloat & x,
		    const GLfloat & y,
		    const GLfloat & z) { m_modelCoord = glm::vec3(x, y, z); };
  void setColor(const QColor & color) { m_color = color; };
  void render();
  void setVisual(const bool & visual) { m_visual = visual; }
 private:
  bool initVAO();
  bool initVBO();
  bool initIBO();
  // ---------------------------------------------------------------------------  
  
 private:
  dbMesh *      m_mesh;
  glm::vec3     m_modelCoord;
  QColor         m_color;
  GLuint          m_vao;
  GLuint          m_vbo;
  GLuint          m_ibo;
  bool             m_visual;
};
#endif // ENENTITY_H
