#include "scriptloader/scripload.h"
#include "core/config.h"
#include <variant>
#include <optional>
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
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

struct colision_odjs
{
    std::vector<int> objects;
};


class Entity {
private:
    int odjectid,colision_odjid;
    position* posodj;
    float size;
    bool colision;
public:
    Entity(std::string model_direction,position first_p,float size_s);

    std::string component_colision(fisicmodel tipe_colision,fisicmodel_med med_colision); 
    
    std::string script_component(std::string script_direction);

    std::string animation_component(std::string animation_direction);

    std::optional<colision_odjs> Colision();    
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
    std::string call_F(int odjid,int fuction_P);
    ~EngineAPY();
};


PYBIND11_MODULE(AlTCORE,alt) {
    py::class_<Vec3>(alt,"Vec3")
        .def(py::init<float,float,float>())
        .def_readwrite("x",&Vec3::x)
        .def_readwrite("y",&Vec3::y)
        .def_readwrite("z",&Vec3::z)
    ;

    py::class_<Rotation>(alt,"Rotation")
        .def(py::init<float,float,float>())
        .def_readwrite("pitch",&Rotation::pitch)
        .def_readwrite("roll",&Rotation::roll)
        .def_readwrite("yaw",&Rotation::yaw)
    ;

    py::class_<position>(alt,"posicion")
        .def(py::init<Vec3, Rotation>())
        .def_readwrite("posicion",&position::Posicion)
        .def_readwrite("rotation",&position::rotacion)
    ;
    
    py::class_<colision_odjs>(alt,"colision")
        .def(py::init<>())
        .def_readwrite("odjects",&colision_odjs::objects)
    ;
    py::class_<Entity>(alt , "Entity")
        .def(py::init<std::string>())
    ;

}