#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using namespace glm;
int main()
{
  if (!glfwInit()) {
    fprintf(stderr, "Faild to initialize GLFW\n");
    return -1;
  }
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow * window;
  window = glfwCreateWindow(1024, 768, "Totorial 01", NULL, NULL);

  if (window == NULL) {
    fprintf(stderr, "Failed to open GLFW window\n");
    glfwTerminate();
    return -1;
  }

  // initialize GLEW
  glfwMakeContextCurrent(window);
  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  do {
    glfwSwapBuffers(window);
  }while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	 glfwWindowShouldClose(window) == 0);
}
