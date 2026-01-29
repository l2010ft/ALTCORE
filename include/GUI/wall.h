#include <string>
#include <memory>
#include <GLFW/glfw3.h>
#include "core/config.h"
class wall
{
private:
    struct wallP;
    struct Inputs;
    struct action;
    
    std::unique_ptr<action> actions;
    std::unique_ptr<Inputs> inpu;
    std::unique_ptr<wallP> data;
    GLFWwindow* window;
    static void Keydown(GLFWwindow* window,int key,int scancode,int action,int mods);
    static void MouseKey(GLFWwindow* window,int key,int action,int mods);
    static void MousePos(GLFWwindow* window,double xpos,double ypos);
    static void MouseScrl(GLFWwindow* window,double xoffset,double yoffset);
    static void Onclose(GLFWwindow* window);
    static void Rezise(GLFWwindow* window,int width,int heigth);
    static void Minimized(GLFWwindow* window,int iconified);
    void KeyAction(int key,int action,int mod);
    void MousechKey(int key,int action,int mod);
    void Onmousemove(double xpos,double ypos);
    void Mousescrl(double xoffset,double yoffset);
    void Resizeact(int width,int heigth);
public:
    wall(API Api);
    std::string create(int X = 800,int Y = 600,std::string names = "ALTCORE");
    std::string Setinput();
    std::string update();
    ~wall();
};