#include <iostream>
#include <stdio.h>
#include "glad.h"
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings window
//----------------------------------
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
//----------------------------------

// shader source
//------------------------------------------------------
const char *vertexShaderSource = "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "void main()\n"
  "{\n"
  " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
  "}\0";
const char *fragmentShader1Source = "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
  "}\n\0";
//------------------------------------------------------
const char *fragmentShader2Source = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\n\0";

int main()
{
  // glfw: initialize and configure
  //------------------------------------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //------------------------------------------------------------

  
  // glfw window creation
  // -------------------------------------------------------------------------------------
  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  //-----------------------------------------------------------------------------------------

  // glad: load all OpenGL function pointers
  // -----------------------------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Faild to initialize GLAD" << std::endl;
    return -1;
  }
  // ------------------------------------------------------------
  
  // build and compile our shader program
  // ---------------------------------------------------------------------------------------------------------------
  // vertex shader
  // -------------------------------------------------------------------------------------------------
  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // check for shader compile errors
  // ----------------------------------------------------------------------------------
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  //------------------------------------------------------------------------------------
  // ----------------------------------------------------------------------------------------------------
  // fragment shader1
  // ----------------------------------------------------------------------------------------------------
  int fragmentShader_1 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader_1, 1, &fragmentShader1Source, NULL);
  glCompileShader(fragmentShader_1);
  // check for shader compile errors
  // -------------------------------------------------------------------------------------
  glGetShaderiv(fragmentShader_1, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader_1, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATIONS_FAILED\n" << infoLog << std::endl;
  }
  // -------------------------------------------------------------------------------------
  // fragment shader2
  // ----------------------------------------------------------------------------------------------------
  int fragmentShader_2 = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader_2, 1, &fragmentShader2Source, NULL);
  glCompileShader(fragmentShader_2);
  // check for shader compile errors
  // -------------------------------------------------------------------------------------
  glGetShaderiv(fragmentShader_2, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader_2, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATIONS_FAILED\n" << infoLog << std::endl;
  }
  // -------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------------------
  // link shaders
  //-------------------------------------------
  int shaderProgramOrange = glCreateProgram();
  glAttachShader(shaderProgramOrange, vertexShader);
  glAttachShader(shaderProgramOrange, fragmentShader_1);
  glLinkProgram(shaderProgramOrange);

  int shaderProgramYellow = glCreateProgram();
  glAttachShader(shaderProgramYellow, vertexShader);
  glAttachShader(shaderProgramYellow, fragmentShader_2);
  glLinkProgram(shaderProgramYellow);
  //-------------------------------------------
  // check for linking errors
  // ------------------------------------------------------------------------------
  glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infoLog);
    std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infoLog);
    std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  //-------------------------------------------------------------------------------
  // delete shader
  // -----------------------------
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader_1);
  glDeleteShader(fragmentShader_2);
  // -----------------------------
  //-----------------------------------------------------------------------------------------------------------------

  // set up vertex data (and buffers(s) and configure vertex attributes)
  // ----------------------------------------------------------------------------------------------------------------
  float firstTriangle[] = {
    0.5f, 0.0f, 0.0f,  // left 
    0.5f, 0.5f, 0.0f,   // right
    0.0f, 0.5f, 0.0f    // top 
  };

  float secondTriangle[] = {
    -0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.0f, -0.5f, 0.0f
  };
  unsigned int VBOs[2], VAOs[2];
  glGenVertexArrays(2, VAOs);
  glGenBuffers(2, VBOs);

  printf("VBO1 %d VBO2 %d VAO1 %d VAO2 %d\n", VBOs[0], VBOs[1], VAOs[0], VAOs[1]);
  // bind the Vertex Array Object first
  // ----------------------------------
  glBindVertexArray(VAOs[0]);
  // ----------------------------------
  
  // bind and set vertex buffer(s)
  // ----------------------------------------------------------------------
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
  // -----------------------------------------------------------------------

  // configure vertex attributtes(s)
  // ------------------------------------------------------------------------
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // ------------------------------------------------------------------------

    // bind the Vertex Array Object first
  // ----------------------------------
  glBindVertexArray(VAOs[1]);
  // ----------------------------------
  
  // bind and set vertex buffer(s)
  // ----------------------------------------------------------------------
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
  // -----------------------------------------------------------------------

  // configure vertex attributtes(s)
  // ------------------------------------------------------------------------
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(0);
  // ------------------------------------------------------------------------


  
  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's
  // bound vertex buffer object so afterwards we can safely unbind
  // ------------------------------
  //glBindBuffer(GL_ARRAY_BUFFER, 0);
  // ------------------------------

  // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely
  // happens. VAOs requires a call a glBindVectexArray anyways so we generally don't unbind VAOs (nor VBOs) when
  // it's not directly neccessary
  // ------------------
  //glBindVertexArray(0);
  // ------------------

  // uncomment this call to draw in wireframe polygons
  // glPolygonMode(GL_FRONT_AND BACK, GL_LINE);

  // render loop
  // ---------------------------------------------------------------------------------------------------------------
  while (!glfwWindowShouldClose(window)) {
    // input
    // ------------------
    processInput(window);
    // ------------------

    // render
    // ----------------------------------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // ----------------------------------

    // draw our first triangle
    // --------------------------------------------------------------------------------------------------------------
    glUseProgram(shaderProgramOrange);
    glBindVertexArray(VAOs[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll
                            // do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgramYellow);

    glBindVertexArray(VAOs[1]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll
                            // do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);

    
    // glBindVertexArray(0); // no need to unbind it every time
    // --------------------------------------------------------------------------------------------------------------

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // ---------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
    // ---------------------
  }
  // -----------------------------------------------------------------------------------------------------------------

  // optional: de-allocate all resources once they've outlived their purpose:
  // ----------------------------
  glDeleteVertexArrays(2, VAOs);
  glDeleteBuffers(2, VBOs);
  glDeleteProgram(shaderProgramOrange);
  glDeleteProgram(shaderProgramYellow);
  // ----------------------------

  // glfw: terminate, clearing all previously allocated GLFW resources
  // -------------
  glfwTerminate();
  // -------------

  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  // make sure the viewport matches the new window dimensions; note that width and
  // height will be significantly large than specified on retina displays
  glViewport(0, 0, width, height);
}
