#include "StructMundo.h"


int main(){
    StructMundo * m1 = new StructMundo();
    m1->generarPoblacion(500);
    m1->generarArbol();
    m1->arbol->inOrder(m1->arbol->raiz);
    cout << m1->poblacion[0]->id << endl;
    if(m1->buscar(134123, m1->arbol->raiz,m1->arbol->altura(m1->arbol->raiz), 1) != nullptr){
        cout << "Encontrado" << endl;
    }

/*     StructHumano * h1 = new StructHumano(12,"Beto","Alvarez","CR","cristo","coding","hoy");
    StructHumano * h2 = new StructHumano(12,"Alfredo","Badilla","CR","cristo","coding","hoy");
    h1->amigos[0] = h2;
    h1->amigosEncontrados = 1;
    h1->cantAmigos = 10;
    h1->imprimir();
    h1->hacerPublicacion4(4);
    cout << "\n\n--------------TESTING" << endl;
    h2->imprimir(); */
    return 0;
} 

