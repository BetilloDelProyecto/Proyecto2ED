#include "StructFamilia.h"


int main(){
    StructMundo * m1 = new StructMundo();
    m1->generarPoblacion(500);

    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Islam");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Hinduismo");
    m1->buscarPorReligion("Bahai");
    m1->buscarPorReligion("Budismo");
    m1->buscarPorReligion("Budismo");




    //m1->arbol->inOrder(m1->arbol->raiz);
    //cout << m1->poblacion[0]->id << endl;
/*     if(m1->buscar(134123, m1->arbol->raiz,m1->arbol->altura(m1->arbol->raiz), 1) != nullptr){
        cout << "Encontrado" << endl;
    }
 */
/*     StructHumano * h1 = new StructHumano(12,"Beto","Alvarez","CR","cristo","coding","hoy");
    StructHumano * h2 = new StructHumano(14,"Alfredo","Badilla","CR","cristo","coding","hoy");
    h1->amigos[0] = h2;
    h1->amigosEncontrados = 1;
    h1->cantAmigos = 10;
    h2->amigos[0] = h1;
    h2->amigosEncontrados = 1;
    h2->cantAmigos = 10;
    h2->hacerPublicacion4(1);
    h1->hacerPublicacion4(4);

    //h1->imprimir();
    //h2->imprimir();
    cout << "\n\n--------------TESTING" << endl;
    Familia * f1 = new Familia("Costa Rica", "Alvarez");
    f1->insertar(h1);
    f1->imprimir();
    f1->insertar(h2);
    f1->imprimir(); */




    return 0;
} 

