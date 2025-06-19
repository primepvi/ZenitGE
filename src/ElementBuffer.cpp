#include "../include/ElementBuffer.hpp"
#include <stdexcept>

ElementBuffer::ElementBuffer(const void *data, size_t size, BufferUsage usage)
    : m_size(size) {
  glGenBuffers(1, &this->m_id);

  if (this->m_id == 0)
    throw std::runtime_error(
        "(ElementBuffer::ElementBuffer): failed to generate vbo.");

  this->Bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, (GLenum)usage);
  this->Unbind();
}

ElementBuffer::~ElementBuffer() { glDeleteBuffers(1, &this->m_id); }

void ElementBuffer::Bind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_id);
}
void ElementBuffer::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
