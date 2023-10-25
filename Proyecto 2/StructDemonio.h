#ifndef STRUCT_DEMONIO_H
#define STRUCT_DEMONIO_H

#include "StructHumano.h"
#include "StructFamilia.h"


struct Demonio{
    std::string nombre;
    std::string pecado;
    Heap * familias[200];
    int cantidadFamilias;

    Demonio(std::string _nombre, std::string _pecado){
        nombre = _nombre;
        pecado = _pecado;
        cantidadFamilias = 0;
    }

     void agregarFamilia(Heap * familia){
        familias[cantidadFamilias] = familia;
        cantidadFamilias++;
    }

    void condenar(){}
};

void cargarDemonios(Demonio *demonios[], int cantidadDemonios){
    std::string nombres[] = {"Asmodeo", "Belfegor", "Mammon", "Abadon", "Satan", "Belcebu", "Lucifer"};
    std::string pecados[] = {"Lujuria", "Gula", "Avaricia", "Pereza", "Ira", "Envidia", "Soberbia"};
    for (int i = 0; i < cantidadDemonios; i++){
        demonios[i] = new Demonio(nombres[i], pecados[i]);
    }
}



#endif // STRUCT_DEMONIO_H