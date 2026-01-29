#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "renders/render.h"
class DrawGL : public rendered
{
private:

public:
  void init() override;
  void beginframe() override;
  void draw() override;
  void endframe() override;

  void rezise(int width,int heigth) = 0;
};
