#include "scriptloader/scripload.h"
#include "core/config.h"
struct Vec3
{
    float x,y,z;
};

struct Rotation {
    float pitch,yaw,roll;
};

struct position {
    Vec3 Posicion;
    Rotation rotacion;
};

class Entity {
private:
    int odjectid;
    position* posodj;
    float size;
public:
    Entity(std::string model_direction,position first_p,float size_s);

    std::string component_colision(fisicmodel tipe_colision,fisicmodel_med med_colision);    
};

class EngineAPY
{
private:
    make* ballistic = nullptr;
public:
    //inicializar antes que el constructor el puntero del ballistic :3
    EngineAPY(make* ptr);
    std::string transform(position pocisionodj,int odjid);
    ~EngineAPY();
};