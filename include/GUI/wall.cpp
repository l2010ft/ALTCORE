#include <stdexcept>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <string>
class wall
{
private:
    struct wallP
    {
        int api;
        std::string name;
        int X;
        int Y;

    };

    wallP regist;
    GLFWwindow* window;
public:
    wall(int Api,std::string name = "ALTCORE"){
        if (!glfwInit)
        {
           throw std::runtime_error("No se pudo iniciar GLFW..."); 
        }
        
        if (Api == 1)
        {
           glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
           glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
           glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
        }else if (Api == 0)
        {
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        }

        regist.api = Api;
        regist.name = name;
    }

    std::string create(int X = 800, int Y = 600){
        const char* namech = regist.name.c_str();

        window = glfwCreateWindow(X,Y,namech,nullptr,nullptr);
        
        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("La ventana no se inicio correctamente");
        }
        std::string resp = "Ventana Iniciada API: " +std::string(regist.api == 0 ? "Vulkan" : "OpenGL") +" X:" + std::to_string(regist.X) +" Y:" + std::to_string(regist.Y) +" con el nombre:" + regist.name;
        return resp;
    }
    ~wall();
};

