#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "renders/render.h"
class DrawGL : public Render
{
private:
  struct wallGLP;
  
  std::unique_ptr<wallGLP> data;
  void Start();
public:
  void init(GLFWwindow* window,int X,int Y) override;
  void beginframe() override;
  void draw() override;
  void endframe() override;

  void rezise(int width,int heigth) = 0;
};
