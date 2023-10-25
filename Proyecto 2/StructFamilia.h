#include "StructMundo.h"

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
        StructHumano * humano = array[index-1];
        StructHumano * borrado = array[1];
        array[index-1] = NULL;
        if(index == 2){
            array[1] = nullptr;
        }
        array[1] = humano;
        index -= 1;
        ordenar();
        return borrado;
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
        personas->insertar(humano);
    }

    StructHumano * borrar(){
        return personas->borrar();
    }

    void imprimir(){
        cout << "Familia " << apellido << " de " << pais << endl;
        personas->imprimir();
    }


};
