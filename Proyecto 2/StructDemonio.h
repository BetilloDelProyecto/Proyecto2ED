#include "StructFamilia.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include "FileManager.h"

#ifndef STRUCT_DEMONIO_H
#define STRUCT_DEMONIO_H
struct Demonio{
    std::string nombre;
    std::string pecado;
    Familia * familias[350];
    int cantidadFamilias;
    logs *logsInstance;

    Demonio(std::string _nombre, std::string _pecado){
        nombre = _nombre;
        pecado = _pecado;
        cantidadFamilias = 0;
        logsInstance = new logs(_nombre);
        for(int i = 0; i < 200; i++){
            familias[i] = nullptr;
        }
    }

     void agregarFamilia(Familia * familia){
        familias[cantidadFamilias] = familia;
        cantidadFamilias++;
    }

    int cantHumanos(){
        int res = 0;
        for (int i = 0; i < cantidadFamilias; i++){
            res += familias[i]->cantHumanos();
        }
        return res;
    }

    void agregarHumano(StructHumano * humano){
        if(familias[0] == nullptr){
            familias[0] = new Familia(humano->pais, humano->apellido);
            familias[0]->insertar(humano);
            cantidadFamilias++;
        }else{
            for(int i = 0; i < cantidadFamilias; i++){
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
        std::copy(_poblacion, _poblacion + cantPoblacion, tmp);
/*         for(int i = 0; i < cantPoblacion; i++){
            tmp[i] = (_poblacion[i]);
        } */
        ordenarPorPecado(pecado, tmp, cantPoblacion);
        int pecadoresDelPecado = std::count_if(tmp, tmp + cantPoblacion, [this](StructHumano * h){return h->getCantidadPecado(pecado) > 0;});
        int cantCondenador = pecadoresDelPecado * 0.05;
        logsInstance->inicioLog();
        for(int i = 0; i < min(cantCondenador, cantPoblacion -1); i++){
            if(tmp[i]->condenado == true || tmp[i]->salvado == true){
                    cantCondenador++;
                } else{
                    tmp[i]->condenado = true;
                    tmp[i]->vivo = false;
                    agregarHumano(tmp[i]);
                    logsInstance->logCondenacion(nombre, i, tmp[i]->nombre, tmp[i]->apellido, tmp[i]->pais, tmp[i]->getCantidadPecado(pecado), pecado);
                }
            }
        logsInstance->finLog();
        }

    void ordenarPorPecado(std::string pecado, StructHumano * poblacion[], int cantPoblacion){
        std::sort(poblacion, poblacion + cantPoblacion, 
            [pecado](StructHumano* a, StructHumano* b) { 
                return a->getCantidadPecado(pecado) > b->getCantidadPecado(pecado); 
            });
}

    void imprimirFamilias(){
        cout << nombre << "\tPecado: "<< pecado << endl;
        for(int i = 0; i < cantidadFamilias; i++){
            cout << "hay familias: " << i << endl;
            familias[i]->imprimir();
        }

        cout << "_____________________________________FIN DEL DEMONIO_____________________________________\n" << endl;
    }

    string toString(){
        string res = "";
        res += nombre + "\tPecado: " + pecado + "\n";
        for(int i = 0; i < cantidadFamilias; i++){
            res += familias[i]->toString();
        }

        res += "\n_____________________________________FIN DEL DEMONIO_____________________________________\n\n";
        return res;
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