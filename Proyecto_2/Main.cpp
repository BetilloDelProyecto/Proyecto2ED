#include "StructDemonio.h"
#include "StructHumano.h"
#include "StructMundo.h"
#include "StructCielo.h"
#include <iostream>
#include "StructArbol.h"
#include <cstdlib>

int main(){
/*     StructMundo * m1 = new StructMundo();
    m1->generarPoblacion(300);

    m1->imprimir();
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Islam");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Hinduismo");
    m1->buscarPorReligion("Bahai");
    m1->buscarPorReligion("Budismo");
    m1->buscarPorReligion("Budismo");
    
    //m1->imprimir();
    //cout << m1->poblacion[1]->cantPecados() << endl;
    cout << "-----------------------TESTING-------------" << endl;
    m1->demonios[1]->condenar((m1->poblacion), m1->cantPoblacion);
    //cout << m1->demonios[1]->familias[0]->personas->index << endl;
    m1->demonios[1]->imprimirFamilias();

    cout << "TESTEANDO LA VARA"  << endl;
    StructHumano * h1 = m1->quitarMasPecador();
    if (h1 != nullptr)
        h1->imprimir(); */

    StructMundo * m1 = new StructMundo();
    m1->generarPoblacion(1000);

    m1->arbol->inOrder(m1->arbol->raiz);

    cout << "-----------------------TESTING-------------" << endl;
    m1->arbolTernarioAngeles->llenarNivel();
    m1->arbolTernarioAngeles->imprimir(m1->arbolTernarioAngeles->raiz);
    
    cout << "-----------------------TESTING2-------------" << endl;
    //Envio de correos electronicos template
    std::string subject = "Probando c++";
    std::string body = "Esto es una prueba de c++";
    std::string filepath = "../Proyecto_2/Nombres.txt";

    std::string command = "python email_sender.py \"" + subject + "\" \"" + body + "\" \"" + filepath + "\"";
    system(command.c_str());
    return 0;
} 

