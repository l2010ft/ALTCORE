#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include "core/config.h"
class make
{
private:
    /* data */
public:
    struct respscript
    {
        std::string message;
        script tipe_message;
    };
    
    make(std::queue<resp1>& input1,std::queue<resp1>& output1,std::condition_variable& cv1);
    respscript act_script(std::string action1,std::string data);

    ~make();
};