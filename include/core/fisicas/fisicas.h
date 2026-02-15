#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "core/config.h"

class fisicas
{
private:
    /* data */
public:
    fisicas();
    fisicass chargmodel(modelColison* model);
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
