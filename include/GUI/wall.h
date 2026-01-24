#include <string>
#include "log/log.h"
class wall
{
private:
    struct wallP;
    GLFWwindow* window;
public:
    wall(int Api,log& log);
    std::string create(int X = 800,int Y = 600);

    ~wall();
};