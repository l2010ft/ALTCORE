#include "Engine.h"
#include "log/log.h"
#include "GUI/wall.h"
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <stdexcept>
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
            try
            {
                wall gui(0,L);
            }
            catch(const std::exception& e)
            {
                L.critical(std::string(e.what()));
            }

        }else{
            L.info(std::string("Iniciando con opengl..."));

            try
            {
                wall gui(1,L);
            }
            catch(const std::exception& e)
            {
                L.critical(std::string(e.what()));
            }

        }
        
    }
    ~engine();
};
