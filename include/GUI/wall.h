#include <string>
#include <memory>
#include <GLFW/glfw3.h>
class wall
{
private:
    struct wallP;

    std::unique_ptr<wallP> data;
    GLFWwindow* window;
public:
    wall(int Api);
    std::string create(int X = 800,int Y = 600,std::string names = "ALTCORE");
    
    ~wall();
};