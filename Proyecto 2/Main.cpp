#include "StructMundo.h"


int main(){
    StructMundo * m1 = new StructMundo(); 
    m1->generarPoblacion(2);
    m1->poblacion[1]->imprimir();
    return 0;
} 

