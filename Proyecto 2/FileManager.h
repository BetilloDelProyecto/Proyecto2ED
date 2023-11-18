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
        std::time_t t = std::chrono::system_clock::to_time_t(time);
        std::tm tm = *std::localtime(&t);
        std::stringstream ss;
        ss << std::put_time(&tm, "%Y-%m-%d_%I-%M-%S_%p");
        std::string str = ss.str();
        size_t pos = str.find("_");
        str.replace(pos, 1, " ");
        return str;
    }


    std::string formatDate(const std::chrono::system_clock::time_point& time) {
        std::time_t t = std::chrono::system_clock::to_time_t(time);
        std::tm tm = *std::localtime(&t);
        std::stringstream ss;
        ss << std::put_time(&tm, "%Y-%m-%d");
        std::string str = ss.str();
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
            file << "\n";
        }
        file.close();
    }

    void inicioLog(){
        std::string path = "DemoniosLogs/logGeneral.txt";
        std::ofstream file(path,std::ios::app);
        if(file.is_open()){
            file << "------------------------------------------- " + demonio + " -------------------------------------------\n";
        }
        file.close();
    }
};

struct logsAngeles{
    
    static int cantSalvados;

    logsAngeles(){
    }

    std::string formatDateTime(const std::chrono::system_clock::time_point& time) {
        std::time_t t = std::chrono::system_clock::to_time_t(time);
        std::tm tm = *std::localtime(&t);
        std::stringstream ss;
        ss << std::put_time(&tm, "%Y-%m-%d_%I-%M-%S_%p");
        std::string str = ss.str();
        size_t pos = str.find("_");
        str.replace(pos, 1, " ");
        return str;
    }

std::string formatDate(const std::chrono::system_clock::time_point& time) {
    std::time_t t = std::chrono::system_clock::to_time_t(time);
    std::tm tm = *std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d");
    std::string str = ss.str();
    return str;
}

void logSalvacion(std::string nombreHumano, std::string apellidoHumano, std::string pais, int pecados, std::string nombreAngel, int numAngel, int generacionAngel){
    std::string path = "AngelesLogs/logGeneral.txt";
    std::ofstream file(path,std::ios::app);
    if(file.is_open()){
        file << formatDateTime(std::chrono::system_clock::now()) + " Humano " + to_string(cantSalvados) + " "+ nombreHumano + " " + apellidoHumano + " " + pais +
        " Salvada el " + formatDate(std::chrono::system_clock::now()) + " por " + to_string(pecados) + " pecados por el angel " + nombreAngel + " " + to_string(numAngel) + " Generacion " + to_string(generacionAngel) +"\n"; 
        }
        cantSalvados++;
        file.close();
    }
};

int logsAngeles::cantSalvados = 0;

#endif // FILEMANAGER_H