#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

#include "../include/Buffer.hpp"
#include "../include/Shader.hpp"
#include "../include/ShaderProgram.hpp"
#include "../include/VertexArray.hpp"
#include "../include/VertexBuffer.hpp"
#include "../include/VertexLayout.hpp"

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

  float vertices[] = {
      0.f,  .5f,  0.f, // top
      -.5f, -.5f, 0.f, // left
      .5f,  -.5f, 0.f, // right
  };

  float colors[] = {
      1.f, 0.f, 0.f, // top
      0.f, 1.f, 0.f, // left
      0.f, 0.f, 1.f, // right
  };

  VertexBuffer verticesVbo(vertices, sizeof(vertices), BufferUsage::StaticDraw);
  VertexLayout verticesLayout;
  verticesLayout.pushFloat(3);

  VertexBuffer colorsVbo(colors, sizeof(colors), BufferUsage::StaticDraw);
  VertexLayout colorsLayout;
  colorsLayout.pushFloat(3);

  VertexArray vao;
  vao.addBuffer(verticesVbo, verticesLayout);
  vao.addBuffer(colorsVbo, colorsLayout);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.use();
    vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
