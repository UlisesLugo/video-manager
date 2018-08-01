#ifndef TEMA_H_INCLUDED
#define TEMA_H_INCLUDED
#include "Materia.h"
#include "EjemploVideo.h"
class Tema{
    public:
        Tema();
        Tema(int idTema,string nombre,int idMateria);
        void setIdTema(int idTema){this->idTema=idTema;}
        void setIdMateria(int idMateria){this->idMateria=idMateria;}
        void setNombre(string nombre){this->nombre=nombre;}
        int getIdTema(){return idTema;}
        int getIdMateria(){return idMateria;}
        string getNombre(){return nombre;}
    private:
        int idMateria;
        string nombre;
        int idTema;
};

Tema::Tema(){
    idTema=0;
    nombre = "";
    idMateria=0;
}

Tema::Tema(int idTema,string nombre,int idMateria){
    this->idTema=idTema;
    this->nombre=nombre;
    this->idMateria=idMateria;
}

#endif // TEMA_H_INCLUDED
