#include <iostream>
#include "enEngine.h"
const char * vertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char * fragmentShaderSource = "#version 120\n"
    "void main()\n"
    "{\n"
    " gl_FragColor = vec4(1.0f, 0.2f, 0.2f, 1.0f);\n"
    "}\n\0";
// Vertex Array Object, VAO
// Vertex Buffer Object, VBO
// Element Buffer Object, EBO/IBO

// -----------------------------------------------------------------------------
void
enEngine::init()
{
    float vertices[] = {
      0.5f, 0.5f, 0.0f,
      0.5f, -0.5f, 0.0f, 
      -0.5f, -0.5f, 0.0f, 
      -0.5f,  0.5f, 0.0f  
    }; 

    unsigned int indices[] = {
      0, 1, 3,
      1, 2, 3
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    m_shaderProgramId = loadShaders(vertexShaderSource, fragmentShaderSource);
}
// -----------------------------------------------------------------------------
void
enEngine::render()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glUseProgram(m_shaderProgramId);
  glBindVertexArray(m_vao); 
  //  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
