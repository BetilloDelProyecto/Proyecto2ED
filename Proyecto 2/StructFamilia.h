#include <iostream>
#include "StructHumano.h"

#ifndef STRUCT_FAMILIA_H
#define STRUCT_FAMILIA_H

struct Heap{
    StructHumano * array[10000];
    int index;

    Heap(){
        index = 1;
    }

    StructHumano * peek(){
        if(index == 1)
            return nullptr;
        else
            return array[1];
    }

    int cantHumanos(){
    if(index == 0)
        return 0;
    else
        return index-1;
   }

    bool estaOrdenado(){
        if(array[1] != NULL){
            for (int i = 1; i < index; i++){
                if (i*2 < index)
                    if(array[i] != nullptr && array[i*2] != nullptr &&  array[i]->cantPecados() < array[i*2]->cantPecados())
                        return false;
                if (i*2+1 < index)
                    if(array[i] != nullptr && array[i*2+1] != nullptr && array[i]->cantPecados() < array[i*2+1]->cantPecados())
                        return false;
            }
            return true;
        }  
    }

    void ordenar(){
        StructHumano * h1 = nullptr,* h2  = nullptr;
        for (int i = 1; i < index; i++){
            if (i*2 <= index){
                if(array[i] != nullptr && array[i*2] != nullptr && array[i]->cantPecados() < array[i*2]->cantPecados()){
                    h1 = array[i];
                    h2 = array[i*2];
                    array[i] = h2;
                    array[i*2] = h1;
                }
            }
            if (i*2+1 <= index){
                if(array[i] != nullptr && array[i*2] != nullptr && array[i]->cantPecados()  < array[i*2+1]->cantPecados() ){
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
                array[1] = nullptr;
                index -=1;
                return borrado;
            }else{
                StructHumano * humano = array[index-1];
                StructHumano * borrado = array[1];
                array[index-1] = nullptr;
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

    string toString(){
        string res = "";
        for (int i = 1; i <  index; i++){
            StructHumano * h1 = array[i];
            if(h1 != nullptr)
                res += h1->toString() + "\n";
        }
        return res;
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
        cout << "\n____________________________________________________________________________________\n" << endl;
    }

    string toString(){
        string res = "";
        res += "Familia " + apellido + " de " + pais + "\n";
        if(personas != nullptr){
            res += personas->toString();
        }
        res += "\n____________________________________________________________________________________\n\n";
        return res;
    }

    int cantHumanos(){
        return personas->cantHumanos();
    }

    StructHumano * peek(){
            return personas->peek();
    }

   



};

#endif // STRUCT_FAMILIA_H
