#include <iostream>
#include "enEngine.h"

//"gl_Position = ftransform();\n"
//"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
const char * vertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"gl_Position = projection*view*model*vec4(aPos,1.0f);\n"
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

void
enEngine::init()
{
  if(!m_render.init()) {
    printf("-E- render init faild\n");
  }
  m_shaderProgramId = loadShaders(vertexShaderSource, fragmentShaderSource);
}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  glUseProgram(m_shaderProgramId);

  int vertexColorLocation = glGetUniformLocation(m_shaderProgramId, "ourColor");
  glUniform4f(vertexColorLocation, 0.0f, 0.3f, 0.0f, 1.0f);
    // create transformations
  glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
  glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);
  model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(0.2f, 0.3f, 0.0f));
  view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
  projection = glm::perspective(glm::radians(45.0f), (float)m_width / (float)m_height, 0.1f, 100.0f);
  // retrieve the matrix uniform locations

  unsigned int viewLoc  = glGetUniformLocation(m_shaderProgramId, "view");
  unsigned int projectionLoc  = glGetUniformLocation(m_shaderProgramId, "projection");
  // pass them to the shaders (3 different ways)

  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
  //  ourShader.setMat4("projection", projection);
  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
  m_render.clean();
  for(unsigned int i = 0; i < 3; ++i)  {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, cubePositions[i]);
    float angle = 20.0f*i;
    unsigned int modelLoc = glGetUniformLocation(m_shaderProgramId, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));    
    m_render.render();
  }
  
  //  glDrawArrays(GL_TRIANGLES, 0, 3);
  // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
