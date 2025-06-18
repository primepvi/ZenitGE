#include "../include/ShaderProgram.hpp"
#include <stdexcept>

ShaderProgram::ShaderProgram() : m_id(glCreateProgram()) {}

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

  for (const Shader &shader : this->m_shaders)
    glDeleteShader(shader.getId());

  this->m_shaders.clear();
}

void ShaderProgram::use() const { glUseProgram(this->m_id); }
