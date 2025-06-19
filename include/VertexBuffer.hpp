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

  void bind() const;
  void unbind() const;

  GLuint getId() const;
  size_t getSize() const;
};
