//
//  NodeDLL.h
//  Evidencia_4.3_Grafos
//
//  Created by Sebas Neira Gzz on 05/12/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#pragma once

#include <stdio.h>


template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T data);
    Node(T data, Node<T>* next, Node<T>* prev);
};

template<class T>
Node<T>::Node(T data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* next,Node<T>* prev){
    this->data = data;
    this->next = next;
    this->prev = prev;
}
