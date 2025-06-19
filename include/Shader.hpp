#pragma once

#include <glad/glad.h>
#include <string>

enum class ShaderType : GLenum {
  Vertex = GL_VERTEX_SHADER,
  Fragment = GL_FRAGMENT_SHADER,
};

class Shader {
private:
  ShaderType m_type;
  GLuint m_id;
  std::string m_source;

  Shader(ShaderType type, const std::string &source);

public:
  ~Shader();

  static Shader fromPath(ShaderType type, const std::string &path);
  static Shader fromSource(ShaderType type, const std::string &source);

  void compile();

  inline void destroy() {
    glDeleteShader(this->m_id);
    this->m_id = 0;
  }

  ShaderType getType() const;
  GLuint getId() const;
};
