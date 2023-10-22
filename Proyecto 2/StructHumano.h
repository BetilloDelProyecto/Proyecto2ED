#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

void cargarNombres(string nombres[]){
    ifstream archivo("Nombres.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
       nombres[i++] = linea; 
    archivo.close();
}

void cargarApellidos(string apellidos[]){
    ifstream archivo("Apellidos.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        apellidos[i++] = linea; 
    archivo.close();
}

void cargarProfesiones(string profesiones[]){
    ifstream archivo("Profesiones.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        profesiones[i++] = linea; 
    archivo.close();
}

void cargarPaises(string paises[]){
    ifstream archivo("Paises.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        paises[i++] = linea;
    archivo.close();
}

void cargarCreencias(string creencias[]){
    ifstream archivo("Creencias.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        creencias[i++] = linea;
    archivo.close();
}

void cargarPecados(string pecados[]){
    ifstream archivo("Pecados.txt");
    string linea;
    int i = 0;
    while (getline(archivo,linea))
        pecados[i++] = linea; 
    archivo.close();
}

void cargarRedes(string redes[]){
    ifstream archivo("Redes.txt");
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
        cout << "Nombre: " << nombre << "\tCantidad: " << cantidad << endl;
    }
    
};

struct StructHumano{
    int id;
    string nombre,apellido,pais,creencia,profesion,nacimiento;
    StructPecado * pecados[7];
    string pecado[7];
    string red[7];
    StructHumano * amigos[100];
    StructRedSocial * redesSociales[7];


    StructHumano(){
         nombre = apellido = pais = creencia = profesion = nacimiento = "";
         id = 0;
    }

    StructHumano(int _id,string _nombre,string _apellido,string _pais,string _creencia,string _profesion, string _nacimiento){
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        nacimiento = _nacimiento;
        cargarPecados(pecado);
        cargarRedes(red);
        for (int i = 0; i < 7; i++){
            pecados[i] = new StructPecado(pecado[i]);
            redesSociales[i] = new StructRedSocial(red[i]);
        }
    }

    void imprimir(){
        cout << "ID: " << to_string(id) << "\tNombre: " << nombre << "\tApellido: " << apellido << "\tPais: " << 
        pais << "\tCreencia: " << creencia << "\tProfesion: " << profesion << "\tNacimiento: " << nacimiento << endl;
    }


};
