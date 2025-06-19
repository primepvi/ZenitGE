#include "../include/VertexArray.hpp"
#include <stdexcept>

VertexArray::VertexArray() : m_index(0) {
  glGenVertexArrays(1, &this->m_id);
  if (this->m_id == 0)
    throw std::runtime_error(
        "(VertexArray::VertexArray): failed to generate vao.");
}

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &this->m_id); }

void VertexArray::addBuffer(const VertexBuffer &vbo,
                            const VertexLayout &layout) {
  this->bind();
  vbo.bind();

  for (const VertexAttribute &attribute : layout.getAttributes()) {
    size_t offset = attribute.offset;

    glEnableVertexAttribArray(this->m_index);
    glVertexAttribPointer(this->m_index++, attribute.count, attribute.type,
                          attribute.normalized, layout.getStride(),
                          (GLvoid *)offset);
  }

  vbo.unbind();
  this->unbind();
}
