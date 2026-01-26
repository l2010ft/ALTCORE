#include <stdexcept>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <string>
#include "wall.h"

struct wall::wallP
{
    int api;
    std::string name;
    int X;
    int Y;
};
struct wall::Inputs
{
    bool keys[GLFW_KEY_LAST + 1]{};
    bool mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1]{};
    double mouseX, mouseY;
    double scrollX, scrollY;
};

struct wall::action
{
    bool action[4+1]{};
    bool acionRec;
};

wall::wall(int Api)
: data(std::unique_ptr<wallP>()) , inpu(std::unique_ptr<Inputs>()), actions(std::unique_ptr<action>())
{
    if (!glfwInit)
    {
        throw std::runtime_error("No se pudo iniciar GLFW..."); 
    }
        
    if (Api == 1)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    }else if (Api == 0)
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    }

    data -> api = Api;
}

std::string wall::create(int X = 800, int Y = 600,std::string names = "ALTCORE"){
    data -> name = names;

    const char* namech = data -> name.c_str();

    window = glfwCreateWindow(X,Y,namech,nullptr,nullptr);
        
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("La ventana no se inicio correctamente");
    }
    std::string resp = "Ventana Iniciada API: " +std::string(data->api == 0 ? "Vulkan" : "OpenGL") +" X:" + std::to_string(data->X) +" Y:" + std::to_string(data->Y) +" con el nombre:" + data->name;
    return resp;
}

std::string wall::Setinput(){
    glfwSetWindowUserPointer(window,this);
    glfwSetKeyCallback(window,Keydown);
    glfwSetMouseButtonCallback(window,MouseKey);
    glfwSetCursorPosCallback(window,MousePos);
    glfwSetScrollCallback(window,MouseScrl);
    glfwSetWindowCloseCallback(window,Onclose);
    glfwSetFramebufferSizeCallback(window,Rezise);

    return std::string("Callbacks seteadas");
}
void wall::Keydown(GLFWwindow* window,int key,int scancode,int action,int mods){
    
}
wall::~wall() {}


