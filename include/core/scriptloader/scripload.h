#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include "core/config.h"
class make
{
private:
    struct data
    {
        std::string data1;
    };
    
public:
    struct respscript
    {
        std::string message;
        script tipe_message;
    };
    /// @brief Crea la clase make y permite la interaccion de cualquier api que posea esta clase
    /// @param input1 la direccion de la cola de input donde make va a recibir la comunicacion de scheduler
    /// @param output1 la dirreccion de la cola output donde make va a enveir la comunicacion de scheduler
    /// @param cv1 la activacion... de la clase :3
    /// @param minput la proteccion de la cola input
    /// @param moutput la proteccion de la cola output
    make(std::queue<resp1>& input1,std::queue<resp1>& output1,std::condition_variable& cv1,std::mutex minput,std::mutex moutput);
    
    respscript act_script(std::string action1,std::string data);
    respscript input_act();
    ~make();
};