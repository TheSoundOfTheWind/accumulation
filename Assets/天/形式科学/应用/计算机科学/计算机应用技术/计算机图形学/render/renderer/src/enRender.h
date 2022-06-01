#ifndef ENRENDER_H
#define ENRENDER_H
#include <vector>
#include <QGLWidget>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "enEntity.h"
#include "enShader.h"

using std::vector;

class enRender {
 public:
  enRender();
  virtual ~enRender();

  // set methods
  // ---------------------------------------------------------
  bool init();
  void clean();
  void render();
  enShader & shader() { return m_shader; }
  // ---------------------------------------------------------

 private:
  enShader                m_shader;
  vector<enEntity *> m_renderObjects;
};
#endif // ENRENDER_H
