#pragma once
#include <cstdint>
#include <string>

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


enum class fisicass {
    matsucces,
    fail,
    materror,
};

enum class fisicasact {
    colision,
    move,
    trayectoria,
    rotaticion,
    gravedad
};

enum class fisicmodel {
    cube,
    sphere,
    rectangle,
    pastilla
};

enum class script {
    cargado,
    proceso,
    scheduler,
    scriptload,
    fisic,
    data,
    fail
};
struct resp1
{
    int id;
    script tipo;
    std::string content;
};
using MeshHandle = uint32_t;
using TextureHandle = uint32_t;
using ShaderHandle = uint32_t;