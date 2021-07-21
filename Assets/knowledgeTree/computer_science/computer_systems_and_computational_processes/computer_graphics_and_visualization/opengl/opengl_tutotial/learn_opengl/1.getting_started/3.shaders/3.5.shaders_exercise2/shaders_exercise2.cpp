#include <iostream>
#include <stdio.h>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "shader_s.h"
#include <cmath>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings window
//----------------------------------
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
//----------------------------------


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
  Shader ourShader("3.3.shader.vs", "3.3.shader.fs");
  float offset = 0.5;
  ourShader.setFloat("x_offset", offset);
  // ---------------------------------------------------------------------------------------------------------------

  // set up vertex data (and buffers(s) and configure vertex attributes)
  // ----------------------------------------------------------------------------------------------------------------
  float vertices[] = {
    0.5, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // left
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// right
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // top
  };

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first
  // ----------------------------------
  glBindVertexArray(VAO);
  // ----------------------------------
  
  // bind and set vertex buffer(s)
  // ----------------------------------------------------------------------
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // -----------------------------------------------------------------------

  // configure vertex attributtes(s)
  // ------------------------------------------------------------------------
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float),
			(void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);
  
  // ------------------------------------------------------------------------

  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's
  // bound vertex buffer object so afterwards we can safely unbind
  // ------------------------------
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  // ------------------------------

  // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely
  // happens. VAOs requires a call a glBindVectexArray anyways so we generally don't unbind VAOs (nor VBOs) when
  // it's not directly neccessary
  // ------------------
  glBindVertexArray(VAO);
  // ------------------

  // uncomment this call to draw in wireframe polygons
  // glPolygonMode(GL_FRONT_AND BACK, GL_LINE);

  // render loop
  // ---------------------------------------------------------------------------------------------------------------
  while (!glfwWindowShouldClose(window)) {
    static bool first_draw = false;
    static unsigned int draw_count = 0;
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
    ourShader.use();
    //glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll
    // do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // --------------------------------------------------------------------------------------------------------------
    first_draw = true;
    draw_count++;
    printf("draw count %d\n", draw_count);
 
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // ---------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
    // ---------------------

  }
  // -----------------------------------------------------------------------------------------------------------------

  // optional: de-allocate all resources once they've outlived their purpose:
  // ----------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
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
