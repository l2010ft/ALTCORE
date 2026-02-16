#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <Jolt/Jolt.h>
#include <Jolt/Physics/PhysicsSystem.h>
#include "core/config.h"

class fisicas
{
private:
    /* data */
public:
    fisicas(JPH::PhysicsSystem& physics);
    fisicass chargmodel(modelColison* model);

    fisicasact move();

    ~fisicas();
};


struct transformfic
{
    glm::vec3 position;
    glm::vec3 scala;
    glm::quat rotation;
};

struct modelColison
{
    fisicmodel model;
    transformfic trasnfom;
};
