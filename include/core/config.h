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

enum class taskact {
    taskfailed,
    taskSucces,
};



using MeshHandle = uint32_t;
using TextureHandle = uint32_t;
using ShaderHandle = uint32_t;