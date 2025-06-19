#include "../include/VertexArray.hpp"
#include <stdexcept>

VertexArray::VertexArray() : m_index(0) {
  glGenVertexArrays(1, &this->m_id);
  if (this->m_id == 0)
    throw std::runtime_error(
        "(VertexArray::VertexArray): failed to generate vao.");
}

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &this->m_id); }

void VertexArray::BindVertexBuffer(const VertexBuffer &vbo,
                                   const VertexLayout &layout) {
  this->Bind();
  vbo.Bind();

  for (const VertexAttribute &attribute : layout.GetAttributes()) {
    size_t offset = attribute.offset;

    glEnableVertexAttribArray(this->m_index);
    glVertexAttribPointer(this->m_index++, attribute.count, attribute.type,
                          attribute.normalized, layout.GetStride(),
                          (GLvoid *)offset);
  }

  vbo.Unbind();
  this->Unbind();
}

void VertexArray::BindElementBuffer(const ElementBuffer &ebo) {
  this->Bind();
  ebo.Bind();
  this->Unbind();
}
