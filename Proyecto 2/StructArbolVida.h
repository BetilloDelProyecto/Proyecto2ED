#ifndef STRUCT_ARBOL_VIDA_H
#define STRUCT_ARBOL_VIDA_H

#include "StructHumano.h"
#include "StructMundo.h"

struct ArbolVida;
struct Nodo;

int calcularNivel(int CantidadHumanos){
    int onePercent = CantidadHumanos/100;
    int nodos, nivel = 0;
    while(nodos < onePercent){
        nodos = 2^nivel - 1;
        nivel++;
    }
    return nivel;
}

struct Nodo{
    StructHumano *humano;
    Nodo *izq;
    Nodo *der;

    Nodo(StructHumano * _humano){
        this->humano = _humano;
        izq = nullptr;
        der = nullptr;
    }
};

struct ArbolVida{
    Nodo * raiz;

    ArbolVida(){
        raiz = nullptr;
    }

    //Determinar la cantidad de nodos en el arbol
    int contarNodo(Nodo * nodo){
        if(nodo == nullptr)
            return 0;
        else
            return 1 + contarNodo(nodo->izq) + contarNodo(nodo->der);
    }

    //Determinar si un id esta en el arbol
    bool esta(int id, Nodo * nodo){
        if(nodo == nullptr)
            return false;
        else if(nodo->humano->id == id)
            return true;
        else if(id < nodo->humano->id)
            return esta(id, nodo->izq);
        else
            return esta(id, nodo->der);
    }

    //Insertar un humano en el arbol
    void insertar(StructHumano * humano, Nodo * nodo){
        if(nodo == nullptr)
            nodo = new Nodo(humano);
        else if(humano->id < nodo->humano->id)
            insertar(humano, nodo->izq);
        else
            insertar(humano, nodo->der);
    }


};

Nodo *ArrMundoToArbol(StructHumano *humanos[],int inicio, int final, int profundidadActual = 0, int nivel){
    if(inicio > final)
        return nullptr;
    int medio = (inicio + final)/2;
    Nodo *root = new Nodo(humanos[medio]);

    if(profundidadActual < nivel){
        root->izq = ArrMundoToArbol(humanos, inicio, medio-1, profundidadActual+1, nivel);
        root->der = ArrMundoToArbol(humanos, medio+1, final, profundidadActual+1, nivel);
    }
    return root;
    
}

ArbolVida* generarArbol(StructMundo * mundo){
    ArbolVida * arbol = new ArbolVida();
    int nodos = calcularNivel(mundo->cantPoblacion);
    Nodo * raiz = ArrMundoToArbol(mundo->poblacion, 0, mundo->cantPoblacion-1, 0, nodos);
    arbol->raiz = raiz;
    return arbol;
}



#endif // STRUCT_ARBOL_VIDA_H
