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
public:
    scheduler();

    taskact schedulerbind(tipethread typeThread, std::function<void> fuction);

    fisicass PhysicsInterac(fisicasact tipact,glm::vec3 position,glm::quat rotation);

    ~scheduler();
};
