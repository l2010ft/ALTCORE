#include <vulkan/vulkan.h>
#include "core/Engine.h"
#include "core/config.h"

bool Vulkancheck();


int main(){
    if (Vulkancheck()){
        engine E(API::Vulkan);
        E.enginestart();
        return 1;
    }else{
        engine E(API::OpenGL);
        E.enginestart();
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