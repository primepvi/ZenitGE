#pragma once

#include "Shader.hpp"
#include <vector>

class ShaderProgram {
private:
  GLuint m_id;
  std::vector<Shader> m_shaders;

public:
  ShaderProgram();
  ~ShaderProgram();

  void attach(const Shader &shader);
  void link();
  void use() const;
};
