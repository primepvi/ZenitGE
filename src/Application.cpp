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

  GLFWwindow *window = glfwCreateWindow(800, 600, "ZenitGE", nullptr, nullptr);
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
      Shader::FromPath(ShaderType::Vertex, "assets/shaders/basic.vert");
  vertexShader.Compile();

  Shader fragShader =
      Shader::FromPath(ShaderType::Fragment, "assets/shaders/basic.frag");
  fragShader.Compile();

  ShaderProgram program;
  program.Attach(vertexShader);
  program.Attach(fragShader);
  program.Link();

  float vertices[] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f  // top left
  };

  unsigned int indices[] = {
      0, 1, 3, // first Triangle
      1, 2, 3  // second Triangle
  };

  float colors[] = {
      1.f, 0.f, 0.f, // top right
      0.f, 1.f, 0.f, // top left
      0.f, 0.f, 1.f, // bottom right
      .5f, 0.f, .5f  // bottom left
  };

  VertexBuffer verticesVbo(vertices, sizeof(vertices), BufferUsage::StaticDraw);
  VertexLayout verticesLayout;
  verticesLayout.PushFloat(3);

  VertexBuffer colorsVbo(colors, sizeof(colors), BufferUsage::StaticDraw);
  VertexLayout colorsLayout;
  colorsLayout.PushFloat(3);

  ElementBuffer ebo(indices, sizeof(indices), BufferUsage::StaticDraw);

  VertexArray vao;
  vao.BindVertexBuffer(verticesVbo, verticesLayout);
  vao.BindVertexBuffer(colorsVbo, colorsLayout);
  vao.BindElementBuffer(ebo);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.Use();
    vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
