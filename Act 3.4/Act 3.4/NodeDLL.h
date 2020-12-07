//
//  NodeDLL.h
//  Act 3.4
//
//  Created by Sebas Neira Gzz on 25/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//
#pragma once

#include <stdio.h>
#include "Bitacora.h"

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
