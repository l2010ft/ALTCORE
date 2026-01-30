#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "renders/render.h"
class DrawGL : public Render
{
private:
  struct wallGLP;
  struct renderData;
  
  std::unique_ptr<wallGLP> data;
  std::unique_ptr<renderData> renderdat;

  GLuint VAO = 0;
  GLuint VBO = 0;
public:
  DrawGL(GLFWwindow* window);
  void init(int X,int Y) override;
  void beginframe() override;
  void draw() override;
  void endframe() override;

  void rezise(int width,int heigth) = 0;
  ~DrawGL() override;
};
