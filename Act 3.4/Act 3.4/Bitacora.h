//
//  Bitacora.h
//  Act 3.4
//
//  Created by Sebas Neira Gzz on 25/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#pragma once
#include <string>
using namespace std;

struct Bitacora{
    int fecha;
    string mmm;
    int dia;
    int mes;
    string hhmmss;
    int hora;
    int minutos;
    int segundos;
    string ip;
    string mensaje;
    
    Bitacora();
    Bitacora(string mmm, int dia, string hhmmss, string ip, string mensaje);
    bool operator <(Bitacora bitacora);
    bool operator >(Bitacora bitacora);
    bool operator <=(Bitacora bitacora);
    bool operator >=(Bitacora bitacora);
    bool operator ==(Bitacora bitacora);
    bool operator !=(Bitacora bitacora);
    int mesInt(string mmm);
    friend ostream& operator<<(ostream& os, Bitacora bitacora);
    
};

bool Bitacora::operator <(Bitacora bitacora){
    string str1 = ip.substr(0,13);
    string str2 = bitacora.ip.substr(0,13);
    
    return str1 < str2;
}

bool Bitacora::operator >(Bitacora bitacora){
    string str1 = ip.substr(0,13);
    string str2 = bitacora.ip.substr(0,13);
    
    return str1 > str2;
}

bool Bitacora::operator <=(Bitacora bitacora){
    string str1 = ip.substr(0,13);
    string str2 = bitacora.ip.substr(0,13);
    
    return str1 <= str2;
}

bool Bitacora::operator >=(Bitacora bitacora){
    string str1 = ip.substr(0,13);
    string str2 = bitacora.ip.substr(0,13);
    
    return str1 >= str2;
}

bool Bitacora::operator ==(Bitacora bitacora){
    string str1 = ip.substr(0,13);
    string str2 = bitacora.ip.substr(0,13);
    
    return str1 == str2;
}

bool Bitacora::operator !=(Bitacora bitacora){
    string str1 = ip.substr(0,13);
    string str2 = bitacora.ip.substr(0,13);
    
    return str1 != str2;
}

ostream& operator<<(ostream& os, Bitacora bitacora){
    os << bitacora.mmm << " " << bitacora.dia << " " << bitacora.hhmmss << " " << bitacora.ip << " " << bitacora.mensaje << endl;
    return os;
}

Bitacora::Bitacora(){
    this->mmm = "Jan";
    this->mes = mesInt(mmm);
    this->dia = 1;
    this->hhmmss = "00:00:00";
    hora = stoi(hhmmss.substr(0,2));
    minutos = stoi(hhmmss.substr(3,2));
    segundos = stoi(hhmmss.substr(6,2));
    
    fecha = 100000000*mes + 1000000*dia + 10000*hora + 100*minutos + segundos;
    
    this->ip = "";
    this->mensaje = "";
    
}

Bitacora::Bitacora(string mmm, int dia, string hhmmss, string ip, string mensaje){
    this->mmm = mmm;
    this->mes = mesInt(mmm);
    this->dia = dia;
    this->hhmmss = hhmmss;
    hora = stoi(hhmmss.substr(0,2));
    minutos = stoi(hhmmss.substr(3,2));
    segundos = stoi(hhmmss.substr(6,2));
    
    fecha = 100000000*mes + 1000000*dia + 10000*hora + 100*minutos + segundos;
    
    this->ip = ip;
    this->mensaje = mensaje;
    
}

int Bitacora::mesInt(string mmm){
    if (mmm == "Jan"){
        return 1;
    }
    if (mmm == "Feb"){
        return 2;
    }
    if (mmm == "Mar"){
        return 3;
    }
    if (mmm == "Apr"){
        return 4;
    }
    if (mmm == "May"){
        return 5;
    }
    if (mmm == "Jun"){
        return 6;
    }
    if (mmm == "Jul"){
        return 7;
    }
    if (mmm == "Aug"){
        return 8;
    }
    if (mmm == "Sep"){
        return 9;
    }
    if (mmm == "Oct"){
        return 10;
    }
    if (mmm == "Nov"){
        return 11;
    }
    if (mmm == "Dec"){
        return 12;
    }
    
    return 0;
}
