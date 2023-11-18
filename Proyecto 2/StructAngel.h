#include <iostream>
#include "StructHumano.h"
#include "FileManager.h"

#ifndef STRUCTANGEL_H
#define STRUCTANGEL_H

struct Angel{
    std::string nombre;
    int version;
    int generacion;
    StructHumano *h;
    logsAngeles *logsInstance;

    Angel(int _version, int _generacion, StructHumano *_h){
        nombre = selectRandomNombre();
        version = _version;
        generacion = _generacion;
        h = _h;
    }

    Angel(int _version, int _generacion){
        nombre = selectRandomNombre();
        version = _version;
        generacion = _generacion;
        h = nullptr;
    }

    Angel(std::string _nombre, int _version, int _generacion){
        nombre = _nombre;
        version = _version;
        generacion = _generacion;
        h = nullptr;
    }

    std::string selectRandomNombre(){
        std::string nombres[10] = {"Miguel", "Nuriel", "Aniel", "Rafael", "Gabriel", "Shamsiel", "Raguel", "Uriel", "Azrael", "Sariel"};
        int random = rand() % 10;
        return nombres[random];
    }

    void logInit(){
        logsInstance = new logsAngeles();
    }


};


#endif // STRUCTANGEL_H
