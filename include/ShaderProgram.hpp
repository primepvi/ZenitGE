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

  void Attach(const Shader &shader);
  void Link();
  void Use() const;
};
