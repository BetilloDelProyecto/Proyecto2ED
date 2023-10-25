#include "StructFamilia.h"
#include <algorithm>
#include <iterator>
#include <iostream>

#ifndef STRUCT_DEMONIO_H
#define STRUCT_DEMONIO_H
struct Demonio{
    std::string nombre;
    std::string pecado;
    Familia * familias[200];
    int cantidadFamilias;

    Demonio(std::string _nombre, std::string _pecado){
        nombre = _nombre;
        pecado = _pecado;
        cantidadFamilias = 0;
        for(int i = 0; i < 200; i++){
            familias[i] = nullptr;
        }
    }

     void agregarFamilia(Familia * familia){
        familias[cantidadFamilias] = familia;
        cantidadFamilias++;
    }

    void agregarHumano(StructHumano * humano){
        if(familias[0] == nullptr){
            familias[0] = new Familia(humano->pais, humano->apellido);
            familias[0]->insertar(humano);
            cantidadFamilias++;
        } else{
            for(int i =0; i < cantidadFamilias; i++){
                if(familias[i]->pais == humano->pais && familias[i]->apellido == humano->apellido){
                    familias[i]->insertar(humano);
                    break;
                } else{
                    if(i == cantidadFamilias-1){
                        familias[cantidadFamilias] = new Familia(humano->pais, humano->apellido);
                        familias[cantidadFamilias]->insertar(humano);
                        cantidadFamilias++;
                        break;
                    }
                }
            }
        }
    }

    void condenar(StructHumano ** _poblacion, int cantPoblacion){
        StructHumano * tmp[100000];
        for(int i = 0; i < cantPoblacion; i++){
            cout << (*(_poblacion[i])).id << endl;
            tmp[i] = (_poblacion[i]);
        }
        ordenarPorPecado(pecado, tmp, cantPoblacion);
        int cantCondenador = cantPoblacion * 0.05;
        for(int i = 0; i < cantCondenador; i++){
            if(i == cantPoblacion-1 ){
                break;
            } else{
                if(tmp[i]->condenado == true || tmp[i]->salvado == true){
                    cantCondenador++;
                } else{
                    tmp[i]->condenado = true;
                    tmp[i]->vivo = false;
                    agregarHumano(tmp[i]);
                }
            }
        }
    }

    void ordenarPorPecado(std::string pecado, StructHumano * poblacion[], int cantPoblacion){
        for (int i = 0; i < cantPoblacion; i++){
            for (int j = 0; j < cantPoblacion-1; j++){
                if(poblacion[j]->getCantidadPecado(pecado) < poblacion[j+1]->getCantidadPecado(pecado)){
                    StructHumano * h1 = poblacion[j];
                    StructHumano * h2 = poblacion[j+1];
                    poblacion[j] = h2;
                    poblacion[j+1] = h1;
                }
            } 
        }  
    }

    void imprimirFamilias(){
        for(int i = 0; i < cantidadFamilias; i++){
            familias[i]->imprimir();
        }
    }

};

void cargarDemonios(Demonio *demonios[], int cantidadDemonios){
    std::string nombres[] = {"Asmodeo", "Belfegor", "Mammon", "Abadon", "Satan", "Belcebu", "Lucifer"};
    std::string pecados[] = {"Lujuria", "Gula", "Avaricia", "Pereza", "Ira", "Envidia", "Soberbia"};
    for (int i = 0; i < cantidadDemonios; i++){
        demonios[i] = new Demonio(nombres[i], pecados[i]);
    }
}



#endif // STRUCT_DEMONIO_H