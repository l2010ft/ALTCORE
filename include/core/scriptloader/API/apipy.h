#include "scriptloader/scripload.h"
#include "core/config.h"
#include <variant>
#include <pybind11/pybind11.h>
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

struct Entity_component {
    float dat1;
};
class Entity {
private:
    int odjectid;
    position* posodj;
    float size;
public:
    Entity(std::string model_direction,position first_p,float size_s);

    std::string component_colision(fisicmodel tipe_colision,fisicmodel_med med_colision); 
    
    std::string script_component(std::string script_direction);

    std::string animation_component(std::string animation_direction);
};

class EngineAPY
{
private:
    make* ballistic = nullptr;
public:
    //inicializar antes que el constructor el puntero del ballistic :3
    EngineAPY(make* ptr);
    std::string transform(position pocisionodj,int odjid);
    std::string Change_V(int odjid,std::variant<int,std::string,float> Value);
    std::variant<int,std::string,float,position> Get_V(int odjid);

    ~EngineAPY();
};


