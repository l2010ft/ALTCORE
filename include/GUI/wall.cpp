#include <stdexcept>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <string>
#include "core/config.h"
#include <memory>
#include "wall.h"
#include "renders/render.h"
#include "Opengl/wallGL.h"
#include "Vulkan/wullkan.h"
struct wall::wallP
{
    API api;
    std::string name;
    int X;
    int Y;
    bool LIMIT_WALL;
    bool Minimized;
};
struct wall::Inputs
{
    bool keys[GLFW_KEY_LAST + 1]{};
    bool mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1]{};
    double mouseX, mouseY;
    double scrollX, scrollY;
    double deltaX,deltaY;
};

struct wall::action
{
    bool Keychange = false;
    bool mouseButtonsch = false;
    bool mouseMoved = false;
    bool scrolled = false; 
};

wall::wall(API Api)
: data(std::make_unique<wallP>()) , inpu(std::make_unique<Inputs>()), 
actions(std::make_unique<action>())
{
    if (!glfwInit())
    {
        throw std::runtime_error("No se pudo iniciar GLFW..."); 
    }
        
    if (Api == API::OpenGL) // Opengl
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    }else if (Api == API::Vulkan) // Vulkan
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        // Agregar el unique de vulkan :3
    }
    data ->Minimized = false;
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
    if(data ->api == API::Vulkan)
    {
        
    } else {
        render = std::make_unique<DrawGL>();
    }

    std::string resp = "Ventana Iniciada API: " +std::string(data->api == API::Vulkan ? "Vulkan" : "OpenGL") +" X:" + std::to_string(data->X) +" Y:" + std::to_string(data->Y) +" con el nombre:" + data->name;
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
    glfwSetWindowIconifyCallback(window,Minimized);
    return std::string("Callbacks seteadas");
}
void wall::Keydown(GLFWwindow* window,int key,int scancode,int action,int mods){
    wall* self = static_cast<wall*>(glfwGetWindowUserPointer(window));

    if(!self) return;

    self -> KeyAction(key,action,mods);
}

void wall::KeyAction(int key,int action,int mod){

    if (key > 0) return;
    if(action == GLFW_PRESS)
    {
        inpu ->keys[key] = true;
        actions -> Keychange = true;
    }
    if(action == GLFW_RELEASE)
    {
        inpu ->keys[key] = false;
        actions -> Keychange = true;
    }
}

void wall::MouseKey(GLFWwindow* window,int key,int action,int mods){
    wall* self = static_cast<wall*>(glfwGetWindowUserPointer(window));

    if(!self) return;

    self->MousechKey(key,action,mods);
}

void wall::MousechKey(int key,int action,int mod){
    if (key > 0) return;

    if(action == GLFW_PRESS)
    {
        inpu->mouseButtons[key] = true;
        actions->mouseButtonsch = true;
    }
    if(action == GLFW_RELEASE)
    {
        inpu->mouseButtons[key] = false;
        actions->mouseButtonsch = false;
    }
}

void wall::MousePos(GLFWwindow* window,double xpos,double ypos){
    wall* self = static_cast<wall*>(glfwGetWindowUserPointer(window));

    if(!self) return;

    self->Onmousemove(xpos,ypos);
}

void wall::Onmousemove(double xpos, double ypos)
{
    if (data->Minimized)
        return;

    if (data->LIMIT_WALL)
    {
        // Modo cursor libre (menús, editor, etc)
        inpu->mouseX = xpos;
        inpu->mouseY = ypos;
        inpu->deltaX = 0.0;
        inpu->deltaY = 0.0;
    }
    else
    {
        // Modo FPS (cursor bloqueado)
        inpu->deltaX = xpos - inpu->mouseX;
        inpu->deltaY = inpu->mouseY - ypos; // eje Y invertido

        inpu->mouseX = xpos;
        inpu->mouseY = ypos;
    }

    actions->mouseMoved = true;
}

void wall::MouseScrl(GLFWwindow* window,double xoffset,double yoffset){
    wall* self = static_cast<wall*>(glfwGetWindowUserPointer(window));

    if(!self) return;

    self -> Mousescrl(xoffset,yoffset);
}

void wall::Mousescrl(double xoffset,double yoffset){
    inpu->scrollX += xoffset;
    inpu->scrollY += yoffset;
    actions->scrolled = true;
}

void wall::Onclose(GLFWwindow* window){
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void wall::Rezise(GLFWwindow* window,int width,int heigth){
    wall* self = static_cast<wall*>(glfwGetWindowUserPointer(window));

    if(!self) return;

    self ->Resizeact(width,heigth);
}

void wall::Resizeact(int width,int heigth){
    if(data->api == API::Vulkan)
    {

    }else {

    }
}
wall::~wall() {}


