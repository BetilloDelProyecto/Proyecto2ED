#include "StructMundo.h"

#ifndef STRUCT_MENU_H
#define STRUCT_MENU_H

void gestionMenu(StructMundo * mundo);
void menuBuscarHumano(StructMundo * mundo);
void menuInfierno(StructMundo * mundo);
void menuCondenar(StructMundo * mundo);
void menuMundo(StructMundo * mundo);
void menuGenerarPoblacion(StructMundo * mundo);
void menuHacerPublicacion(StructMundo * mundo);
void menuPublicarPorID(StructMundo  * mundo);
void menuPublicarPorReligion(StructMundo * mundo);
void menuPublicarPorProfesion(StructMundo * mundo);
void menuPublicarPorFamilia(StructMundo * mundo);
void menuCielo(StructMundo * mundo);



bool tryStringToInt(string str) {
    try {
        stoi(str); // Intentar convertir el string a int
        return true; // Conversión exitosa
    } catch (const exception& e) {
        return false; // Error al convertir
    }
}

void gestionMenu(StructMundo * mundo){
    int opcion = 0;
    string frase;
    while (opcion != 9){
        cout << "_________BATALLA POR LAS ALMAS_________" << endl;
        cout << "1. Mundo" << endl;
        cout << "2. Humanos"<< endl;
        cout << "3. Infierno"<< endl;
        cout << "4. Cielo" << endl;
        cout << "5. Salir" << endl;
        cout << "Escoge una opcion: ";
        getline(cin, frase);
        if (tryStringToInt(frase) == true){
            int num = stoi(frase);
            switch (num){
                case 1://
                    menuMundo(mundo);
                    break;
                case 2://
                    menuBuscarHumano(mundo);
                    break;
                case 3://
                    menuInfierno(mundo);
                    break;
                case 4://
                    menuCielo(mundo);
                    break;
                case 5://
                    if(mundo->getGenteMuerta() > mundo->getGenteCielo() )
                        cout << "Ha gando el Infierno, personas en el cielo: " << mundo->getGenteCielo() << "\t Personas en el infierno: " << mundo->getGenteMuerta() << "\t Personas vivas: " <<  mundo->getGenteViva() <<  endl;
                    else if (mundo->getGenteMuerta() < mundo->getGenteCielo())
                         cout << "Ha gando el Cielo, personas en el cielo: " << mundo->getGenteCielo() << "\t Personas en el infierno: " << mundo->getGenteMuerta() << "\t Personas vivas: " <<  mundo->getGenteViva() <<  endl;
                    else
                        cout << "Hay un empate, personas en el cielo: " << mundo->getGenteCielo() << "\t Personas en el infierno: " << mundo->getGenteMuerta() << "\t Personas vivas: " <<  mundo->getGenteViva() <<  endl;
                    cout << "\n\nAdios\n\n";
                    return;
                default:
                    cout << "Opcion invalida\n" << endl;
                    break;
            }
        } else cout << "Opcion invalida\n" << endl;
    }
}

void menuCielo(StructMundo * mundo){
    string frase;
    cout << "\n_________Cielo_________" << endl;
    cout << "1. Generar Salvacion"<< endl;
    cout << "2. Imprimir Arbol de Angeles"<< endl;
    cout << "3. Imprimir el Hash"<< endl;
    cout << "Escoge una opcion: ";
    getline(cin, frase);
    if (tryStringToInt(frase)){
        int num = stoi(frase);
        switch (num){
            case 1://
                if(mundo->getGenteMuerta() >= pow(3,mundo->arbolTernarioAngeles->nivel)){
                    mundo->salvacion();
                    mundo->enviarCorreoAngeles();
                }
                else
                    cout << "\nNo hay la suficiente cantidad de muertos,condena mas personas\n" << endl;
                break;
            case 2://
                cout << "\n\n___________Arbol del Cielo___________" << endl;
                mundo->arbolTernarioAngeles->imprimir(mundo->arbolTernarioAngeles->raiz);
                cout << "\n\n_________Fin Arbol del Cielo_________" << endl;
                break;
            case 3://
                cout << "\n\n___________Hash del Cielo___________" << endl;
                mundo->cielo->imprimir();
                cout << "\n\n_________Fin Hash del Cielo_________" << endl;
                break;
            default:
                cout << "\nOpcion invalida\n\n" << endl;
                break;
            
        }
    } else cout << "\nOpcion invalida\n\n" << endl;  
}

void menuBuscarHumano(StructMundo * mundo){
    string id;
    cout << "\n_________Buscar Humano_________" << endl;
    cout << "Digita un ID: ";
    getline(cin, id);
    if (tryStringToInt(id)){
        int _id = stoi(id);
        StructHumano * h1 = mundo->buscar2(_id);
        if(h1 != nullptr){
            h1->imprimir();
            cout << "\n\n-----------------FIN DEL HUMANO-----------------\n\n";
        }else   cout << "\nNo existe un humano con ese ID\n\n" << endl;  
    } else cout << "\nOpcion invalida\n\n" << endl;  
}

void menuInfierno(StructMundo * mundo){
    string frase;
    cout << "\n_________INFIERNO_________" << endl;
    cout << "1. Condenar" << endl;
    cout << "2. Imprimir Infierno"<< endl;
    cout << "3. Condenar con todos los demonios"<< endl;
    cout << "Escoge una opcion: ";
    getline(cin, frase);
    if (tryStringToInt(frase)){
        int num = stoi(frase);
        switch (num){
            case 1://
                menuCondenar(mundo);
                break;
            case 2://
                for (int i = 0; i < 7; i++){
                    mundo->demonios[i]->imprimirFamilias();
                }
                
                break;
            case 3://
                for (int i = 0; i < 7; i++){
                    mundo->demonios[i]->condenar(mundo->poblacion,mundo->cantPoblacion);
                }
                mundo->enviarCorreoDemonios();
                cout << "\n\nCondenacion existosa...\n\n";
                break;
            default:
                cout << "\nOpcion invalida\n\n" << endl;
                break;
            
        }
    } else cout << "\nOpcion invalida\n\n" << endl;  
}

void menuCondenar(StructMundo * mundo){
    string frase;
    cout << "\n_________DEMONIOS_________" << endl;
    cout << "1. Asmodeo" << endl;
    cout << "2. Belfegor" << endl;
    cout << "3. Mammon" << endl;
    cout << "4. Abadon" << endl;
    cout << "5. Satan" << endl;
    cout << "6. Belcebu" << endl;
    cout << "7. Lucifer" << endl;
    cout << "Digita el numero del demonio: ";
    getline(cin, frase);
    if (tryStringToInt(frase)){
        int num = stoi(frase);
        if( num > 0  || num <= 7){
            if(mundo->cantPoblacion > 0){
                mundo->demonios[num-1]->condenar(mundo->poblacion,mundo->cantPoblacion);
                cout<< "\n\nCondenacion existosa...\n\n";
            }else cout << "\nNo hay humanos generados...\n\n" << endl;  
        }else cout << "\nOpcion invalida,tiene que estar entre 1 y 7\n\n" << endl;  
    }else cout << "\nOpcion invalida\n\n" << endl;  
}


void menuMundo(StructMundo * mundo){
    string frase;
    cout << "\n_________MUNDO_________" << endl;
    cout << "1. Info" << endl;
    cout << "2. Generar poblacion"<< endl;
    cout << "3. Imprimir Arbol"<< endl;
    cout << "4. Hacer una publicacion"<< endl;
    cout << "5. Imprimir todos los humanos"<< endl;
    cout << "Escoge una opcion: ";
    getline(cin, frase);
    if (tryStringToInt(frase) == true){
        int num = stoi(frase);
        switch (num){
            case 1://
                mundo->imprimirInfo();
                break;
            case 2://
                menuGenerarPoblacion(mundo);
                break;
            case 3://
                cout << "\n\n________Arbol Del Mundo________" << endl;
                mundo->arbol->inOrder(mundo->arbol->raiz);
                cout << endl << endl;
                break;
            case 4://
                menuHacerPublicacion(mundo);
                break;
            case 5://
                cout << "\n\n________Humanos En El Mundo________" << endl;
                mundo->imprimir();
                cout << "\n\n_____________________________________\n";
                break;
            default:
                cout << "Opcion invalida\n\n" << endl;
                break;
            
        }
    } else cout << "Opcion invalida\n\n" << endl;    
}


void menuGenerarPoblacion(StructMundo * mundo){
    string frase;
    cout << "\n\n_____________Generar poblacion_____________"<< endl;
    cout << "Cantidad de la generacion: ";
    getline(cin, frase);
    if (tryStringToInt(frase) == true){
        int num = stoi(frase);
        if (num+mundo->cantPoblacion < 100000){
            mundo->generarPoblacion(num);
            cout << "Generacion existosa...\n" << endl;
        }else{
            cout << "La cantidad no puede ser ingresada, habria mas de 100000 humanos\n" << endl;
        }
    }else cout << "Opcion invalida\n" << endl;
    
}

void menuHacerPublicacion(StructMundo * mundo){
    string frase;
    cout << "\n\n_____________Hacer una publicacion_____________"<< endl;
    cout << "1. Publicar por ID" << endl;
    cout << "2. Publicar por religion" << endl;
    cout << "3. Publicar por profesion" << endl;
    cout << "4. Publicar por familia" << endl;
    cout << "Escoge una opcion: ";
    getline(cin, frase);
    if (tryStringToInt(frase) == true){
        int num = stoi(frase);
        switch (num){
            case 1://
                menuPublicarPorID(mundo);
                break;
            case 2://
                menuPublicarPorReligion(mundo);
                break;
            case 3://
                menuPublicarPorProfesion(mundo);
                break;
            case 4://
                menuPublicarPorFamilia(mundo);
                break;
            default:
                cout << "\nOpcion invalida\n\n" << endl;
                break;
        }
    }else cout << "\nOpcion invalida\n" << endl;
    
}

void menuPublicarPorID(StructMundo  * mundo){
    string ID,red;
    cout << "\n\n_____________Publicacion por ID_____________"<< endl;
    cout << "Digita un ID: ";
    getline(cin, ID);
    cout << "\nDigita una red social: ";
    getline(cin, red);
    if(tryStringToInt(ID)){
        int id = stoi(ID);
        StructHumano * h1 = mundo->buscar2(id);
        if(h1 != nullptr){
            if(mundo->existeRed(red)){
                h1->hacerPublicacion1(red);
                cout << "\nPublicacion existosa...\n" << endl;
            }else cout << "\nEsa red no existe\n" << endl;
        }else cout << "\nEse ID no existe\n" << endl;
        
    }else cout << "\nOpcion Invalida\n" << endl;
}

void menuPublicarPorReligion(StructMundo * mundo){
    string frase,cant;
    cout << "\n\n_____________Publicacion por religion_____________"<< endl;
    cout << "Escoge una religion: ";
    getline(cin, frase);
    cout << frase << endl;
    if(mundo->existeReligion(frase)){
        mundo->buscarPorReligion(frase);
        cout << "\n\nPublicacion exitosa\n\n";
    }else cout << "\nNo existe esa religion\n" << endl;
}


void menuPublicarPorProfesion(StructMundo * mundo){
    string frase,cant;
    cout << "\n\n_____________Publicacion por profesion_____________"<< endl;
    cout << "Digita una profesion: ";
    getline(cin, frase);
    if(mundo->existeProfesion(frase)){
        cout << "Cantidad de redes: ";
        getline(cin, cant);
        if (tryStringToInt(cant)){
            int can = stoi(cant);
            if(can > 0 && can < 8){
                mundo->buscarPorProfesion(frase,can);
                cout << "\nPublicacion exitosa...\n";   
            }else cout << "\nOpcion invalida, tiene que ser de 1 a 7\n";   
        }else cout << "\nOpcion invalida\n";
    }else cout << "Esa profesion no existe\n" << endl;
    
    
}

void menuPublicarPorFamilia(StructMundo * mundo){
    string apellido,pais,cant;
    cout << "\n\n_____________Publicacion por familia_____________"<< endl;
    cout << "Digita un apellido: ";
    getline(cin, apellido);
    cout << "Digita un pais: ";
    getline(cin, pais);
    if(mundo->existeFamilia(apellido,pais)){
        cout << "Cantidad de redes: ";
        getline(cin, cant);
        if (tryStringToInt(cant)){
            int can = stoi(cant);
            if(can > 0 && can < 8){
                mundo->buscarPorFamilia(pais,apellido,can);
                cout << "\nPublicacion creada con exito\n" << endl;
            }else cout << "\nOpcion invalida, tiene que ser de 1 a 7\n" << endl;   
        }else cout << "\nOpcion invalida\n" << endl;
    }else cout << "\nEsa familia no existe\n" << endl;
}

#endif