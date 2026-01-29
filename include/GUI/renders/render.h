#pragma once

class rendered
{
public:
    virtual ~rendered() = default;

    virtual void init() = 0;
    virtual void beginframe() = 0;
    virtual void draw() = 0;
    virtual void endframe() = 0;

    virtual void rezise(int width,int heigth) = 0;
};