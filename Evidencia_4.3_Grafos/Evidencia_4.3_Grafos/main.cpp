//
//  main.cpp
//  Evidencia_4.3_Grafos
//
//  Created by Sebas Neira Gzz on 22/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


#include "Graph.h"
#include "DLL.h"
#include "Ip.h"
#include "Heap.h"



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

template<class T>
DoublyLinkedList<IP> agrupIP(Graph<T> Grafo){
    DoublyLinkedList<IP> listIPs;
    
    for (int v=0; v<Grafo.vertices.size(); v++){
        listIPs.addLast(IP(Grafo.vertices[v],Grafo.adjList[v].size()));
    }
    
    return listIPs;
}

template<class T>
void HeapSort(DoublyLinkedList<T> &list, string order = "ascending"){
    if(!list.isEmpty()){
        Heap<T> heapAux(list);
        list.clear();
        while (!heapAux.isEmpty()){
            T aux = heapAux.remove();
            if (order == "ascending"){
                list.addFirst(aux);
            } else {
                list.addLast(aux);
            }
            
        }
    }
}


int main() {
    vector<string> vertices = leerVertex();
    Graph<string> Grafo(vertices);
    leerTarget(Grafo);
    
    cout << "Lista de Ips con Adyacencias" << endl << endl;
    Grafo.print();
    
    DoublyLinkedList<IP> listIPs = agrupIP(Grafo);
    HeapSort(listIPs, "descending");
    cout << endl << "Ip con # de Adyacencias" << endl << endl;
    listIPs.print();
    
    cout << endl << "Top Ip:"<< endl;
    cout << listIPs[1] << endl;
    cout << listIPs[2] << endl;
    return 0;
}
