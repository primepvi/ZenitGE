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

  static Shader FromPath(ShaderType type, const std::string &path);
  static Shader FromSource(ShaderType type, const std::string &source);

  void Compile();

  inline void Destroy() {
    glDeleteShader(this->m_id);
    this->m_id = 0;
  }

  inline ShaderType GetType() const { return this->m_type; }
  inline GLuint GetId() const { return this->m_id; }
};
