#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

#include "StructHumano.h"
#include <cmath>
#include "StructDemonio.h"

struct ArbolVida;
struct Nodo;
int calcularNivel(int CantidadHumanos);
Nodo *ArrMundoToArbol(StructHumano *humanos[],int inicio, int final, int profundidadActual, int nivel);


struct Nodo{
    StructHumano **humano;
    Nodo *izq;
    Nodo *der;

    Nodo(StructHumano ** _humano){
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
        else if((*(nodo->humano))->id == id)
            return true;
        else if(id < (*(nodo->humano))->id)
            return esta(id, nodo->izq);
        else
            return esta(id, nodo->der);
    }

    void inOrder(Nodo* nodo) {
        if (nodo != nullptr) {
            inOrder(nodo->izq);
            std::cout << (*(nodo->humano))->id << " ";
            inOrder(nodo->der);
        }
    }

    

    int altura(Nodo * nodo){
        if(nodo == nullptr)
            return 0;
        else
            return 1 + max(altura(nodo->izq), altura(nodo->der));
    }

    //Insertar un humano en el arbol
    void insertar(StructHumano ** humano, Nodo * nodo){
        if(nodo == nullptr)
            nodo = new Nodo(humano);
        else if((*humano)->id < (*nodo->humano)->id)
            insertar(humano, nodo->izq);
        else
            insertar(humano, nodo->der);
    }


};

int calcularNivel(int CantidadHumanos){
    int onePercent = CantidadHumanos/100;
    int nodes = 0;
    int nivel = 0;
    while(nodes < onePercent){
        nodes = pow(2,nivel+1) - 1;
        nivel++;
    }
    return nivel;
}

Nodo *ArrMundoToArbol(StructHumano *humanos[],int inicio, int final, int profundidadActual, int nivel){
    if(inicio > final)
        return nullptr;
    int medio = (inicio + final)/2;
    Nodo *root = new Nodo(&(humanos[medio]));

    if(profundidadActual < nivel){
        root->izq = ArrMundoToArbol(humanos, inicio, medio-1, profundidadActual+1, nivel);
        root->der = ArrMundoToArbol(humanos, medio+1, final, profundidadActual+1, nivel);
    }
    return root;
}

struct StructMundo{
    StructHumano * poblacion[100000];
    string nombres[1000];
    string apellidos[15];
    string profesiones[20];
    string paises[20];
    string creencias[10];
    int cantPoblacion;
    ArbolVida * arbol;
    Demonio * demonios[7];


    StructMundo(){
        arbol = new ArbolVida();
        cantPoblacion = 0;
        cargarNombres(nombres);
        cargarApellidos(apellidos);
        cargarProfesiones(profesiones);
        cargarPaises(paises);
        cargarCreencias(creencias);
        cargarDemonios(demonios, 7);
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
        generarArbol();
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

    void generarArbol(){
        int nivel = calcularNivel(cantPoblacion);
        Nodo * raiz = ArrMundoToArbol(poblacion, 0, cantPoblacion-1, 1, nivel);
        arbol->raiz = raiz;
    }

    void buscarPorReligion(string religion){
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->creencia == religion){
                poblacion[i]->hacerPublicacion2();
            }
        }
    }

    void buscarPorProfesion(string profesion,int cantRedes){
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->profesion == profesion){
                poblacion[i]->hacerPublicacion3(cantRedes);
            }
        } 
    }

    void buscarPorFamilia(string pais,string apellido,int cantRedes){
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->pais == pais && poblacion[i]->apellido == apellido){
                poblacion[i]->hacerPublicacion3(cantRedes);
            }
        } 
    }

    StructHumano * buscar(int id, Nodo * nodo, int nivelAlcanzar, int nivelActual ){
        if(nodo == nullptr)
            return nullptr;
        else if((*(nodo->humano))->id == id)
            return *nodo->humano;
        else if(nivelActual >= nivelAlcanzar)
            return buscarEnArray(id, nodo->humano);
        else if(id < (*nodo->humano)->id)
            return buscar(id, nodo->izq, nivelAlcanzar, nivelActual+1);
        else
            return buscar(id, nodo->der, nivelAlcanzar, nivelActual+1);
    }

    //FALTA OPTIMIZAR COMPLEJIDAD O^CANTIDADHUMANOS - CANTIDADHUMANOS[INDEX]
    StructHumano * buscarEnArray(int _id, StructHumano ** ptHumano){
        if(_id < (*ptHumano)->id){
            while(ptHumano != nullptr){
            ptHumano = ptHumano - 1;
                if((*ptHumano)->id == _id)
                    return *ptHumano;
            }
        }else{
            if(_id > (*ptHumano)->id){
                while(ptHumano != nullptr){
                    ptHumano = ptHumano + 1;
                    if((*ptHumano)->id == _id)
                        return *ptHumano;
                }
            }
        }
        return nullptr;
    }

    //Hacer publicacion dado un id y una red social
    void publicar1(int id, string red){
        StructHumano * humano = buscar(id, arbol->raiz, arbol->altura(arbol->raiz), 1);
        if(humano != nullptr){
            humano->hacerPublicacion1(red);
        }else{
            cout << "No se encontro el humano" << endl;
        }
    }
};



#endif 

