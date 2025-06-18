#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

#include "../include/Shader.hpp"
#include "../include/ShaderProgram.hpp"

int main(int argc, char **argv) {
  if (!glfwInit()) {
    std::cerr << "failed to init glfw." << std::endl;
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(800, 600, "ShadeGE", nullptr, nullptr);
  if (!window) {
    std::cerr << "failed to create glfw window." << std::endl;
    return 1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "failed to load glad." << std::endl;
    return 1;
  }

  std::cout << "OpenGL Version:" << glGetString(GL_VERSION) << std::endl;

  Shader vertexShader =
      Shader::fromPath(ShaderType::Vertex, "assets/shaders/basic.vert");
  vertexShader.compile();

  Shader fragShader =
      Shader::fromPath(ShaderType::Fragment, "assets/shaders/basic.frag");
  fragShader.compile();

  ShaderProgram program;
  program.attach(vertexShader);
  program.attach(fragShader);
  program.link();

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
