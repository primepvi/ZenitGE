#include "../include/VertexLayout.hpp"

VertexLayout::VertexLayout() : m_stride(0), m_attributes() {}

void VertexLayout::pushFloat(GLuint count) {
  VertexAttribute attribute = {.count = count,
                               .offset = (GLuint)this->m_stride,
                               .type = GL_FLOAT,
                               .normalized = GL_FALSE};

  this->m_attributes.push_back(attribute);
  this->m_stride += sizeof(GLfloat) * count;
}
