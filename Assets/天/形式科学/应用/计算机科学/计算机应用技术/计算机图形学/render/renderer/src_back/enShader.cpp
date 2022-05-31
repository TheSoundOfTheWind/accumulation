#include <stdio.h>
#include "enShader.h"
//"gl_Position = ftransform();\n"
//"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"gl_Position = projection*view*model*vec4(aPos,1.0f);\n"

/*
const char * cubeVertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"attribute vec3 aNormal;\n"
"varying vec3 FragPos;\n"
"varying vec3 Normal;\n"  
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"FragPos = vec3(model*vec4(aPos, 1.0));\n"
"Normal = aNormal;\n"  
"gl_Position = projection*view*vec4(FragPos,1.0f);\n"
"}\0";

const char * cubeFragmentShaderSource = "#version 120\n"
"varying vec3 FragPos;\n"
"varying vec3 Normal;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 lightColor;\n"  
"uniform vec3 objectColor;\n"
"void main()\n"
"{\n"
"float ambientStrength = 0.1;\n"
"vec3 ambient = ambientStrength * lightColor;\n"
"vec3 norm = normalize(Normal);\n"
"vec3 lightDir = normalize(lightPos-FragPos);\n"  
"vec3 diff = max(dot(norm, lightDir), 0.0);\n"
"vec3 diffuse = diff * lightColor;\n"
"vec3 result = (ambient + diffuse)*objectColor;\n"  
" gl_FragColor = vec4(result, 1.0f);\n"
"}\n\0";
*/
/*
const char * cubeVertexShaderSource =
"#version 120\n"
"void main()\n"
"{\n"
"gl_FrontColor = gl_Color*(vec4(0.7, 0.7, 0.7, 1.0) + vec4(0.5, 0.5, 0.5, 0.0)*max(dot(gl_NormalMatrix*gl_Normal, vec3(0.0, -0.89, -0.45)), 0.0));\n"
"gl_Position = ftransform();\n"
"}\0";

const char * cubeFragmentShaderSource =
"#version 120\n"
"void main()\n"
"{\n"
"float z = gl_FragCoord.z / gl_FragCoord.w;\n"
"float fogFactor = exp(-gl_Fog.density * z);\n"
"fogFactor = clamp(fogFactor, 0.0, 1.0);\n"
"gl_FragColor.rgb = gl_Color.rgb*fogFactor;\n"
"gl_FragColor.a = gl_Color.a;\n"  
"}\n\0";
*/


const char * cubeVertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"gl_Position = projection*view*model*vec4(aPos,1.0f);\n"
"}\0";

const char * cubeFragmentShaderSource = "#version 120\n"
"uniform vec3 objectColor;\n"
"void main()\n"
"{\n"
"gl_FragColor = vec4(objectColor, 1.0f);\n"
"}\n\0";


const char * lightVertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"gl_Position = projection*view*model*vec4(aPos,1.0f);\n"
"}\0";

const char * lightFragmentShaderSource = "#version 120\n"
"void main()\n"
"{\n"
" gl_FragColor = vec4(1.0);\n"
"}\n\0";

enShader::enShader()
{
  m_shaderProgramId = 0;
  m_model          = glm::mat4(1.0f); 
  m_view             = glm::mat4(1.0f);
  m_projection     = glm::mat4(1.0f);
  m_clip               = m_model*m_view*m_model;  
}

enShader::~enShader()
{
  m_shaderProgramId = 0;  
}
// set methods
// ---------------------------------------------------------------------------
void
enShader::init(ShaderType type)
{
  m_type = type; 
  if (Cube == m_type) {
    m_shaderProgramId = loadShaders(cubeVertexShaderSource, cubeFragmentShaderSource);
  } else {
    m_shaderProgramId = loadShaders(lightVertexShaderSource, lightFragmentShaderSource);
  }
  /*
  m_model = glm::rotate(m_model, glm::radians(45.0f), glm::vec3(0.0f, 0.3f, 0.0f));
  updateModel(m_model);  

  m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
  updateView(m_view);
  */

  m_model = glm::rotate(m_model, glm::radians(45.0f), glm::vec3(1.0f, 1.0f, 1.0f));
  updateModel(m_model);  

  m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));
  updateView(m_view);

}
// ---------------------------------------------------------------------------
void
enShader::use()
{
  glUseProgram(m_shaderProgramId);
}
// ---------------------------------------------------------------------------  
void
enShader::setVec3(const GLchar * name, glm::vec3 & vec)
{
  GLint location = glGetUniformLocation(m_shaderProgramId, name);
  if (-1 == location) {
    printf("-E- setVec3() error\n");
    return;
  }
  glUniform3f(location, vec.x, vec.y, vec.z);
}
// ---------------------------------------------------------------------------  
void
// ---------------------------------------------------------------------------  
enShader::setVec3(const GLchar * name, GLfloat v0, GLfloat v1, GLfloat v2)
{
  GLint location = glGetUniformLocation(m_shaderProgramId, name);
  if (-1 == location) {
    printf("-E- setVec3() error\n");
    return;
  }
  glUniform3f(location, v0, v1, v2);
}
// ---------------------------------------------------------------------------  
void
enShader::setMat4(const GLchar * name, glm::mat4 & mat)
{
  GLint location  = glGetUniformLocation(m_shaderProgramId, name);
  if (-1 == location) {
    printf("-E- setMat4() error\n");
    return;
  }
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}
// ---------------------------------------------------------------------------  
void
enShader::updateModel(glm::mat4 & mat)
{
  m_model = mat;
  setMat4("model", m_model);
}
// ---------------------------------------------------------------------------  
void
enShader::updateView(glm::mat4 & mat)
{
  m_view = mat;
  setMat4("view", m_view);
}
// ---------------------------------------------------------------------------  
void
enShader::updateProjection(glm::mat4 & mat)
{
  m_projection = mat;
  setMat4("projection", m_projection);
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
