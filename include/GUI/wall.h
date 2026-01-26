#include <string>
#include <memory>
#include <GLFW/glfw3.h>
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
    
public:
    wall(int Api);
    std::string create(int X = 800,int Y = 600,std::string names = "ALTCORE");
    std::string Setinput();
    std::string update();
    ~wall();
};