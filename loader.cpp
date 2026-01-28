#include <vulkan/vulkan.h>
#include "core/Engine.h"
#include "core/config.h"

bool Vulkancheck();


int main(){
    engine E;
    if (Vulkancheck()){
        E.enginestart(API::Vulkan);
        return 1;
    }else{
        E.enginestart(API::OpenGL);
        return 1;
    }
}
bool Vulkancheck(){
    VkInstance instance;
    
    VkApplicationInfo appinfo{};
    appinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    appinfo.pApplicationName = "Engine";
    appinfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createinfo{};
    createinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createinfo.pApplicationInfo = &appinfo;

    VkResult resuslt = vkCreateInstance(&createinfo,nullptr,&instance);

    if (resuslt != VK_SUCCESS){
        return false;
    }

    vkDestroyInstance(instance,nullptr);
    return true;
}