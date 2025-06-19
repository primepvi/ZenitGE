#include "../include/VertexBuffer.hpp"
#include <stdexcept>

VertexBuffer::VertexBuffer(const void *data, size_t size, BufferUsage usage)
    : m_size(size) {
  glGenBuffers(1, &this->m_id);

  if (this->m_id == 0)
    throw std::runtime_error(
        "(VertexBuffer::VertexBuffer): failed to generate vbo.");

  this->Bind();
  glBufferData(GL_ARRAY_BUFFER, size, data, (GLenum)usage);
  this->Unbind();
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &this->m_id); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, this->m_id); }
void VertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
