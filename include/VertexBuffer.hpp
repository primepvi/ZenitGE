#pragma once

#include "Buffer.hpp"
#include <cstdlib>
#include <glad/glad.h>

class VertexBuffer {
private:
  GLuint m_id;
  size_t m_size;

public:
  VertexBuffer(const void *data, size_t size, BufferUsage usage);
  ~VertexBuffer();

  void Bind() const;
  void Unbind() const;

  inline GLuint GetId() const { return this->m_id; }
  inline size_t GetSize() const { return this->m_size; }
};
