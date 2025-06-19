#include "../include/VertexBuffer.hpp"
#include <stdexcept>

VertexBuffer::VertexBuffer(const void *data, size_t size, BufferUsage usage)
    : m_size(size) {
  glGenBuffers(1, &this->m_id);

  if (this->m_id == 0)
    throw std::runtime_error(
        "(VertexBuffer::VertexBuffer): failed to generate vbo.");

  glBindBuffer(GL_ARRAY_BUFFER, this->m_id);
  glBufferData(GL_ARRAY_BUFFER, size, data, (GLenum)usage);
  glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &this->m_id); }

void VertexBuffer::bind() const { glBindBuffer(GL_ARRAY_BUFFER, this->m_id); }
void VertexBuffer::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

GLuint VertexBuffer::getId() const { return this->m_id; }
size_t VertexBuffer::getSize() const { return this->m_size; }
