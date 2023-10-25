#ifndef STRUCT_DEMONIO_H
#define STRUCT_DEMONIO_H

#include "StructFamilia.h"
#include <algorithm>
#include <iterator>

struct Heap{
    StructHumano * array[10000];
    int index;

    Heap(){
        index = 1;
    }

    bool estaOrdenado(){
        for (int i = 1; i < index; i++){
            if (i*2 <= index)
                if(array[i]->cantPecados() < array[i*2]->cantPecados())
                    return false;
            if (i*2+1 <= index)
                if(array[i]->cantPecados() < array[i*2+1]->cantPecados())
                    return false;
        }
        return true;
    }

    void ordenar(){
        StructHumano * h1 = nullptr,* h2  = nullptr;
        for (int i = 1; i < index; i++){
            if (i*2 <= index){
                if(array[i]->cantPecados() < array[i*2]->cantPecados()){
                    h1 = array[i];
                    h2 = array[i*2];
                    array[i] = h2;
                    array[i*2] = h1;
                }
            }
            if (i*2+1 <= index){
                if(array[i] < array[i*2+1]){
                    h1 = array[i];
                    h2 = array[i*2+1];
                    array[i] = h2;
                    array[i*2+1] = h1;
                }
            }
        }
        if(!estaOrdenado())
            ordenar();        
    }

    void insertar(StructHumano * humano){
        array[index] = humano;
        
        ordenar();
        index += 1;
    }

    StructHumano * borrar(){
        if(index != 1){
            if(index == 2){
                StructHumano * borrado = array[1];
                array[1] = NULL;
                index -=1;
                return borrado;
            }else{
                StructHumano * humano = array[index-1];
                StructHumano * borrado = array[1];
                array[index-1] = NULL;
                array[1] = humano;
                index -= 2;
                ordenar();
                index += 1;
                return borrado;
            }

        }else return NULL;

    }

    void imprimir(){
        for (int i = 1; i <  index; i++){
            array[i]->imprimir();
            cout << endl;
        }
        
    }
};

struct Familia{
    string pais, apellido;
    Heap * personas;

    Familia(){
        pais = apellido = "";
        personas = new Heap();
    }

    Familia(string _pais,string _apellido){
        pais = _pais;
        apellido = _apellido;
        personas = new Heap();
    }

    void insertar(StructHumano * humano){
        if(personas != nullptr){
            personas->insertar(humano);
        }
    }

    StructHumano * borrar(){
        if(personas != nullptr){
            return personas->borrar();
        }
        return nullptr;
    }

    void imprimir(){
        cout << "Familia " << apellido << " de " << pais << endl;
        if(personas != nullptr){
            personas->imprimir();
        }
    }
};

struct Demonio{
    std::string nombre;
    std::string pecado;
    Familia * familias[200];
    int cantidadFamilias;

    Demonio(std::string _nombre, std::string _pecado){
        nombre = _nombre;
        pecado = _pecado;
        cantidadFamilias = 0;
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

    void condenar(StructHumano * _poblacion, int cantPoblacion){
        StructHumano * tmp[100000];
        std::copy(_poblacion, _poblacion + cantPoblacion, tmp);
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
        free(tmp);
    }

    void ordenarPorPecado(std::string pecado, StructHumano * poblacion[], int cantPoblacion){
        for (int i = 0; i < cantPoblacion; i++){
            for (int j = 0; j < cantPoblacion-1; j++){
                if(poblacion[j]->getCantidadPecado(pecado) > poblacion[j+1]->getCantidadPecado(pecado)){
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