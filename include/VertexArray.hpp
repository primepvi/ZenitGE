#pragma once

#include "VertexBuffer.hpp"
#include "VertexLayout.hpp"
#include <cstddef>
#include <glad/glad.h>

class VertexArray {
private:
  size_t m_index;
  GLuint m_id;

public:
  VertexArray();
  ~VertexArray();

  inline void bind() const { glBindVertexArray(this->m_id); }
  inline void unbind() const { glBindVertexArray(0); }

  void addBuffer(const VertexBuffer &vbo, const VertexLayout &layout);
};
