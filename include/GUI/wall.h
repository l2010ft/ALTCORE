#include <string>
#include <memory>
#include <GLFW/glfw3.h>
class wall
{
private:
    struct wallP;
    bool keys[GLFW_KEY_LAST]{};

    std::unique_ptr<wallP> data;
    GLFWwindow* window;
    static void Keydown();
    static void MouseKey();
    static void MousePos();
    static void MouseScrl();
    static void Onclose();
    static void Rezise();

public:
    wall(int Api);
    std::string create(int X = 800,int Y = 600,std::string names = "ALTCORE");
    std::string Setinput();
    std::string update();
    ~wall();
};