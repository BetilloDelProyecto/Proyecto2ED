#include "StructDemonio.h"
#include "StructHumano.h"
#include "StructMundo.h"
#include "StructCielo.h"
#include <iostream>
#include "StructArbol.h"
#include <cstdlib>

int main(){
    StructMundo * m1 = new StructMundo();
    m1->generarPoblacion(300);

    //m1->imprimir();
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Islam");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Hinduismo");
    m1->buscarPorReligion("Budismo");
    m1->buscarPorReligion("Sikhismo");
    m1->buscarPorReligion("Jainismo");
    m1->buscarPorReligion("Zoroastrismo");
    m1->buscarPorReligion("Bahai");
    m1->buscarPorReligion("Shintoismo");
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Islam");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Hinduismo");
    m1->buscarPorReligion("Budismo");
    m1->buscarPorReligion("Sikhismo");
    m1->buscarPorReligion("Jainismo");
    m1->buscarPorReligion("Zoroastrismo");
    m1->buscarPorReligion("Bahai");
    m1->buscarPorReligion("Shintoismo");
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Islam");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Hinduismo");
    m1->buscarPorReligion("Budismo");
    m1->buscarPorReligion("Sikhismo");
    m1->buscarPorReligion("Jainismo");
    m1->buscarPorReligion("Zoroastrismo");
    m1->buscarPorReligion("Bahai");
    m1->buscarPorReligion("Shintoismo");
    m1->buscarPorReligion("Cristianismo");
    m1->buscarPorReligion("Islam");
    m1->buscarPorReligion("Judaismo");
    m1->buscarPorReligion("Hinduismo");
    m1->buscarPorReligion("Budismo");
    m1->buscarPorReligion("Sikhismo");
    m1->buscarPorReligion("Jainismo");
    m1->buscarPorReligion("Zoroastrismo");
    m1->buscarPorReligion("Bahai");
    m1->buscarPorReligion("Shintoismo");
    //m1->imprimir();

    for (int i = 0; i < 7; i++){
        m1->demonios[i]->condenar(m1->poblacion,m1->cantPoblacion);
    }
    
    m1->salvacion();
    m1->arbolTernarioAngeles->imprimir(m1->arbolTernarioAngeles->raiz);
        
    
    /*
    StructMundo * m1 = new StructMundo();
    StructHumano * h1 = new StructHumano(1,"beto","alvarez","cr","cristo","code","ya");
    StructHumano * h3 = new StructHumano(2,"alfredo","alvarez","cr","cristo","code","ya");
    ArbolTernario * t1 = new ArbolTernario();
    t1->imprimir(t1->raiz);
    t1->llenarNivel();
    cout << "\n\nLLENAR NIVEL que es esto: " << endl << endl;
    
    t1->insertarHumano(h1,t1->raiz);
    t1->insertarHumano(h3,t1->raiz);
    t1->imprimir(t1->raiz);
    cout << "test index arbol: " << pow(3,t1->nivel-1) << endl;
    */
    
    cout << "-----------------------TESTING2-------------" << endl;
    //Envio de correos electronicos template
    std::string subject = "Probando c++";
    std::string body = "Esto es una prueba de c++";
    std::string filepath = "../Proyecto_2/Nombres.txt";

    std::string command = "python email_sender.py \"" + subject + "\" \"" + body + "\" \"" + filepath + "\"";
    system(command.c_str());
    return 0;
} 

