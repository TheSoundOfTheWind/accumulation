#include <iostream>
#include "enEngine.h"

//"gl_Position = ftransform();\n"
//"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"gl_Position = projection*view*model*vec4(aPos,1.0f);\n"
const char * vertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"uniform mat4 clip;\n"
"void main()\n"
"{\n"
"gl_Position = clip*vec4(aPos,1.0f);\n"
"}\0";

const char * fragmentShaderSource = "#version 120\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
" gl_FragColor = ourColor;\n"
"}\n\0";
// Vertex Array Object, VAO
// Vertex Buffer Object, VBO
// Element Buffer Object, EBO/IBO

// -----------------------------------------------------------------------------

glm::vec3 cubePositions[] = {
  glm::vec3(0.0f, 0.0f, 0.0f),
  glm::vec3(2.0f, 5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f)
};
enEngine::enEngine()
{
  // make sure to initialize matrix to identity matrix first
  m_model         = glm::mat4(1.0f); 
  m_view          = glm::mat4(1.0f);
  m_projection    = glm::mat4(1.0f);
}

enEngine::~enEngine()
{

}

void
enEngine::init()
{
  if(!m_render.init()) {
    printf("-E- render init faild\n");
  }
  m_model = glm::rotate(m_model, glm::radians(-55.0f), glm::vec3(0.2f, 0.3f, 0.0f));
  m_view  = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
  m_projection = glm::perspective(glm::radians(45.0f), (float)m_width / (float)m_height, 0.1f, 100.0f);
  updateModel(m_model);
  updateView(m_view);
  updateProjection(m_projection);
  m_shaderProgramId = loadShaders(vertexShaderSource, fragmentShaderSource);
}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  glUseProgram(m_shaderProgramId);

  int vertexColorLocation = glGetUniformLocation(m_shaderProgramId, "ourColor");
  glUniform4f(vertexColorLocation, 0.0f, 0.3f, 0.0f, 1.0f);

  m_render.clean();


  for(unsigned int i = 0; i < 3; ++i)  {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, cubePositions[i]);
    updateModel(model);
    unsigned int clipLoc  = glGetUniformLocation(m_shaderProgramId, "clip");
    glUniformMatrix4fv(clipLoc, 1, GL_FALSE, glm::value_ptr(m_clip));
    float angle = 20.0f*i;
    m_render.render();
  }
}
// -----------------------------------------------------------------------------
void
enEngine::updateModel(glm::mat4 & mat)
{
  m_clip = m_projection*m_view*mat;
}
// -----------------------------------------------------------------------------
void
enEngine::updateView(glm::mat4 & mat)
{
  m_clip = m_projection*mat*m_model;
}
// -----------------------------------------------------------------------------
void
enEngine::updateProjection(glm::mat4 & mat)
{
  m_clip = mat*m_view*m_model;
}
// -----------------------------------------------------------------------------
GLuint
enEngine::loadShaders(const char * vertexShaderSource,
		                      const char * fragmentShaderSource)
{
  // build and compile our shader program
  // ------------------------------------
  // vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // check for shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
    {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
  // fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
    {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
  // link shaders
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}
//------------------------------------------------------------------------------
void
enEngine::setViewPort(int width, int height)
{
  m_width = width;
  m_height = height;
}
