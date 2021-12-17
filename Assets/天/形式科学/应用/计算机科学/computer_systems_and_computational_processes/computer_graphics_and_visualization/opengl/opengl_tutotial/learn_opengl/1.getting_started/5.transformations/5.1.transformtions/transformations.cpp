#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "shader_s.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
  //-------------------------------------------------------------
  Shader ourShader("5.1.transform.vs", "5.1.transform.fs");
  //-------------------------------------------------------------
  
  
  // set up vertex data (and buffers(s) and configure vertex attributes)
  // ----------------------------------------------------------------------------------------------------------------
  float vertices[] = {
    // positions         colors
    0.5f, 0.5f, 0.0f, 1.0f, 1.0f, // top right
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f  // top left
  };

  unsigned int indices[] { // note that we start from 0
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
  };

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the Vertex Array Object first
  // ----------------------------------
  glBindVertexArray(VAO);
  // ----------------------------------
  
  // bind and set vertex buffer(s)
  // ----------------------------------------------------------------------
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // -----------------------------------------------------------------------

  // bind and set emement buffer(s)
  // ----------------------------------------------------------------------
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  // ----------------------------------------------------------------------

  // configure vertex attributtes(s)
  // ----------------------------------------------------------------------------------------
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);
  // ----------------------------------------------------------------------------------------

  // load and create texture
  // --------------------------------------------------
  unsigned int texture[2];
  glGenTextures(2, texture);

  glBindTexture(GL_TEXTURE_2D, texture[0]); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
  // set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // set texture filtering paramenters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // load image, create texture and generate mipmaps
  int width, height, nrChannels;
  //  unsigned char *data = stbi_load("/home/hljin/knowledge/graphics/opengl/learn_opengl/resources/textures/container.jpg", &width, &height, &nrChannels, 0);
  unsigned char *data = stbi_load("./container.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    std::cout << "Faild to load texture" << std::endl;
  }
  stbi_image_free(data);

  // texture 2

  glBindTexture(GL_TEXTURE_2D, texture[1]);
  
  // set the texture wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  // set texture filtering paramenters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  stbi_set_flip_vertically_on_load(true);
  data = stbi_load("./awesomeface.png", &width,
				   &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  ourShader.use();
  ourShader.setInt("texture1", 0);
  ourShader.setInt("texture2", 1);
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

    // bind textures on corresponding texture units
    // --------------------------------------
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    // --------------------------------------

    // create transformations
    // ----------------------------------------------------------------------------------------------
    glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
    transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    // ----------------------------------------------------------------------------------------------

    // get matrix's uniform location and set matrix
    ourShader.use();
    unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

    // render container
    // -------------------------------------------------
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // -------------------------------------------------

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
  glDeleteBuffers(1, &EBO);
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
