#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
void
enEngine::init()
{
  /*
    float vertices[] = {
      0.5f, 0.5f, 0.0f,
      0.5f, -0.5f, 0.0f, 
      -0.5f, -0.5f, 0.0f, 
      -0.5f,  0.5f, 0.0f  
    }; 

    unsigned int indices[] = {
      0, 1, 2, 3
    };
  */

  float vertices[] = {
      -0.5f, 0.5f, -0.5f,
      0.5f, 0.5f, -0.5f, 
      0.5f, -0.5f, -0.5f, 
      -0.5f,  -0.5f, -0.5f,
      -0.5f, 0.5f, 0.5f,
      0.5f, 0.5f, 0.5f, 
      0.5f, -0.5f, 0.5f, 
      -0.5f,  -0.5f, 0.5f  
    }; 

    unsigned int indices[] = {
      0, 1, 2, 3,
      4, 5, 6, 7,
      0, 3, 7, 4,
      0, 4, 5, 1,
      5, 1, 2, 6,
      6, 2, 3, 7
    };
  
    GLint data = 0;    

    // VAO
    glGenVertexArrays(1, &m_vao);
    if (0 == m_vao) {
      printf("-E- Failed to generate VAO\n");
    }
    glBindVertexArray(m_vao);
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &data);
    if (data != m_vao) {
      printf("-E- Failed to bind VAO\n");
    }

    // VBO 
    glGenBuffers(1, &m_vbo);
    if (0 == m_vbo) {
      printf("-E- Failed to generate VBO\n");
    }
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &data);
    if (data != m_vbo) {
      printf("-E- Failed to bind VBO\n");
    }
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // IBO / EBO
    glGenBuffers(1, &m_ibo);
    if (0 == m_ibo) {
      printf("-E- Failed to generate IBO\n");
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &data);
    if (data != m_ibo) {
      printf("Failed to bind IBO");
    }
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // other
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
    glEnable(GL_DEPTH_TEST);

    //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    m_shaderProgramId = loadShaders(vertexShaderSource, fragmentShaderSource);

}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  // also clear the depth buffer now!
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(m_shaderProgramId);
  glBindVertexArray(m_vao); 

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
  unsigned int modelLoc = glGetUniformLocation(m_shaderProgramId, "model");
  unsigned int viewLoc  = glGetUniformLocation(m_shaderProgramId, "view");
  unsigned int projectionLoc  = glGetUniformLocation(m_shaderProgramId, "projection");
  // pass them to the shaders (3 different ways)
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
  // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
  //  ourShader.setMat4("projection", projection);
  glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));  
  //  glDrawArrays(GL_TRIANGLES, 0, 3);
  // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glDrawElements(GL_POLYGON, 24, GL_UNSIGNED_INT, 0);
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
