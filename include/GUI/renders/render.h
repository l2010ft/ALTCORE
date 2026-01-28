#pragma once

class rendered
{
public:
    virtual ~rendered();

    virtual void init() = 0;
    virtual void beginframe() = 0;
    virtual void draw() = 0;
    virtual void endframe() = 0;
};