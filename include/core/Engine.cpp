#include "Engine.h"
#include "config.h"
#include "log/log.h"
#include "GUI/wall.h"
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <memory>

struct engine::datP
{
    wall* guis = nullptr;
};




engine::engine(API type) : data(std::make_unique<datP>()){
    L.info(std::string("Iniciando motor"));
    if (type == API::Vulkan)
    {
        L.info(std::string("Iniciando con vulkan..."));
        std::string resp;
        auto gui = creategui(API::Vulkan,resp);
        
        if (gui) {
            L.info(std::string("Render iniciado con Vulkan"));
            data->guis = &gui;
        } else {
            L.error(resp);
            auto guires = creategui(API::OpenGL,resp);
            L.info(std::string("Intentando cambiar a OpenGL"));
            if (guires)
            {
                L.info(std::string("Cambiado correctamente a OpenGL"));
            } else {
                L.critical(resp);
                // lugar de funcion de protocolo de panico :3
            }
            
        }
    }else{
        L.info(std::string("Iniciando con opengl..."));

        std::string resp;
        auto gui = creategui(API::OpenGL,resp);

        if (gui) {
            L.info(std::string("Render iniciado con OpenGL"));
        }else {
            L.error(resp);
            auto guires = creategui(API::Vulkan,resp);
            L.info(std::string("Cambiando a Vulkan"));
            if (guires)
            {
                L.info(std::string("Cambiando correctamente a Vulkan"));
            } else {
                L.critical(resp);
                //funcion de protocolo de panico :3
            }
            
        }
    }
}

void engine::enginestart(){
}

engine::~engine(){}