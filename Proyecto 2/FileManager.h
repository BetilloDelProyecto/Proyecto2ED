#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

struct logs{

    std::string demonio;

    logs(std::string _demonio){
        demonio = _demonio;
    }

std::string formatDateTime(const std::chrono::system_clock::time_point& time) {
    // Convert time_point to time_t
    std::time_t t = std::chrono::system_clock::to_time_t(time);
    // Convert time_t to tm struct
    std::tm tm = *std::localtime(&t);
    // Format the date and time as a string
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d_%I-%M-%S_%p");
    std::string str = ss.str();
    // Replace the underscore with a space and add AM/PM
    size_t pos = str.find("_");
    str.replace(pos, 1, " ");
    return str;
}


std::string formatDate(const std::chrono::system_clock::time_point& time) {
    // Convert time_point to time_t
    std::time_t t = std::chrono::system_clock::to_time_t(time);
    // Convert time_t to tm struct
    std::tm tm = *std::localtime(&t);
    // Format the date and time as a string
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d");
    std::string str = ss.str();
    // Replace the underscore with a space and add AM/PM
    return str;
}

void logCondenacion(std::string nombreDemonio, int num,  std::string nombreHumano, std::string apellidoHumano, std::string pais, int pecados, std::string tipoPecado){
    std::string path = "DemoniosLogs/logGeneral.txt";
    std::ofstream file(path,std::ios::app);
    if(file.is_open()){
        file << formatDateTime(std::chrono::system_clock::now()) + " Humano " + std::to_string(num) + " " + nombreHumano + " " + apellidoHumano + " " + pais +
        " Murio el " + formatDate(std::chrono::system_clock::now()) + " condenado por " + std::to_string(pecados) + " pecados de " + tipoPecado + "\n"; 
        }
    file.close();
    }

void finLog(){
    std::string path = "DemoniosLogs/logGeneral.txt";
    std::ofstream file(path,std::ios::app);
    if(file.is_open()){
        file << "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    file.close();
}

void inicioLog(){
    std::string path = "DemoniosLogs/logGeneral.txt";
    std::ofstream file(path,std::ios::app);
    if(file.is_open()){
        file << "--------------------- " + demonio + "---------------------\n";
    }
    file.close();
}

};
#endif // FILEMANAGER_H