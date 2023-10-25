#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>




#ifndef STRUCT_HUMANO_H
#define STRUCT_HUMANO_H


using namespace std;

string addPadding(string input, int targetSize, char paddingChar) {
    if (input.length() >= targetSize) {
        return input;
    }

    string result = input;
    while (result.length() < targetSize) {
        result += paddingChar;
    }

    return result;
}

void cargarNombres(string nombres[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Nombres.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        nombres[i++] = linea; 
    archivo.close();
}

void cargarApellidos(string apellidos[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Apellidos.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        apellidos[i++] = linea; 
    archivo.close();
}

void cargarProfesiones(string profesiones[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Profesiones.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        profesiones[i++] = linea; 
    archivo.close();
}

void cargarPaises(string paises[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Paises.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        paises[i++] = linea;
    archivo.close();
}

void cargarCreencias(string creencias[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Creencias.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        creencias[i++] = linea;
    archivo.close();
}

void cargarPecados(string pecados[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Pecados.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        pecados[i++] = linea; 
    archivo.close();
}

void cargarRedes(string redes[]){
    ifstream archivo("C:\\Users\\Amerc\\Documents\\TEC\\ESTRUCTURA_DATOS\\Proyecto2ED\\Proyecto2ED\\Proyecto 2\\Redes.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        redes[i++] = linea; 
    archivo.close();
}

int numRandom(int cant){
    std::mt19937 generador(std::random_device{}());
    std::uniform_int_distribution<int> distribucion(0, cant);
    int numeroAleatorio = distribucion(generador);
    return numeroAleatorio;
}

string getDateTime(){
	chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    struct tm* localTime = localtime(&currentTime);
    stringstream ss;
    ss << std::put_time(localTime, "%d-%m-%Y_%I-%M-%S");
    string dateTimeString = ss.str();
    return dateTimeString;
}

string getPecado(string redSocial){
    if(redSocial == "Tinder"){
        return "Lujuria";
    }else if (redSocial == "iFood"){
        return "Gula";
    }else if (redSocial == "Linkedin"){
        return "Avaricia";
    }else if (redSocial == "Netflix"){
        return "Pereza";
    }else if (redSocial == "Twitter"){
        return "Ira";
    }else if (redSocial == "Facebook"){
        return "Envidia";
    }else
        return "Soberbia"; 
}

struct StructRedSocial{
    int prefrerencia;
    string nombre;

    StructRedSocial(){
        prefrerencia = 0;
        nombre = "";
    }

    StructRedSocial(string _nombre,int _prefrerencia){
        nombre = _nombre;
        prefrerencia = _prefrerencia;
    }

    StructRedSocial(string _nombre){
        nombre = _nombre;
        prefrerencia = 0;
    }

    void imprimir(){
        cout << "Red: " << nombre << "\tGusto: " << prefrerencia << endl;
    }
};


struct StructPecado{
    int cantidad;
    string nombre;

    StructPecado(){
        cantidad = 0;
        nombre = "";
    }

    StructPecado(string _nombre){
        nombre = _nombre;
        cantidad = 0;
    }

    void imprimir(){
        cout << "Pecado: " << nombre << "\tCantidad: " << cantidad << endl;
    }
    
};

struct StructHumano{
    int id,cantAmigos,amigosEncontrados;
    string nombre,apellido,pais,creencia,profesion,nacimiento;
    StructPecado * pecados[7];
    string pecado[7];
    string red[7];
    StructHumano * amigos[100];
    StructRedSocial * redesSociales[7];
    bool vivo;
    bool condenado;
    bool salvado;


    StructHumano(){
        nombre = apellido = pais = creencia = profesion = nacimiento = "";
        id = cantAmigos = amigosEncontrados = 0;
    }

    StructHumano(int _id,string _nombre,string _apellido,string _pais,string _creencia,string _profesion, string _nacimiento){
        cantAmigos = amigosEncontrados = 0;
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        nacimiento = _nacimiento;
        vivo = true;
        condenado = false;
        salvado = false;
        cargarPecados(pecado);
        cargarRedes(red);
        for (int i = 0; i < 7; i++){
            pecados[i] = new StructPecado(pecado[i]);
            redesSociales[i] = new StructRedSocial(red[i],numRandom(100));
        }
        ordenarRedes();
    }

    void imprimir(){
        cout << "ID: " << to_string(id) << "\tNombre: " <<addPadding(nombre,1, ' ') << " " << addPadding(apellido,10, ' ') << "\tPais: " << 
        addPadding(pais,10, ' ') << "\tCreencia: " << addPadding(creencia,10, ' ') << "\tProfesion: " << addPadding(profesion,10, ' ') << "\tNacimiento: " << nacimiento << endl << "Amigos:\n";
        for (int i = 0; i < amigosEncontrados; i++){
            amigos[i]->imprimir2();
        }
        cout << "\nPecados:\n";
        for (int i = 0; i < 7; i++){
            pecados[i]->imprimir();
        }

        cout << "\nRedes:\n";
        for (int i = 0; i < 7; i++){
            redesSociales[i]->imprimir();
        }
        
        cout << "-----------------------------------------------------------------------------" << endl;
    }

    void imprimir2(){
        cout << "\tID: " << to_string(id) << "\tNombre: " << addPadding(nombre,1, ' ') << " " << addPadding(apellido,10, ' ') << "Pais: " << 
        addPadding(pais,10, ' ') << "Creencia: " << addPadding(creencia,10, ' ') << "Profesion: " << addPadding(profesion,10, ' ') << "Nacimiento: " << nacimiento << endl;
    }

    void ordenarRedes(){
        for (int i = 0; i < 7; i++){
            for (int j = 0; j < 7-1; j++){
                if(redesSociales[j]->prefrerencia < redesSociales[j+1]->prefrerencia){
                    StructRedSocial * r1 = redesSociales[j];
                    StructRedSocial * r2 = redesSociales[j+1];
                    redesSociales[j] = r2;
                    redesSociales[j+1] = r1;
                }
            }
        }
    }

    int getPreferencia(string redSocial){
        for (int i = 0; i < 7; i++){
            if(redesSociales[i]->nombre == redSocial){           
                switch (i){
                    case 0:
                        return 7;
                    case 1:
                        return 6;
                    case 2:
                        return 5;
                    case 3:
                        return 4;
                    case 4:
                        return 3;
                    case 5:
                        return 2;
                    case 6:
                        return 1;
                    default:
                        return 0;
                }
            }
        }
    }

    void hacerPublicacion1(const string& _red){
        for(int i = 0; i < amigosEncontrados; i++){
            for(int j = 0; j < 7; j++){
                if(amigos[i]->pecados[j]->nombre == _red){
                    amigos[i]->pecados[j]->cantidad += amigos[i]->getPreferencia(_red);
                }
            }
        }
    }

    void hacerPublicacion2(){
        string redFavorita = redesSociales[0]->nombre;
        string pecado = getPecado(redFavorita);
        for (int i = 0; i < amigosEncontrados; i++){
            for (int j = 0; j < 7; j++){
                if (amigos[i]->pecados[j]->nombre == pecado){
                    amigos[i]->pecados[j]->cantidad += amigos[i]->getPreferencia(redFavorita);
                }
            }
        }
    }

    void hacerPublicacion3(int cantRedes){
        cout << endl;
        for (int i = 0; i < amigosEncontrados; i++){
            for (int j = 0; j < cantRedes ; j++){
                string red = redesSociales[j]->nombre;
                string pecado = getPecado(red);
                for (int k = 0; k < 7; k++){
                    if (amigos[i]->pecados[k]->nombre == pecado){
                        amigos[i]->pecados[k]->cantidad += amigos[i]->getPreferencia(red);
                    }
                } 
            }
        }
    }

    void hacerPublicacion4(int cantRedes){
        cout << endl;
        for (int i = 0; i < amigosEncontrados; i++){
            for (int j = 0; j < cantRedes ; j++){
                string red = redesSociales[j]->nombre;
                string pecado = getPecado(red);
                for (int k = 0; k < 7; k++){
                    if (amigos[i]->pecados[k]->nombre == pecado){
                        amigos[i]->pecados[k]->cantidad += amigos[i]->getPreferencia(red);
                    }
                } 
            }
        }
    }

    int cantPecados(){
        int res = 0;
        for (int i = 0; i < 7; i++){
            res += pecados[i]->cantidad;
        }  
        return res;
    }

    int getCantidadPecado(string _pecado){
        for(int i = 0; i < 7; i++){
            if(pecados[i]->nombre == _pecado){
                return pecados[i]->cantidad;
            }
        }
    }


};

#endif // STRUCT_HUMANO_H