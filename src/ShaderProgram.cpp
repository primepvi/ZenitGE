#include "../include/ShaderProgram.hpp"
#include <iostream>
#include <stdexcept>

ShaderProgram::ShaderProgram() : m_id(glCreateProgram()) {}
ShaderProgram::~ShaderProgram() {
  for (Shader &shader : this->m_shaders)
    shader.destroy();

  glDeleteProgram(this->m_id);
  this->m_shaders.clear();
}

void ShaderProgram::attach(const Shader &shader) {
  this->m_shaders.push_back(shader);
  glAttachShader(this->m_id, shader.getId());
}

void ShaderProgram::link() {
  glLinkProgram(this->m_id);

  int success;
  glGetProgramiv(this->m_id, GL_LINK_STATUS, &success);
  if (!success) {
    char log[512];
    glGetProgramInfoLog(this->m_id, 512, NULL, log);
    throw std::runtime_error(
        std::string("(ShaderProgram::link): cannot link shader program: ") +
        std::string(log));
  }

  std::cout << "(shader): Shader Program was compiled successfully."
            << std::endl;

  for (Shader &shader : this->m_shaders)
    shader.destroy();

  this->m_shaders.clear();
}

void ShaderProgram::use() const { glUseProgram(this->m_id); }
