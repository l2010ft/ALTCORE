#pragma once
#include <GLFW/glfw3.h>
#include "core/config.h"
class Render
{
public:
    virtual ~Render() = default;

    virtual void init(int X,int Y) = 0;
    virtual renderact chargeSTL(const float* vertizes,size_t vertexSize,unsigned int indices,size_t indexCout) = 0;
    virtual void beginframe() = 0;
    virtual void draw() = 0;
    virtual void endframe() = 0;

    virtual void rezise(int width,int heigth) = 0;
};