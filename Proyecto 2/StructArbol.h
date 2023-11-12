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
        if(angel->h != nullptr){
            cout << "Nombre: "<<angel->nombre << "\tVersion: "<< angel->version << "\tGeneracion: " <<angel->generacion << "\nHumano Salvado:\n";
            angel->h->imprimir();
        }else{
            cout << "Nombre: "<<angel->nombre << "\tVersion: "<< angel->version << "\tGeneracion: " <<angel->generacion << "\nHumano Salvado: No ha salvado ha nadie...\n" << endl;
        }
            
    }

    string toString(){
        string res ="";
        if(angel->h != nullptr){
            res += "Nombre: " + angel->nombre + "\tVersion: " + to_string( angel->version) + "\tGeneracion: " + to_string(angel->generacion) + "\nHumano Salvado:\n";
            res += angel->h->toString();
        }else{
            res += "Nombre: " + angel->nombre + "\tVersion: " + to_string(angel->version) + "\tGeneracion: " + to_string(angel->generacion) + "\nHumano Salvado: No ha salvado ha nadie...\n\n";
        }
        return res;
    }
};

struct ArbolTernario{
    NodoAngel * raiz;
    int nivel;

    ArbolTernario(){
        raiz = nullptr;
        nivel = 0;
        insertarInicial();
    }

    bool estaHumano(StructHumano * h ,NodoAngel * root){
        if (root == nullptr){
            return false;
        }else if(root->angel->h == nullptr ){
            return false || estaHumano(h,root->izq) || estaHumano(h,root->cen) || estaHumano(h,root->der);
        }else if(root->angel->h != nullptr && h->id == root->angel->h->id){
            return true;
        }else
            return estaHumano(h,root->izq) || estaHumano(h,root->cen) || estaHumano(h,root->der);
        
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

    string toString(NodoAngel * nodo,string res){
        if (nodo == nullptr)
            return "";
        else{ 
            res += nodo->toString();
            return res + toString(nodo->izq,"") +  toString(nodo->cen,"") + toString(nodo->der,"");
        }
            
        
        
    }

    void insertarHumano(StructHumano * _h , NodoAngel * nodo){
        if(nodo != NULL && !estaHumano(_h,raiz)){
            if (nodo != nullptr){
                if(nodo->angel->nombre != "El Dios" && nodo->angel->nombre != "Serafines" && nodo->angel->nombre != "Querubines"  && nodo->angel->nombre != "Tronos" && nodo->angel->h == nullptr){
                    nodo->angel->h = _h;
                    return;
                }else{
                    insertarHumano(_h,nodo->izq);
                    insertarHumano(_h,nodo->cen);
                    insertarHumano(_h,nodo->der);
                }
            }
        }else return;
    }

    NodoAngel * getRaiz(){
        return raiz;
    }





};

#endif // STRUCTARBOL_H
