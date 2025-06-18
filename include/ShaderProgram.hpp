#pragma once

#include "Shader.hpp"
#include <cstdint>
#include <vector>

class ShaderProgram {
private:
  uint32_t m_id;
  std::vector<Shader> m_shaders;

public:
  ShaderProgram();
  void attach(const Shader &shader);
  void link();
  void use() const;
};
