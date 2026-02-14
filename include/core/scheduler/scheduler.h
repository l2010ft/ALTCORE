#include <thread>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>
#include "core/config.h"

class scheduler
{
private:
public:
    scheduler();

    taskact schedulerbind(tipethread type, std::function<void> fuction);

    class Physics
    {
    private:
        /* data */
    public:
        Physics(/* args */);
        ~Physics();
    };
    class Scripts
    {
    private:
        /* data */
    public:
        Scripts(/* args */);
        ~Scripts();
    };

    ~scheduler();
};
