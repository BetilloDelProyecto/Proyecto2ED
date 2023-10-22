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
            poblacion[i] = new StructHumano(nombres[numRandom(999)],apellidos[numRandom(14)],paises[numRandom(19)],creencias[numRandom(9)],profesiones[numRandom(19)],getDateTime());
        }
        cantPoblacion += cant;
    }
};

