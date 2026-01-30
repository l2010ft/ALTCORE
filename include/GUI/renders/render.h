#pragma once
#include <GLFW/glfw3.h>
class Render
{
public:
    virtual ~Render() = default;

    virtual void init(int X,int Y) = 0;
    virtual void beginframe() = 0;
    virtual void draw() = 0;
    virtual void endframe() = 0;

    virtual void rezise(int width,int heigth) = 0;
};