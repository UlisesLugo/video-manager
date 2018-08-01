#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "Tema.h"
class Materia{
    public:
        Materia();
        Materia(int idMateria,string nombre);
        void setIdMateria(int idMateria){this->idMateria=idMateria;}
        void setNombre(string nombre){this->nombre=nombre;}
        int getIdMateria(){return idMateria;}
        string getNombre(){return nombre;}
    private:
        int idMateria;
        string nombre;
};

Materia::Materia(){
    idMateria=0;
    nombre="";
}

Materia::Materia(int idMateria,string nombre){
    this->idMateria=idMateria;
    this->nombre=nombre;
}

#endif // MATERIA_H_INCLUDED
