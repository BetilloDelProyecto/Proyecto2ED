#include "StructHumano.h"

struct StructMundo{
    StructHumano * poblacion[100000];
    string nombres[1000];
    string apellidos[15];
    string profesiones[20];
    string paises[20];
    string creencias[10];
    int cantPoblacion;

    StructMundo(){
        cantPoblacion = 0;
        cargarNombres(nombres);
        cargarApellidos(apellidos);
        cargarProfesiones(profesiones);
        cargarPaises(paises);
        cargarCreencias(creencias);
    }

    void generarPoblacion(int cant){
        for (int i = cantPoblacion; i < cant+cantPoblacion; i++){
            poblacion[i] = new StructHumano(numRandom(999999),nombres[numRandom(999)],apellidos[numRandom(14)],paises[numRandom(19)],creencias[numRandom(9)],profesiones[numRandom(19)],getDateTime());
        }
        cantPoblacion += cant;
        ordenarPoblacion();
    }

    void imprimir(){
        for (int i = 0; i < cantPoblacion; i++)
            poblacion[i]->imprimir();
    }

    void ordenarPoblacion(){
        for (int i = 0; i < cantPoblacion; i++){
            for (int j = 0; j < cantPoblacion-1; j++){
                if(poblacion[j]->id > poblacion[j+1]->id){
                    StructHumano * h1 = poblacion[j];
                    StructHumano * h2 = poblacion[j+1];
                    poblacion[j] = h2;
                    poblacion[j+1] = h1;
                }
            } 
        }  
    }
};

