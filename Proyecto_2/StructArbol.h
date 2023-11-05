#include "StructAngel.h"

#ifndef STRUCTARBOL_H
#define STRUCTARBOL_H


struct NodoAngel{
    Angel * angel;
    NodoAngel * izq;
    NodoAngel * der;
    NodoAngel * cen;

    NodoAngel(Angel * _angel){
        angel = _angel;
        izq = nullptr;
        der = nullptr;
        cen = nullptr;
    }

    void imprimir(){
        cout << angel->nombre << " "<< angel->version << " " <<angel->generacion <<   endl;
    }
};

struct ArbolTernario{
    NodoAngel * raiz;
    int nivel;

    ArbolTernario(){
        raiz = nullptr;
        nivel = 0;
    }

    void insertarInicial(){
        raiz = new NodoAngel(new Angel("El Dios", 1, nivel++));
        raiz->izq = new NodoAngel(new Angel("Serafines", 1, nivel));
        raiz->cen = new NodoAngel(new Angel("Querubines", 2, nivel));
        raiz->der = new NodoAngel(new Angel("Tronos", 3, nivel++));
    }

    void llenarNivel(NodoAngel* nodo, int nivelActual, int nivelDeseado, int& contador) {
        if (nodo == nullptr) {
            return;
        }

        if (nivelActual == nivelDeseado) {
            if (nodo->izq == nullptr) {
                nodo->izq = new NodoAngel(new Angel(contador++, nivel));
            }
            if (nodo->cen == nullptr) {
                nodo->cen = new NodoAngel(new Angel(contador++, nivel));
            }   
        if (nodo->der == nullptr) {
            nodo->der = new NodoAngel(new Angel(contador++, nivel));
        }
    } else {
        llenarNivel(nodo->izq, nivelActual + 1, nivelDeseado, contador);
        llenarNivel(nodo->cen, nivelActual + 1, nivelDeseado, contador);
        llenarNivel(nodo->der, nivelActual + 1, nivelDeseado, contador);
    }
}

    void llenarNivel() {
        int contador = 1;
        int _nivel = nivel -1;
        llenarNivel(raiz, 0, _nivel, contador);
        nivel++;
    }

    void imprimir(NodoAngel * nodo){
        if (nodo == nullptr)
            return;
        imprimir(nodo->izq);
        nodo->imprimir();
        imprimir(nodo->cen);
        imprimir(nodo->der);
    }





};

#endif // STRUCTARBOL_H
