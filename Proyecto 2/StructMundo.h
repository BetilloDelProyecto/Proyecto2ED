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
        int repeticiones = 0;
        for (int i = cantPoblacion; i < cant+cantPoblacion; i++){
            int id = numRandom(999999);
            if(!(existeID(id))){
                poblacion[i] = new StructHumano(id,nombres[numRandom(999)],apellidos[numRandom(14)],paises[numRandom(19)],creencias[numRandom(9)],profesiones[numRandom(19)],getDateTime());
                poblacion[i]->cantAmigos = numRandom(100);
            }else{
                repeticiones += 1;
                cant += 1; 
            }
            
        }
        cantPoblacion += cant;
        cantPoblacion -= repeticiones;
        ordenarPoblacion();
        buscarAmigos();
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

    bool existeID(int id){
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->id == id){
                return true;
            }  
        }  
        return false;
    }

    void buscarAmigos(){
        for (int i = 0; i < cantPoblacion; i++){
            StructHumano * humano = poblacion[i];
            for (int j = 0; j < cantPoblacion ; j++){
                StructHumano * amigo = poblacion[j];
                if(amigo->id != humano->id){
                    if(amigo->pais == humano->pais && (amigo->creencia == humano->creencia || amigo->profesion == humano->profesion || amigo->apellido == humano->apellido)){
                        if (humano->amigosEncontrados < humano->cantAmigos){
                            humano->amigos[humano->amigosEncontrados] = amigo;
                            humano->amigosEncontrados += 1;
                        }
                    }   
                }else
                    continue;
            }
        }
    }
};

