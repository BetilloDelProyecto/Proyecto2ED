#include "StructMundo.h"


int main(){
    StructMundo * m1 = new StructMundo(); 

    m1->generarPoblacion(500);
    //m1->imprimir();
    m1->generarArbol();
    m1->arbol->inOrder(m1->arbol->raiz);
    return 0;
} 

