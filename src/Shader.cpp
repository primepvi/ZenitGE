#include "../include/Shader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

Shader Shader::FromPath(ShaderType type, const std::string &path) {
  std::ifstream sourceFile(path);
  if (!sourceFile)
    throw std::runtime_error("(Shader::fromPath) cannot open source file: " +
                             path);

  std::stringstream buffer;
  buffer << sourceFile.rdbuf();
  std::string source = buffer.str();

  return Shader(type, source);
}

Shader Shader::FromSource(ShaderType type, const std::string &source) {
  return Shader(type, source);
}

Shader::Shader(ShaderType type, const std::string &source)
    : m_type(type), m_source(source), m_id(0) {}

Shader::~Shader() {
  if (this->m_id != 0)
    this->Destroy();
}

void Shader::Compile() {
  const char *shaderSource = this->m_source.c_str();
  const char *shaderName =
      this->m_type == ShaderType::Fragment ? "Fragment" : "Vertex";
  GLuint shaderId = glCreateShader((GLenum)this->m_type);
  glShaderSource(shaderId, 1, &shaderSource, NULL);
  glCompileShader(shaderId);

  int success;
  char log[512];
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
  if (success) {
    this->m_id = shaderId;
    std::cout << "(shader): " << shaderName
              << " Shader was compiled successfully." << std::endl;
    return;
  }

  glGetShaderInfoLog(shaderId, 512, NULL, log);
  std::stringstream errorBuffer;
  errorBuffer << "(Shader::compile): cannot compile the " << shaderName
              << " Shader.\n"
              << log << "\n"
              << shaderSource;

  throw std::runtime_error(errorBuffer.str());
}
