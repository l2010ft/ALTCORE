#include <thread>
#include <queue>
#include <condition_variable>
#include "core/config.h"

class scheduler
{
private:
public:
    scheduler();

    taskact threadPhisics();
    taskact threadScript();

    ~scheduler();
};
