//
//  main.cpp
//  Act 3.4
//
//  Created by Sebas Neira Gzz on 25/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Bitacora.h"
#include "Heap.h"
#include "IP.h"

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

DoublyLinkedList<Bitacora> leerArchivos(){
    ifstream entrada;
    string mmm;
    int dia;
    string hhmmss;
    string ip;
    string mensaje;
    DoublyLinkedList<Bitacora> list;
    
    entrada.open("/Users/sebasneiragzz/Desktop/EL PEPE/Estructura de Datos/Act 3.4/Act 3.4/bitacora2.txt");
    if (entrada.fail()){
        cout << "No se encontró el archivo"<< endl;
    } else{
        while(entrada >> mmm >> dia >> hhmmss >> ip){
            getline(entrada,mensaje);
            Node<Bitacora>* nodo = new Node<Bitacora>(Bitacora(mmm, dia, hhmmss, ip, mensaje));
            list.addLast(nodo->data);
        
        }
    }
    entrada.close();
    return list;
}

DoublyLinkedList<IP> agrupIP(DoublyLinkedList<Bitacora> list){
    DoublyLinkedList<IP> listIPS;
    int num = 1;
    int i = 1;
    
    while(i < list.getSize()){
        if(list.getData(i) == list.getData(i+1)){
            num++;
        } else {
            listIPS.addLast(IP(list.getData(i).ip.substr(0,13),num));
            num = 1;
        }
        i++;
    }
    
    listIPS.addLast(IP(list.getData(i).ip.substr(0,13),num));
    
    
    return listIPS;
}

void top5(DoublyLinkedList<IP> listIPS){
    for(int i = 1; i < 6;i++){
        cout << listIPS[i] << endl;
    }
    
}


int main() {
    DoublyLinkedList<Bitacora> list = leerArchivos();
    
    cout << endl << "Heap Sort Descending" << endl;
    HeapSort(list,"descending");
    list.print();
    
    cout << endl << "Grouped IPs Descending" << endl;
    DoublyLinkedList<IP> listIPS = agrupIP(list);
    HeapSort(listIPS,"descending");
    listIPS.print();
    
    cout << endl << "Top 5 IPs:" << endl;
    top5(listIPS);
    
}
