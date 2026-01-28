#include "wallGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

DrawGL::DrawGL(GLFWwindow* window){
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("GLAD falied");
    }
    
}