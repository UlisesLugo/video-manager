#include <iostream>
#include <fstream>

using namespace std;

#include "EjemploVideo.h"

//Funcion que pide y lee los nombres de los archivos
void pedirLeerNombres(string nombres[4]){
    cout << "Ingresa el nombre del archivo que contiene las Materias" << endl;
    cin >> nombres[0];
    cout << "Ingresa el nombre del archivo que contiene los Temas" << endl;
    cin >> nombres[1];
    cout << "Ingresa el nombre del archivo que contiene los Autores" << endl;
    cin >> nombres[2];
    cout << "Ingresa el nombre del archivo que contiene los Videos de ejemplo" << endl;
    cin >> nombres[3];
}

//Funcion que lee cada archivo dependiendo de su nombre
void leerArchivos(string nombres[4],ifstream& archEnt, Materia materias[5], Tema temas[10],Autor autores[10],EjemploVideo videos[20],int contadores[5]){
    int id1,id2,dd,mm,aa,idA,cant,contadorAgregados;
    string nombre;
    bool encuentra;
    for(int i=0;i<4;i++){
        contadores[i]=0;
        nombres[i]+=".txt";
        archEnt.open(nombres[i].c_str());
        if(archEnt.is_open()){
            switch(i){
                case 0://Leer Materias
                    while(archEnt>>id1 && getline(archEnt,nombre)){
                        materias[contadores[0]].setIdMateria(id1);
                        materias[contadores[0]].setNombre(nombre);
                        contadores[0]++;
                    }
                    break;
                case 1://Leer Temas
                    while(archEnt>>id1>>id2 && getline(archEnt,nombre)){
                        encuentra=false;
                        for(int i=0;i<contadores[0];i++){
                            if(id2==materias[i].getIdMateria()){
                                encuentra=true;
                                break;
                            }
                        }
                        if(encuentra){
                            temas[contadores[1]].setIdTema(id1);
                            temas[contadores[1]].setIdMateria(id2);
                            temas[contadores[1]].setNombre(nombre);
                            contadores[1]++;
                        }
                        else{
                            cout << "La materia con id " << id2 << " NO esta registrada en la lista" << endl;
                        }
                    }
                    break;
                case 2://Leer Autores
                    while(archEnt>>id1 && getline(archEnt,nombre)){
                        autores[contadores[2]].setIdAutor(id1);
                        autores[contadores[2]].setNombre(nombre);
                        contadores[2]++;
                    }
                    break;
                case 3://Leer Videos
                    while(archEnt>>id1>>nombre>>id2>>dd>>mm>>aa>>cant){
                        //Checar que el id2 este en los idTemas
                        encuentra=false;
                        for(int i=0;i<contadores[1];i++){
                            if(id2==temas[i].getIdTema()){
                                encuentra=true;
                                break;
                            }
                        }
                        if(encuentra){
                            //Leer los id de autores y buscarlos
                             contadorAgregados=0;
                            for(int i=1;i<=cant;i++){
                                encuentra=false;
                                archEnt>>idA;
                                for(int j=0;j<contadores[2];j++)
                                    if(idA==autores[j].getIdAutor()){
                                        encuentra=true;
                                        break;
                                    }
                                if(encuentra){
                                    if(videos[contadores[3]].agregaAutor(idA))
                                        contadorAgregados++;
                                }
                                else{
                                    EjemploVideo vacio;
                                    videos[contadores[3]]=vacio;
                                    cout << "El autor con id " << idA << " NO esta registrado" << endl;
                                    break;
                                }
                            }
                            if(contadorAgregados==cant){
                                videos[contadores[3]].setIdVideo(id1);
                                videos[contadores[3]].setNombre(nombre);
                                videos[contadores[3]].setIdTema(id2);
                                Fecha ejemplo;
                                ejemplo.setFecha(dd,mm,aa);
                                videos[contadores[3]].setFechaElaboracion(ejemplo);
                                contadores[3]++;
                            }
                        }
                        else{
                            cout << "El tema con id " << id2 << " NO esta registrado" << endl;
                            for(int i=1;i<=cant;i++)
                                archEnt>>idA;
                        }
                    }
                    break;
            }
        }
        archEnt.close();
    }
}

//Funcion que muestra la lista de materias, temas y autores
void muestraListas(int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10]){
    cout << endl << "     Lista de materias     " << endl;
    cout << "Id    Nombre" << endl;
    for(int i=0;i<contadores[0];i++){
        cout << materias[i].getIdMateria() << " " << materias[i].getNombre() << endl;
    }
    cout << endl << "     Lista de Temas     " << endl;
    cout << " Id IdMateria Nombre" << endl;
    for(int i=0;i<contadores[1];i++){
        cout << temas[i].getIdTema() << " " << temas[i].getIdMateria() << " " << temas[i].getNombre() << endl;
    }
    cout << endl << "     Lista de Autores    " << endl;
    cout << "Id    Nombre" << endl;
    for(int i=0;i<contadores[2];i++){
        cout << autores[i].getIdAutor() << " " << autores[i].getNombre() << endl;
    }
}

//Funcion que agrega un video a la lista de videos
void agregaVideo(int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10],EjemploVideo videos[20]){
    int idVideo,idTema, idAutor,dd,mm,aa,cantidad;
    bool encuentra;
    string nombre;
    //Busca que no se repita el id de video
    do{
        cout << endl << "Ingrese el id del Video (unico): ";
        cin >> idVideo;
        encuentra=false;
        for(int i=0;i<contadores[3];i++)
        if(idVideo==videos[i].getIdVideo()){
            encuentra=true;
            break;
        }
    }while(encuentra);
    cout << "Ingrese el nombre del video (1 palabra): ";
    cin >> nombre;

    //Busca un idTema valido
    encuentra=false;
    do{
        cout << "Ingrese el id del tema (valido): ";
        cin >> idTema;
        for(int i=0;i<contadores[1];i++){
            if(idTema==temas[i].getIdTema()){
                encuentra=true;
                break;
            }
        }
    }while(!encuentra);

    //Pide la fecha
    cout << "Ingresa la fecha (dd mm aa)" << endl;
    cin >> dd >> mm >> aa;
    Fecha nueva;
    nueva.setFecha(dd,mm,aa);
    //Pide cantidad de autores y valida cada uno
    cout << "Ingresa la cantidad de autores: " << endl;
    cin >> cantidad;
    for(int i=0;i<cantidad;i++){
        encuentra=false;
        do{
            cout << "Ingresa el id del Autor " << i+1 << ": ";
            cin >> idAutor;
            for(int i=0;i<contadores[2];i++){
                if(idAutor==autores[i].getIdAutor()){
                    encuentra=true;
                    break;
                }
            }
            if(!(videos[contadores[3]].agregaAutor(idAutor)) && encuentra){
            cout << "El autor con id " << idAutor << " ya fue ingresado" << endl;
            encuentra=false;
            }
        }while(!encuentra);
    }
    //Agrega video
    videos[contadores[3]].setIdVideo(idVideo);
    videos[contadores[3]].setNombre(nombre);
    videos[contadores[3]].setIdTema(idTema);
    videos[contadores[3]].setFechaElaboracion(nueva);
    contadores[3]++;

}
//Funcion que muestra todos los autores dado el numero del video
void mostrarAutores(int numVideo,int contadores[5], EjemploVideo videos[20],Autor autores[10]){
    for(int i=0;i<videos[numVideo].getCantidadAutores();i++){
        for(int j=0;j<contadores[2];j++){
            if(videos[numVideo].getListaAutores(i)==autores[j].getIdAutor()){
                cout << autores[j].getNombre() << " ";
                break;
            }
        }
    }
    cout << endl;
}
//Funcion que muestra la fecha de un video dado el numero de video
void mostrarFecha(int numVideo, EjemploVideo videos[20]){
    cout << " " << videos[numVideo].getFechaElaboracion().getDia() << " " << videos[numVideo].getFechaElaboracion().getMes() << " " << videos[numVideo].getFechaElaboracion().getAnio() << " ";
}
//Funcion que muestra el nombre del tema dado el numero de video
void mostrarTemaMateria(int numVideo, int contadores[5],EjemploVideo videos[20],Tema temas[10],Materia materias[5]){

    for(int i=0;i<contadores[1];i++){
        if(videos[numVideo].getIdTema()==temas[i].getIdTema()){
            cout << " " << temas[i].getNombre();
            for(int j=0;j<contadores[0];j++){
                if(temas[i].getIdMateria()==materias[j].getIdMateria()){
                    cout << " " << materias[j].getNombre();
                    break;
                }
            }
            break;
        }

    }
}
//Funcion que muestra
void muestraVideos(int numVideo,int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10],EjemploVideo videos[20]){
    cout << endl << videos[numVideo].getIdVideo() << " " << videos[numVideo].getNombre();
    mostrarTemaMateria(numVideo,contadores,videos,temas,materias);
    mostrarFecha(numVideo,videos);
    mostrarAutores(numVideo,contadores,videos,autores);
}

//Funcion que muestra todos los datos de los videos dado un idTema
void mostrarVideosPorTema(int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10],EjemploVideo videos[20]){
    int idTema;
    cout << "Ingrese el id del tema: ";
    cin >> idTema;
    int mostrados=0;
    for(int i=0;i<contadores[3];i++){
        if(idTema==videos[i].getIdTema()){
            muestraVideos(i,contadores,materias,temas,autores,videos);
            mostrados++;
        }
    }
    if(mostrados==0)
        cout << endl << "No hay ningun video registrado con ese id" << endl;
}
//Funcion que muestra todos los datos de los videos dado un idMateria
void mostrarVideosPorMateria(int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10],EjemploVideo videos[20]){
    int idMateria,encontrados=0;
    cout << "Ingrese el id de la materia: ";
    cin >> idMateria;
    for(int i=0;i<contadores[3];i++){
        for(int j=0;i<contadores[1];j++){
            if(videos[i].getIdTema()==temas[j].getIdTema()){
                if(idMateria==temas[j].getIdMateria()){
                    muestraVideos(i,contadores,materias,temas,autores,videos);
                    encontrados++;
                }
                break;
            }
        }
    }
    if(encontrados==0)
        cout << endl << "No hay ningun video registrado con ese id" << endl;
}

void mostrarListaVideos(int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10],EjemploVideo videos[20]){
    for(int i=0;i<contadores[3];i++){
        muestraVideos(i,contadores,materias,temas,autores,videos);
    }
}
//Funcion que muestra el id y el nombre de todos los videos dado un autor
void mostrarVideosPorAutor(int contadores[5],Materia materias[5],Tema temas[10],Autor autores[10],EjemploVideo videos[20]){
    int idAutor, encuentra=0;
    cout << "Ingrese el id del autor: ";
    cin >> idAutor;
    cout << endl;
    for(int i=0;i<contadores[3];i++){
        for(int j=0;j<videos[i].getCantidadAutores();j++){
            if(idAutor==videos[i].getListaAutores(j)){
                cout << videos[i].getIdVideo() << " " << videos[i].getNombre()<< endl;
                encuentra++;
                break;
            }
        }
    }
    if(encuentra==0)
        cout << "No hay ningun video registrado con ese id" << endl;
}

int main()
{
    ifstream archEnt;
    string nombres[4];
    int contadores[5];
    // [0]-Materias [1]-Temas [2]-Autores [3]-Videos
    char opcion;
    Materia materias[5];
    Tema temas[10];
    Autor autores[10];
    EjemploVideo videos[20];
    pedirLeerNombres(nombres);
    /*
        nombres[0]="Materias";
        nombres[1]="Temas";
        nombres[2]="Autores";
        nombres[3]="EjemploVideo";
    */
    //Nombres predeterminados de archivos
    leerArchivos(nombres,archEnt,materias,temas,autores,videos,contadores);
    do{
        cout << endl << "      MENU       " << endl;
        cout << "a. Consulta Informacion de Materias, Temas y Autores " << endl << "b. Dar de alta Videos de Ejemplo " << endl;
        cout << "c. Consultar la lista de Videos por tema " << endl << "d. Consultar la lista de Videos por materia" << endl;
        cout << "e. Consultar lista de Videos" << endl << "f. Consultar videos por autor" << endl << "g. Terminar" << endl;
        cout << "Ingresa opcion(letra): ";
        cin >> opcion;
        switch(opcion){
            case 'a':
                muestraListas(contadores,materias,temas,autores);
                break;
            case 'b':
                agregaVideo(contadores,materias,temas,autores,videos);
                break;
            case 'c':
                mostrarVideosPorTema(contadores,materias,temas,autores,videos);
                break;
            case 'd':
                mostrarVideosPorMateria(contadores,materias,temas,autores,videos);
                break;
            case 'e':
                mostrarListaVideos(contadores,materias,temas,autores,videos);
                break;
            case 'f':
                mostrarVideosPorAutor(contadores,materias,temas,autores,videos);
                break;
        }
    }while (opcion!='g');
    return 0;
}
