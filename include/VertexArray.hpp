#pragma once

#include "ElementBuffer.hpp"
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

  inline void Bind() const { glBindVertexArray(this->m_id); }
  inline void Unbind() const { glBindVertexArray(0); }

  void BindVertexBuffer(const VertexBuffer &vbo, const VertexLayout &layout);
  void BindElementBuffer(const ElementBuffer &ebo);
};
