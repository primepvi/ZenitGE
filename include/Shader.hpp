#pragma once

#include <cstdint>
#include <glad/glad.h>
#include <string>

enum class ShaderType {
  Vertex = GL_VERTEX_SHADER,
  Fragment = GL_FRAGMENT_SHADER,
};

class Shader {
private:
  ShaderType m_type;
  uint32_t m_id;
  std::string m_source;

  Shader(ShaderType type, const std::string &source);

public:
  static Shader fromPath(ShaderType type, const std::string &path);
  static Shader fromSource(ShaderType type, const std::string &source);

  void compile();

  ShaderType getType() const;
  uint32_t getId() const;
};
