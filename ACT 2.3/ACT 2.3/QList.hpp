//
//  QList.hpp
//  Doulby Link List
//
//  Created by Sebas Neira Gzz on 08/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef QList_h
#define QList_h

#include "NodeQ.hpp"
#include <iostream>
using namespace std;

template<class T>
class QueuedList{
private:
    NodeQ<T>* head;
    NodeQ<T>* tail;
    int size;
    
public:
    QueuedList();
    T dequeue();
    void enqueue(T data);
    T front();
    T back();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
QueuedList<T>::QueuedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
T QueuedList<T>::front(){
    return tail->data;
}

template<class T>
T QueuedList<T>::back(){
    return head->data;
}

template<class T>
T QueuedList<T>::dequeue(){
    if(!isEmpty()){
        T value = head->data;
        head = head->next;
        size--;
        return value;
    } else {
        throw runtime_error("La lista no contiene elementos");
    }
}

template<class T>
void QueuedList<T>::enqueue(T data){
    if(!isEmpty()){
        NodeQ<T>* aux = tail;
        tail = new NodeQ<T>(data,NULL);
        
        aux->next = tail;
        size++;
    } else{
        tail = new NodeQ<T>(data);
        head = tail;
        size++;
    }
}

template<class T>
int QueuedList<T>::getSize(){
    return size;
}


template<class T>
void QueuedList<T>::clear(){
    NodeQ<T>* aux = head;
    NodeQ<T>* prev = head;
    while(aux != NULL){
        prev = aux;
        aux = aux->next;
        delete prev;
        size--;
    }
}
    
template<class T>
void QueuedList<T>::print(){
    NodeQ<T>* aux = head;
    for (int i = 0; i < size ; i++){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;

}

template<class T>
bool QueuedList<T>::isEmpty(){
    return size == 0;
}

#endif /* QList_h */
