#include "StructArbolVida.h"


int main(){
    StructMundo * m1 = new StructMundo(); 

    m1->generarPoblacion(1000);
    m1->imprimir();
    ArbolVida * arbol = generarArbol(m1);
    return 0;
} 

