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

using MeshHandle = uint32_t;
using TextureHandle = uint32_t;