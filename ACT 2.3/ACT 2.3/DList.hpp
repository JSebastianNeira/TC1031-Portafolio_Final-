//
//  DList.hpp
//  ACT 2.3
//
//  Created by Sebas Neira Gzz on 08/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef DList_h
#define DList_h

#include<iostream>
#include "Node.hpp"
#include "QList.hpp"
using namespace std;

template<class T>
class DoulbyList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    
public:
    DoulbyList();
    void addFirst(T data);
    void addLast(T data);
    bool deleteData(T data);
    bool deleteAt(int pos);
    T getData(int pos);
    void updateAt(int pos, T data);
    void updateData(T dataBuscar, T data);
    int findData(T data);
    
    void insertAt(int pos, T data);
    void clear();
    void merge(int ini, int med, int fin);
    void mergeSort(int ini, int fin);
    void sort();
    
    bool isEmpty();
    void print();
    void printTail();
    
    void operator=(DoulbyList<T> list);
    T& operator[](int pos);
    void operator=(initializer_list<T> list);
};

template <class T>
T& DoulbyList<T>::operator[](int pos){
    if (pos < 0 || pos >= size){
        throw out_of_range("Posición invalida");
    } else{
        Node<T>* aux = head;
        if (pos == 0){
            return aux->data;
        } else {
            for (int i = 0; i < pos; i++){
            aux = aux->next;
            }
            return aux->data;
        }
    }
}

template <class T>
void DoulbyList<T>::operator=(initializer_list<T> list){
    if (!isEmpty()){
        for (T i : list){
            addLast(i);
        }
    } else{
        throw runtime_error("Error: Linked List no esta vacia");
    }
}

template <class T>
void DoulbyList<T>::operator=(DoulbyList<T> list){
    clear();
    for(int i = 0;i<list.size;i++){
        addLast(list[i]);
    }
}

template<class T>
DoulbyList<T>::DoulbyList(){
    head = NULL;
    tail = NULL;
    size = 0;
    
}

template<class T>
void DoulbyList<T>::addFirst(T data){
    if(head == NULL){
        head = new Node<T>(data);
        tail = head;
        size++;
        
    } else {
        Node<T>* aux = head;
        head = new Node<T>(data,head,NULL);
        
        aux->prev = head;
        size++;
    }
}

template<class T>
void DoulbyList<T>::addLast(T data){
    if(tail == NULL){
        tail = new Node<T>(data);
        head = tail;
        size++;
        
    } else {
        Node<T>* aux = tail;
        tail = new Node<T>(data,NULL,tail);
        
        aux->next = tail;
        size++;
    }
}

template<class T>
bool DoulbyList<T>::deleteData(T data){
    if(!isEmpty()){
        if(head->data == data){
            Node<T>* aux = head;
            head = aux->next;
            delete aux;
            size--;
            return true;
        } else if (tail->data == data){
            Node<T>* aux = tail;
            tail = aux->prev;
            delete aux;
            size--;
            return true;
        } else{
            if((head->next != NULL)){
                Node<T>* aux = head->next;
                Node<T>* auxPrev = head;
                
                while (aux->next != tail){
                    if(aux->data == data){
                        auxPrev->next = aux->next;
                        aux->next->prev = auxPrev;
                        delete aux;
                        size --;
                        return true;
                    } else{
                        auxPrev = aux;
                        aux = aux->next;
                    }
                }
            }
        }
    }
    return false;
}


template<class T>
bool DoulbyList<T>::deleteAt(int pos){
   if (pos >= 0 && pos < size){
       if(!isEmpty()){
           if(pos == 0){
               Node<T>* aux = head;
               head = aux->next;
               delete aux;
               size--;
               return true;
           } else if(pos == size-1){
               Node<T>* aux = tail;
               tail = aux->prev;
               delete aux;
               size--;
               return true;
           } else {
               Node<T>* aux = head->next;
               Node<T>* auxPrev = head;
               for (int i = 0; i < pos-1; i++){
                   auxPrev = aux;
                   aux = aux->next;
               }
               auxPrev->next = aux->next;
               aux->next->prev = auxPrev;
               delete aux;
               size --;
               return true;
           }
       }
   }
   return false;
}



template<class T>
T DoulbyList<T>::getData(int pos){
    if (pos >= 0 && pos < size){
        if(pos == 0){
            return head->data;
            
        } else if(pos == size-1){
            return tail->data;
            
        } else if (pos <= (size-1)/2){
            Node<T>* aux = head;
            
            for(int i = 0; i<pos; i++){
                aux = aux->next;
            }
            return aux->data;
        } else if (pos > (size-1)/2){
            Node<T>* aux = tail;
            
            for(int i = 0; i<size-1-pos; i++){
                aux = aux->prev;
            }
            return aux->data;
        }
    }
    throw out_of_range("Posición invalida");
}

template<class T>
void DoulbyList<T>::updateAt(int pos, T data){
    if (pos >= 0 && pos < size){
        if (pos == 0){
            head->data = data;
            
        } else if (pos == size-1){
            tail->data = data;
            
        }else if (pos <= (size-1)/2){
            Node<T>* aux = head;
            
            for(int i = 0; i<pos; i++){
                aux = aux->next;
            }
            aux->data = data;
        } else if (pos > (size-1)/2){
            Node<T>* aux = tail;
            
            for(int i = 0; i<size-1-pos; i++){
                aux = aux->prev;
            }
            aux->data = data;
        }
    } else{
        throw out_of_range("Posición invalida");
    }
}

template<class T>
void DoulbyList<T>::updateData(T dataBuscar, T data){
    Node<T>* aux = head;
    bool encontrado = false;
    for (int i = 0; i < size; i++){
        if (aux->data == dataBuscar){
            aux->data = data;
            encontrado = true;
        } else {
            aux = aux->next;
        }
    }
    
    if (!encontrado){
        throw out_of_range("El dato no se encuentra en la lista");
    }
}

template<class T>
int DoulbyList<T>::findData(T data){
    int posI = 0;
    int posF = size-1;
    int posM = (posI + posF) / 2;
    bool found = false;

    
    while (posI<=posF && !found){
        if (data < getData(posM)){
            posF = posM-1;
            
        } else{
            if (data > getData(posM)){
                posI = posM + 1;
            } else{
                if (data == getData(posM)){
                    found = true;
                }
            }
        }
        
        posM = (posI + posF) / 2;
    }
    
    if (found){
        return posM;
    } else {
        throw runtime_error("Elemento no encontrado");
    }
}

template<class T>
void DoulbyList<T>::insertAt(int pos, T data){
    if (pos >= 0 && pos <= size){
        if(!isEmpty()){
            if(pos == 0){
                Node<T>* aux = head;
                head = new Node<T>(data,head,NULL);
                
                aux->prev = head;
                size++;
                
            }else if (pos == size){
                Node<T>* aux = tail;
                tail = new Node<T>(data,NULL,tail);
                
                aux->next = tail;
                size++;
            }else {
                Node<T>* aux = head->next;
                Node<T>* auxPrev = head;
                for (int i = 0; i < pos-1; i++){
                    auxPrev = aux;
                    aux = aux->next;
                }
                Node<T>* nuevo = new Node<T>(data, aux, auxPrev);
                auxPrev->next = nuevo;
                aux->prev = nuevo;
                size ++;
                
            }
        }
    }
}

template<class T>
void DoulbyList<T>::clear(){
    Node<T>* aux = head;
    Node<T>* auxPrev = head;

    while(aux != NULL){
        auxPrev = aux;
        aux = aux->next;
        delete auxPrev;
        size--;
    }
    tail->data = NULL;
    tail->prev = NULL;
}


template<class T>
void DoulbyList<T>::merge(int ini, int mid, int fin){
    QueuedList<T> left;
    QueuedList<T> rigth;
    int pos,f1,f2,i,j;
    
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;
    
    for(i = 0; i<f1;i++){
        left.enqueue(getData(ini+i));
    }
    for(j = 0; j<f2;j++){
        rigth.enqueue(getData(mid+1+j));
    }
    
    
    i = 0;
    j = 0;
    
    while(i<f1 && j<f2){
        if (left.front() <= rigth.front()){
            updateAt(pos, left.dequeue());
            i++;
        } else{
            updateAt(pos, rigth.dequeue());
            j++;
        }
        pos++;
    }
    
    while (i<f1){
        updateAt(pos, left.dequeue());
        i++;
        pos++;
    }
    while (j<f2){
        updateAt(pos, rigth.dequeue());
        j++;
        pos++;
    }
}

template<class T>
void DoulbyList<T>::mergeSort(int ini, int fin){
    if(ini < fin){
        int mid = (ini + fin)/2;
        mergeSort(ini, mid);
        mergeSort(mid+1, fin);
        
        merge(ini,mid,fin);
    }
}

template<class T>
void DoulbyList<T>::sort(){
    mergeSort(0,size-1);
}

//Empiezan Metodos Print

template<class T>
void DoulbyList<T>::print(){
    Node<T>* aux = head;
    for (int i = 0; i < size ; i++){
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
    
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    
}

template<class T>
void DoulbyList<T>::printTail(){
    Node<T>* aux = tail;
    for (int i = size; i > 0 ; i--){
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
    
    cout << "Tail: " << tail->data << endl;
    cout << "Head: " << head->data << endl;
    
}


//Metodos Complementarios

template<class T>
bool DoulbyList<T>::isEmpty(){
    return size == 0;
}

#endif /* DList_h */
