#include "StructHumano.h"
#include <cmath>
#include <cctype> 
#include "StructDemonio.h"
#include "StructArbol.h"
#include "StructCielo.h"
#include <unordered_set>
#include <cstdio>

#ifndef STRUCT_MUNDO_H
#define STRUCT_MUNDO_H

string toUpperCase(string str){
    for (char &c : str) {
        // Convertir el carácter a mayúsculas usando toupper
        c = std::toupper(c);
    }
    return str;
}

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

struct Demonio;
struct Cielo;



struct StructMundo{
    StructHumano * poblacion[100000];
    string nombres[1000];
    string apellidos[15];
    string profesiones[20];
    string paises[20];
    string creencias[10];
    string pecados[7];
    string red[7];
    int cantPoblacion;
    ArbolVida * arbol;
    
    Demonio * demonios[7];
    ArbolTernario * arbolTernarioAngeles;
    Cielo * cielo;


    StructMundo(){
        arbol = new ArbolVida();
        cantPoblacion = 0;
        cargarRedes(red);
        cargarNombres(nombres);
        cargarApellidos(apellidos);
        cargarProfesiones(profesiones);
        cargarPaises(paises);
        cargarCreencias(creencias);
        cargarDemonios(demonios, 7);
        cargarPecados(pecados);
        arbolTernarioAngeles = new ArbolTernario();
        cielo = new Cielo();
        
    }

    string toString(){
        string res = "";
        for (int i = 0; i < cantPoblacion; i++){
            res += poblacion[i]->toString();
        }
        return res;
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
                if(poblacion[j]->id > poblacion[j+1]->id){ // SE DA ERROR SI SE GENERAN 2 VECES LAS GENERACIONES
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

    StructHumano * buscar2(int id){
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->id == id)
                return poblacion[i];
        }
        return nullptr;
    }

    //Buscar en array
    StructHumano * buscarEnArray(int _id, StructHumano ** ptHumano){
        if(_id < (*ptHumano)->id){
            while(ptHumano != nullptr){
            ptHumano = ptHumano - 1;
                if((*ptHumano)->id == _id)
                    return *ptHumano;
                else if((*ptHumano)->id < _id)
                    return nullptr;
            }
        }else{
            if(_id > (*ptHumano)->id){
                while(ptHumano != nullptr){
                    ptHumano = ptHumano + 1;
                    if((*ptHumano)->id == _id)
                        return *ptHumano;
                    else if((*ptHumano)->id > _id)
                        return nullptr;    
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

    StructHumano * getMasPecador(){
        StructHumano * humanos[100000];
        int encontrados = 0;
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < demonios[i]->cantidadFamilias; j++)
                if(demonios[i]->familias[j]->peek() != nullptr)
                    humanos[encontrados++]  = demonios[i]->familias[j]->peek();
        
        for (int i = 0; i < encontrados-1; i++)
            for (int j = 0; j < encontrados-1; j++)
                if (humanos[i] != nullptr && humanos[i+1] != nullptr && humanos[i]->cantPecados() < humanos[i+1]->cantPecados()){
                    StructHumano * h1 = humanos[i];
                    StructHumano * h2 = humanos[i+1];
                    humanos[i] = h2;
                    humanos[i+1] = h1;
                }
        if(encontrados != 0)
            return humanos[0];
        else
            return nullptr; 
    }

    StructHumano * quitarMasPecador(){
        StructHumano * h1 = getMasPecador();
        if(h1 != nullptr){
            for (int i = 0; i < 7; i++)
                for (int j = 0; j < demonios[i]->cantidadFamilias; j++)
                    if (demonios[i]->familias[j]->peek() != nullptr && demonios[i]->familias[j]->peek()->id == h1->id){
                        return demonios[i]->familias[j]->borrar();
                    }
                    
        }else return nullptr;
    return nullptr;
    }


    void salvacion(){
        arbolTernarioAngeles->llenarNivel();
        StructHumano * h1 = nullptr;
        for (int i = 0; i < pow(3,arbolTernarioAngeles->nivel-1); i++){
            h1 = quitarMasPecador();
            if(h1 != nullptr){
                cielo->insertar(h1);
                arbolTernarioAngeles->insertarHumano(h1,arbolTernarioAngeles->raiz);
            }else
                cout << "No encontro pecador" << endl;
        }
    }

    int getGenteViva(){
        int res = 0;
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->vivo)
                res++;
        }
        return res;
    }

    int getGenteMuerta(){
        int res = 0;
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->condenado)
                res++;
        }
        return res;
    }

    int getGenteCielo(){
        int res = 0;
        for (int i = 0; i < cantPoblacion; i++){
            if(poblacion[i]->salvado)
                res++;
        }
        return res;
    } 

    void imprimirInfo(){
        cout << "\n\n______________INFO MUNDO______________" << endl;
        cout << "Cantidad de Poblacion: " << cantPoblacion << endl;
        StructHumano * h1 = getMasPecador();
        cout << "Humano mas pecador:\n";
        if(h1 != nullptr){
            h1->imprimir();
        }else{
            cout << "no hay pecador" << endl;
        }
        if(getGenteViva() > 0 || getGenteMuerta() > 0 || getGenteCielo() > 0 ){
            (static_cast<double>(getGenteViva()/static_cast<double>(cantPoblacion)))*100;
            cout << "Personas Vivas: " << getGenteViva() <<"\tPorcentaje: "  << (static_cast<double>(getGenteViva()/static_cast<double>(cantPoblacion)))*100 <<"%"<<endl;
            cout << "Personas en el infierno: " << getGenteMuerta() <<"\tPorcentaje: "<<  (static_cast<double>(getGenteMuerta()/static_cast<double>(cantPoblacion)))*100 <<"%" <<endl;
            cout << "Personas en el cielo: " << getGenteCielo() <<"\tPorcentaje: "  << (static_cast<double>(getGenteCielo()/static_cast<double>(cantPoblacion)))*100<<"%" <<endl;
        }else{
            cout << "Personas Vivas: " << getGenteViva() <<"\t\tPorcentaje: 0%" <<endl;
            cout << "Personas en el infierno: " << getGenteMuerta() <<"\t\tPorcentaje: 0%" <<endl;
            cout << "Personas en el cielo: " << getGenteCielo() <<"\t\tPorcentaje: 0%" <<endl;
        }
        cout << endl;
    }

    bool existeProfesion(string prof){
        for (int i = 0; i < 20; i++){
            //cout << toUpperCase( profesiones[i]) << "                " << toUpperCase(prof) << endl;
            if(toUpperCase( profesiones[i]) == toUpperCase(prof))
                return true;
        }
        return false;
    }

    bool existeFamilia(string apellido,string pais){
        for (int i = 0; i < cantPoblacion; i++)
            if(toUpperCase(poblacion[i]->apellido) == toUpperCase(apellido) && toUpperCase(poblacion[i]->pais) == toUpperCase(pais))
                return true;
        return false;
    }

    bool existeReligion(string rel){
        for (int i = 0; i < cantPoblacion; i++)
            if(toUpperCase(poblacion[i]->creencia) == toUpperCase(rel))
                return true;
        return false;
    }

    bool existeRed(string _red){
        for (int i = 0; i < 7; i++){
            string red_ = toUpperCase(red[i]);
            if( red_ == toUpperCase(_red))
                return true;
        }
        return false;
    }

    void enviarCorreo(){
        std::string subject = "Probando c++";
        std::string body = "Esto es una prueba de c++";
        std::string filepath = "DemoniosLogs/LogGeneral.txt";
        std::string command = "python email_sender.py \"" + subject + "\" \"" + body + "\" \"" + filepath + "\" > output.txt 2>&1";
        FILE * in = _popen(command.c_str(), "r");
        _pclose(in);
        
    }
};



#endif 

