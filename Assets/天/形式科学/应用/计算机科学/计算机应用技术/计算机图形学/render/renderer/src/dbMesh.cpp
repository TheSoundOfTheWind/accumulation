#include <math.h>
#include "dbMesh.h"
dbMesh::dbMesh()
{

}

dbMesh::~dbMesh()
{

}

// set methods
// ---------------------------------------------------------------------------
// add data
void
dbMesh::addCube(const GLfloat & x1, const GLfloat & y1, const GLfloat & z1,
		const GLfloat & x2, const GLfloat & y2, const GLfloat & z2)
{
  if (x1 > x2 or y1 > y2 or z1 > z2) {
    printf("addCube faild\n");
    return;
  }
  unsigned int index = m_indices.size();
  // top
  m_vertices.push_back(Vertex(x1, y1, z2));
  m_vertices.push_back(Vertex(x1, y2, z2));
  m_vertices.push_back(Vertex(x2, y2, z2));
  m_vertices.push_back(Vertex(x2, y1, z2));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // bottom
  index += 4;  
  m_vertices.push_back(Vertex(x1, y1, z1));
  m_vertices.push_back(Vertex(x2, y1, z1));
  m_vertices.push_back(Vertex(x2, y2, z1));
  m_vertices.push_back(Vertex(x1, y2, z1));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // front
  index += 4;      
  m_vertices.push_back(Vertex(x1, y1, z1));
  m_vertices.push_back(Vertex(x1, y1, z2));
  m_vertices.push_back(Vertex(x2, y1, z2));
  m_vertices.push_back(Vertex(x2, y1, z1));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  
  
  // back
  index += 4;    
  m_vertices.push_back(Vertex(x1, y2, z1));
  m_vertices.push_back(Vertex(x2, y2, z1));
  m_vertices.push_back(Vertex(x2, y2, z2));
  m_vertices.push_back(Vertex(x1, y2, z2));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // left
  index += 4;        
  m_vertices.push_back(Vertex(x1, y1, z1));
  m_vertices.push_back(Vertex(x1, y2, z1));
  m_vertices.push_back(Vertex(x1, y2, z2));
  m_vertices.push_back(Vertex(x1, y1, z2));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // right
  index += 4;          
  m_vertices.push_back(Vertex(x2, y1, z1));
  m_vertices.push_back(Vertex(x2, y1, z2));
  m_vertices.push_back(Vertex(x2, y2, z2));
  m_vertices.push_back(Vertex(x2, y2, z1));
  m_indices.push_back(Index(index, index+1, index+2, index+3));

  addNormal();
}
void
dbMesh::addCube(glm::vec3 & bl, glm::vec3 & br,
   	glm::vec3 & tl, glm::vec3 & tr)
{
  if (bl.x > br.x or bl.y > br.y or bl.z > tl.z or
      tl.x > tr.x or tl.y > tr.y or br.z > tr.z) {
    printf("addCube faild\n");
    return;
  }
  unsigned int index = m_indices.size();
  // top
  m_vertices.push_back(Vertex(tl.x, tl.y, tl.z));
  m_vertices.push_back(Vertex(tl.x, tr.y, tl.z));
  m_vertices.push_back(Vertex(tr.x, tr.y, tl.z));
  m_vertices.push_back(Vertex(tr.x, tl.y, tl.z));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // bottom
  index += 4;  
  m_vertices.push_back(Vertex(bl.x, bl.y, bl.z));
  m_vertices.push_back(Vertex(br.x, bl.y, bl.z));
  m_vertices.push_back(Vertex(br.x, br.y, bl.z));
  m_vertices.push_back(Vertex(bl.x, br.y, bl.z));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // front
  index += 4;    
  m_vertices.push_back(Vertex(bl.x, bl.y, bl.z));
  m_vertices.push_back(Vertex(tl.x, tl.y, tl.z));
  m_vertices.push_back(Vertex(tr.x, tl.y, tl.z));
  m_vertices.push_back(Vertex(br.x, bl.y, bl.z));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // back
  index += 4;      
  m_vertices.push_back(Vertex(bl.x, br.y, bl.z));
  m_vertices.push_back(Vertex(br.x, br.y, bl.z));
  m_vertices.push_back(Vertex(tr.x, tr.y, tl.z));
  m_vertices.push_back(Vertex(tl.x, tr.y, tl.z));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // left
  index += 4;        
  m_vertices.push_back(Vertex(bl.x, bl.y, bl.z));
  m_vertices.push_back(Vertex(bl.x, br.y, bl.z));
  m_vertices.push_back(Vertex(tl.x, tr.y, tl.z));
  m_vertices.push_back(Vertex(tl.x, tl.y, tl.z));
  m_indices.push_back(Index(index, index+1, index+2, index+3));  

  // right
  index += 4;          
  m_vertices.push_back(Vertex(br.x, br.y, bl.z));
  m_vertices.push_back(Vertex(br.x, bl.y, bl.z));
  m_vertices.push_back(Vertex(tr.x, tl.y, tl.z));
  m_vertices.push_back(Vertex(tr.x, tr.y, tl.z));
  m_indices.push_back(Index(index, index+1, index+2, index+3));

  addNormal();
}

// ---------------------------------------------------------------------------
void
dbMesh::addNormal()
{
  float nx, ny, nz;
  float dx1, dy1, dz1;
  float dx2, dy2, dz2;
  float l;
  for (auto & id : m_indices) {
    dx1 = m_vertices[id.index[2]].vertex[0]-m_vertices[id.index[1]].vertex[0];
    dy1 = m_vertices[id.index[2]].vertex[1]-m_vertices[id.index[1]].vertex[1];
    dz1 = m_vertices[id.index[2]].vertex[2]-m_vertices[id.index[1]].vertex[2];
    dx2 = m_vertices[id.index[2]].vertex[0]-m_vertices[id.index[0]].vertex[0];
    dy2 = m_vertices[id.index[2]].vertex[1]-m_vertices[id.index[0]].vertex[1];
    dz2 = m_vertices[id.index[2]].vertex[2]-m_vertices[id.index[0]].vertex[2];
    nx = dy1*dz2 - dz1*dy2;
    ny = dz1*dx2 - dx1*dz2;
    nz = dx1*dy2 - dy1*dx2;
    l = sqrt(nx*nx + ny*ny + nz*nz);
    nx = nx / l; ny = ny / l; nz = nz / l;
    
    m_vertices[id.index[0]].normal[0] = nx;
    m_vertices[id.index[0]].normal[1] = ny;
    m_vertices[id.index[0]].normal[2] = nz;

    m_vertices[id.index[1]].normal[0] = nx;
    m_vertices[id.index[1]].normal[1] = ny;
    m_vertices[id.index[1]].normal[2] = nz;

    m_vertices[id.index[2]].normal[0] = nx;
    m_vertices[id.index[2]].normal[1] = ny;
    m_vertices[id.index[2]].normal[2] = nz;

    m_vertices[id.index[3]].normal[0] = nx;
    m_vertices[id.index[3]].normal[1] = ny;
    m_vertices[id.index[3]].normal[2] = nz;
  }// for
}
// ---------------------------------------------------------------------------
