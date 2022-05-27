#include <stdio.h>
#include "enShader.h"
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

enShader::enShader()
{
  m_shaderProgramId = 0;
}

enShader::~enShader()
{
  m_shaderProgramId = 0;  
}
// set methods
// ---------------------------------------------------------------------------
void
enShader::init()
{
  m_shaderProgramId = loadShaders(vertexShaderSource, fragmentShaderSource);
}
// ---------------------------------------------------------------------------
void
enShader::use()
{
  glUseProgram(m_shaderProgramId);
}
// ---------------------------------------------------------------------------  
GLuint
enShader::loadShaders(const char * vertexShaderSource,
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
      printf("-E- shader vertex compilation failed\n");
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
      printf("-E- shader fragment compilation failed\n");
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
    printf("-E- shader program linking failed\n");
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  return shaderProgram;
}
// ---------------------------------------------------------------------------  
