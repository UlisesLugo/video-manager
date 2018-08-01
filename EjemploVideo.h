#ifndef EJEMPLOVIDEO_H_INCLUDED
#define EJEMPLOVIDEO_H_INCLUDED

#include "Fecha.h"
#include "Autor.h"
#include "Tema.h"

class EjemploVideo{
    public:
        EjemploVideo();
        void setIdTema(int idTema){this->idTema=idTema;}
        void setIdVideo(int idVideo){this->idVideo=idVideo;}
        void setNombre(string nombre){this->nombre=nombre;}
        void setFechaElaboracion(Fecha fechaElaboracion){this->fechaElaboracion=fechaElaboracion;}
        int getIdTema(){return idTema;}
        int getIdVideo(){return idVideo;}
        string getNombre(){return nombre;}
        int getCantidadAutores(){return cantidadAutores;}
        int getListaAutores(int indice){return listaAutores[indice];}
        bool agregaAutor(int idAutor);
        Fecha getFechaElaboracion(){return fechaElaboracion;}

    private:
        int idVideo;
        string nombre;
        int idTema;
        Fecha fechaElaboracion;
        int cantidadAutores;
        int listaAutores[10];
};

EjemploVideo::EjemploVideo(){
    idVideo=0;
    nombre="";
    idTema=0;
    Fecha f1;
    fechaElaboracion=f1;
    cantidadAutores=0;
    listaAutores[0]=0;
}

bool EjemploVideo::agregaAutor(int idAutor){
    if(cantidadAutores==10)
        return false;
    else{
        for(int i=0;i<cantidadAutores;i++)
            if(listaAutores[i]==idAutor)
                return false;
        listaAutores[cantidadAutores]=idAutor;
        cantidadAutores++;
        return true;
    }
}

#endif // EJEMPLOVIDEO_H_INCLUDED
