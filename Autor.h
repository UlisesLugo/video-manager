#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED
#include "EjemploVideo.h"
class Autor{
    public:
        Autor();
        Autor(int idAutor,string nombre);
        void setIdAutor(int idAutor){this->idAutor=idAutor;}
        void setNombre(string nombre){this->nombre=nombre;}
        int getIdAutor(){return idAutor;}
        string getNombre(){return nombre;}
    private:
        int idAutor;
        string nombre;
};

Autor::Autor(){
    idAutor = 0;
    nombre ="";
}

Autor::Autor(int idAutor, string nombre){
    this->idAutor = idAutor;
    this->nombre = nombre;
}
#endif // AUTOR_H_INCLUDED
