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
    std::unique_ptr<wall> guis = nullptr;
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
            data->guis = std::move(gui);
        } else {
            L.error(resp);
            auto guires = creategui(API::OpenGL,resp);
            L.info(std::string("Intentando cambiar a OpenGL"));
            if (guires)
            {
                L.info(std::string("Cambiado correctamente a OpenGL"));

                data->guis = std::move(guires);
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

            data->guis = std::move(gui);
        }else {
            L.error(resp);
            auto guires = creategui(API::Vulkan,resp);
            L.info(std::string("Cambiando a Vulkan"));
            if (guires)
            {
                L.info(std::string("Cambiando correctamente a Vulkan"));
                data->guis = std::move(guires);
            } else {
                L.critical(resp);
                //funcion de protocolo de panico :3
            }
            
        }
    }
}

void engine::enginestart(){
    L.info(std::string("Iniciando GLFW"));

    std::string res;
}

std::unique_ptr<wall> engine::creategui(API api,std::string& resp) {
    try
    {
        auto ptr = std::make_unique<wall>();
        resp = resp + std::string("[Wall Create]");
        return ptr;
    }
    catch(const std::exception& e)
    {
        resp = resp + std::string("[Wall ERROR]:") + std::string(e.what());
        return nullptr;
    }
}

void engine::createwindow(int x = 800,int y = 600,std::string name = "ALTCORE",std::string& res) {
    try
    {
        std::string resp = data->guis->create(x,y,name);
        res = res + resp;
    }
    catch(const std::exception& e)
    {
        res = res + std::string(e.what());
    }
}

engine::~engine(){}