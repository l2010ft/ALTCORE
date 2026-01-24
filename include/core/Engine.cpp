#include "Engine.h"
#include "log/log.h"
#include "GUI/wall.h"
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
class engine
{
private:
    log L;
public:
    engine(){
    }
    void engineRun(int type){
        L.info(std::string("Iniciando motor"));
        if (type == 0)
        {
            L.info(std::string("Iniciando con vulkan..."));
        }else{
            L.info(std::string("Iniciando con opengl..."));
        }
        
    }
    ~engine();
};
