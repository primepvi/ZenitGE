#pragma once

#include <cstddef>
#include <glad/glad.h>
#include <vector>

struct VertexAttribute {
  GLuint count;
  GLuint offset;
  GLenum type;
  GLboolean normalized;
};

class VertexLayout {
private:
  std::vector<VertexAttribute> m_attributes;
  size_t m_stride;

public:
  VertexLayout();
  void pushFloat(GLuint count);

  inline const std::vector<VertexAttribute> &getAttributes() const {
    return this->m_attributes;
  }

  inline size_t getStride() const { return this->m_stride; }
};
