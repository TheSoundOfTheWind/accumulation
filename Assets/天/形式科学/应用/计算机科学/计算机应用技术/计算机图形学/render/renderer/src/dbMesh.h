#ifndef ENMESH_H
#define ENMESH_H
#include <vector>
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>

using std::vector;

typedef struct Vertex {
  Vertex(const GLfloat & x, const GLfloat & y, const GLfloat & z) {
    vertex[0] = x;
    vertex[1] = y;
    vertex[2] = z;
  }
  GLfloat vertex[3];
  GLfloat normal[3];
} Vertex;

typedef struct Index {
  Index(const unsigned int & index0,
	const unsigned int & index1,
	const unsigned int & index2,
	const unsigned int & index3)
  {
    index[0] = index0;
    index[1] = index1;
    index[2] = index2;
    index[3] = index3;
  }
  unsigned int index[4];
} Index;

class dbMesh {
 public:
  dbMesh();
  virtual ~dbMesh();

 public:
  // get methods
  // ---------------------------------------------------------------------------
  const vector<Vertex>  & getVertices() { return m_vertices; }
  const vector<Index> &    getIndices() {  return m_indices; }
  // ---------------------------------------------------------------------------
  
  // set methods
  // ---------------------------------------------------------------------------
  void addCube(const GLfloat & x1, const GLfloat & y1, const GLfloat & z1,
	       const GLfloat & x2, const GLfloat & y2, const GLfloat & z2);
  void addCube(glm::vec3 & bottomLeft, glm::vec3 & bottomRight,
	                 glm::vec3 & topLeft, glm::vec3 & topRight);
  void addNormal();
  // ---------------------------------------------------------------------------
  
 private:
  vector<Vertex>  m_vertices;
  vector<Index>    m_indices;
};
#endif // ENMESH_H
