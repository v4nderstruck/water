#ifndef RENDER_GL_MAIN_H
#define RENDER_GL_MAIN_H

#include <glad/glad.h> // must be included before glfw
#include <GLFW/glfw3.h>
#include <string>

class Renderer {
public:
  Renderer(const char* title);
  ~Renderer();
  bool initialize();
  bool renderLoop();
private: 
  std::string title;
  GLFWwindow *window;
};
#endif