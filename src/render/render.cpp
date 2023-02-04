#include "render.h"
#include <iostream>

static void framebuffer_size_cb(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

static void getKeys(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

Renderer::Renderer(const char *title) : title(title)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Renderer::~Renderer()
{
  glfwTerminate();
}

bool Renderer::initialize()
{
  window = glfwCreateWindow(800, 600, title.c_str(), NULL, NULL);
  if (window == NULL)
  {
    std::cout << "RENDERER: Failed to open window\n";
    return false;
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "RENDERER: Failed to initialize GLAD\n";
    return false;
  }
  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_cb);
  return true;
}

bool Renderer::renderLoop()
{

  while (!glfwWindowShouldClose(window))
  {
    getKeys(window);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  return true;
}
