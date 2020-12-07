//
//  main.cpp
//  Evidencia 5.2 Hash
//
//  Created by Sebas Neira Gzz on 06/12/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


#include "Graph.h"
#include "Hash.h"



vector<string> leerVertex(){
    ifstream entrada;
    string source;
    vector<string> list;
    
    entrada.open("/Users/sebasneiragzz/Desktop/EL PEPE/Estructura de Datos/Evidencia_4.3_Grafos/Evidencia_4.3_Grafos/B_Source.txt");
    if (entrada.fail()){
        cout << "No se encontró el archivo"<< endl;
    } else{
        while(getline(entrada,source)){
            
            list.push_back(source);
        
        }
    }
    entrada.close();
    return list;
}

template<class T>
Graph<T> leerTarget(Graph<T> &Grafo){
    ifstream entrada;
    string mmm;
    int dia;
    string hhmmss;
    string source;
    string target;
    string mensaje;
    
    entrada.open("/Users/sebasneiragzz/Desktop/EL PEPE/Estructura de Datos/Evidencia_4.3_Grafos/Evidencia_4.3_Grafos/Bitacora.txt");
    if (entrada.fail()){
        cout << "No se encontró el archivo"<< endl;
    } else{
        while(entrada >> mmm >> dia >> hhmmss >> source >> target){
            getline(entrada,mensaje);
            Grafo.addEdge(source,target);
        }
    }
    entrada.close();
    return Grafo;
}




int main() {
    string ip;
    
    vector<string> vertices = leerVertex();
    Graph<string> Grafo(vertices);
    leerTarget(Grafo);
    
    
    Hash vertexHash(vertices);
    cout << endl << "Los vertices se han añadido a la Hash Table de manera correcta." << endl;
    cout << endl << "Lista de Vertices añadidos:" << endl;
    vertexHash.print();
    
    cout << endl << "Ingresa Ip: " << endl;
    cin >> ip;
    
    
    cout << endl << "Lista de adyacencias para la ip: " << endl;
    Grafo.getAdjList(ip);
    
    
    return 0;
}
