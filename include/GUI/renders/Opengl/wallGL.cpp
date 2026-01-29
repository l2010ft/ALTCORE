#include "wallGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

void DrawGL::init(GLFWwindow* window,int X,int Y){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }   

    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,X,Y);
}