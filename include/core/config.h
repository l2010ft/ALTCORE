#pragma once
#include <cstdint>

enum class API {
    OpenGL,
    Vulkan
};

enum class renderact {
    render_success,
    render_fail
};

enum class Action {
    drawSUCCES,
    drawFail
};

struct matriz
{
    float mat4[16];
};


using MeshHandle = uint32_t;
using TextureHandle = uint32_t;
using ShaderHandle = uint32_t;