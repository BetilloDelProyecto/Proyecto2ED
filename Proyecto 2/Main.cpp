#include "StructMundo.h"


int main(){
    StructMundo * m1 = new StructMundo();
    // m1->generarPoblacion(500);
    // m1->imprimir();
    // m1->generarArbol();
    // m1->arbol->inOrder(m1->arbol->raiz);
    StructHumano * h1 = new StructHumano(12,"Beto","Alvarez","CR","cristo","coding","hoy");
    StructHumano * h2 = new StructHumano(12,"Alfredo","Badilla","CR","cristo","coding","hoy");
    h1->amigos[0] = h2;
    h1->amigosEncontrados = 1;
    h1->cantAmigos = 10;
    h1->imprimir();
    h1->hacerPublicacion4(4);
    cout << "\n\n--------------TESTING" << endl;
    h2->imprimir();
    return 0;
} 

