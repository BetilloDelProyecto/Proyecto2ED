#include <iostream>
#include "StructHumano.h"

#ifndef STRUCT_FAMILIA_H
#define STRUCT_FAMILIA_H

struct Heap{
    StructHumano * array[10000];
    int index;

    Heap(){
        index = 0;
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
        
    void heapify(int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && array[left]->cantPecados() < array[smallest]->cantPecados())
            smallest = left;

        if (right < n && array[right]->cantPecados() < array[smallest]->cantPecados())
            smallest = right;

        if (smallest != i) {
            std::swap(array[i], array[smallest]);
            heapify(n, smallest);
        }
    }

    // main function to do heap sort
    void ordenar() {
        int n = index;
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);
        // Heap sort
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end
            std::swap(array[0], array[i]);
            // Call max heapify on the reduced heap
            heapify(i, 0);
        }

        print();
    }
    void print(){
        for (int i = 0; i < index; ++i)
            std::cout << array[i]->cantPecados() << " ";
        std::cout << "\n";
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
