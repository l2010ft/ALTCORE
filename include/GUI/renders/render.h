#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "core/config.h"
class Render
{
public:
    virtual ~Render() = default;

    virtual void init(int X,int Y) = 0;
    virtual renderact chargeSTL(const float* vertizes,size_t vertexSize,const unsigned int* indices,size_t indexCout,int model) = 0;
    virtual void beginframe(const glm::mat4& View,const glm::mat4& projection) = 0;
    virtual Action draw(const glm::mat4& model,int idmodel,int shader = 1) = 0;
    virtual void endframe() = 0;

    virtual void rezise(int width,int heigth) = 0;
};