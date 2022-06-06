#ifndef DBBOX_H
#define DBBOX_H
#include <glm/glm.hpp>

class dbBox {
 public:
  dbBox(const glm::vec3 & bl, const glm::vec3 & tr);
  virtual ~dbBox();
  
 private:
  glm::vec3 m_bl;
  glm::vec3 m_tr;
};
#endif // DBBOX_H
