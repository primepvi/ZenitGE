#pragma once

#include <glad/glad.h>

enum class BufferUsage : GLenum {
  StaticDraw = GL_STATIC_DRAW,
  DynamicDraw = GL_DYNAMIC_DRAW,
  StreamDraw = GL_STREAM_DRAW,
};
