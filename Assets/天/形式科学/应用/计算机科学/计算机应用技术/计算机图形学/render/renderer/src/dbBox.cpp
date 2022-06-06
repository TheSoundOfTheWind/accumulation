#include "dbBox.h"

dbBox::dbBox(const glm::vec3 & bl, const glm::vec3 & tr)
{
  m_bl = bl;
  m_tr = tr;
}

dbBox::~dbBox()
{

}
