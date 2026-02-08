#include "Engine.h"
#include "config.h"
#include "log/log.h"
#include "GUI/wall.h"
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <stdexcept>

engine::engine() {}

void engine::enginestart(API type){
    L.info(std::string("Iniciando motor"));
    if (type == API::Vulkan)
        {
            L.info(std::string("Iniciando con vulkan..."));
            try
            {
                std::string Resp;
                wall gui(API::Vulkan);
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
            std::string Resp;
            wall gui(API::OpenGL);

            Resp = gui.create();

            L.info(Resp);
        }
        catch(const std::exception& e)
        {
            L.critical(std::string(e.what()));
        }
    }
}

engine::~engine(){}