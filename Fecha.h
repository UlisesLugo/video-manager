#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "EjemploVideo.h"
class Fecha{
    public:
        Fecha();
        void setAnio(int anio){this->anio=anio;}
        void setMes(int mes){this->mes=mes;}
        void setDia(int dia){this->dia=dia;}
        int getAnio(){return anio;}
        int getMes(){return mes;}
        int getDia(){return dia;}
        void setFecha(int dia,int mes,int anio);
    private:
        int anio;
        int mes;
        int dia;
};

Fecha::Fecha(){
    dia=1;
    mes=1;
    anio=2000;
}

void Fecha::setFecha(int dia,int mes,int anio){
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
}
#endif // FECHA_H_INCLUDED
