#include "wallGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

struct DrawGL::wallGLP{
    GLFWwindow* window;
    int x,y;
};

struct DrawGL::renderData{
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
    GLuint shaderprogram = 0;
    size_t indexCount = 0;
};
DrawGL::DrawGL(GLFWwindow* window)
: data(std::make_unique<wallGLP>()), renderdat(std::make_unique<renderData>())
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    data ->window = window;

}

void DrawGL::init(int X,int Y)
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,X,Y);
    data -> x = X;
    data -> y = Y;
}

