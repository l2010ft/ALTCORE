#include <thread>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "core/config.h"

class scheduler
{
private:
    struct chargue
    {
        std::queue<resp1> input;
        std::queue<resp1> output;
        std::mutex inputmu,outputmu;
        std::condition_variable cvfuc;
    };
    
    static void Phisycs(chargue& physiccom);
    static void Scripts(chargue& scriptcom);
public:
    scheduler();
    ~scheduler();
};
