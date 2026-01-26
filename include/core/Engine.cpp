#include "Engine.h"
#include "log/log.h"
#include "GUI/wall.h"
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <stdexcept>

engine::engine() {}

void engine::enginestart(int type){
    L.info(std::string("Iniciando motor"));
        if (type == 0)
        {
            L.info(std::string("Iniciando con vulkan..."));
            try
            {
                std::string Resp;
                wall gui(0);
                Resp = gui.create();

                L.info(Resp);

            }
            catch(const std::exception& e)
            {
                L.critical(std::string(e.what()));
            }
            
        }else{
            L.info(std::string("Iniciando con opengl..."));

            try
            {
            }
            catch(const std::exception& e)
            {
                L.critical(std::string(e.what()));
            }

        }
}

engine::~engine(){}