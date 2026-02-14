#include <thread>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <glm/glm.hpp>
#include <glm/glm/
#include "core/config.h"

class scheduler
{
private:
public:
    scheduler();

    taskact schedulerbind(tipethread typeThread, std::function<void> fuction);

    fisicas PhysicsInterac(fisicasact tipact,glm::mat4& position,glm::mat4&

    ~scheduler();
};
