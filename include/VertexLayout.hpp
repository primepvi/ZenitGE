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
  void PushFloat(GLuint count);

  inline const std::vector<VertexAttribute> &GetAttributes() const {
    return this->m_attributes;
  }

  inline size_t GetStride() const { return this->m_stride; }
};
