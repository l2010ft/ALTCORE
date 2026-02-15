#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "core/config.h"

class fisicas
{
private:
    /* data */
public:
    fisicas(/* args */);
    ~fisicas();
};


struct transformfic
{
    glm::vec3 position;
    glm::quat rotation;
};

struct modelColison
{
    fisicmodel model;
    transformfic ubi;

};
