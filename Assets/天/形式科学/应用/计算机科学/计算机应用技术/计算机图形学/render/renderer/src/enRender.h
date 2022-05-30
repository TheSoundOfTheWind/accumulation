#ifndef ENRENDER_H
#define ENRENDER_H
#include <vector>
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using std::vector;

typedef struct Vertex {
  GLfloat vertex[3];
  GLfloat normal[3];
} Vertex;

typedef struct Index {
  GLushort index[4];
} Index;

class enRender {
 public:
  enRender();
  virtual ~enRender();
  
  // set methods
  // ---------------------------------------------------------
  bool init();
  void clean();
  void render();

  // add data
  void addCube(GLfloat x1, GLfloat y1, GLfloat z1,
	                 GLfloat x2, GLfloat y2, GLfloat z2);
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

  vector<Vertex> m_vertices;
  vector<Index>   m_indices;
};
#endif // ENRENDER_H
