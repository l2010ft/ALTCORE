#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <unordered_map>
#include "renders/render.h"
#include "core/config.h"
class DrawGL : public Render
{
private:
  struct wallGLP;
  struct renderData;
  struct shader;
  
  
  std::unique_ptr<wallGLP> data;

  MeshHandle nextId = 1;
  std::unordered_map<MeshHandle,renderData> RenderMeshes;

  ShaderHandle nextid = 1;
  std::unordered_map<ShaderHandle,shader> Shaders;

  GLuint VAO = 0;
  GLuint VBO = 0;

  void CreateBuffers(renderData* render,const float* vertices, size_t vertSize,const unsigned int* indices, size_t indexSize);
  GLuint createprogram();
public:
  DrawGL(GLFWwindow* window);
  void init(int X,int Y) override;
  renderact chargeSTL(const float* vertizes,size_t vertexSize,const unsigned int* indices,size_t indexCout,int model) override;
  void beginframe(const matriz& View,const matriz& projection) override;
  Action draw(const matriz& model,int idmodel,int shader = 1) override;
  void endframe() override;

  void rezise(int width,int heigth) = 0;
  ~DrawGL() override;
};
