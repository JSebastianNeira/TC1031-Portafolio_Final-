//
//  NodeQ.hpp
//  Doulby Link List
//
//  Created by Sebas Neira Gzz on 08/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#pragma once

#include <stdio.h>

template<class T>
struct NodeQ{
    T data;
    NodeQ<T>* next;
    NodeQ(T data);
    NodeQ(T data, NodeQ<T>* next);
};

template<class T>
NodeQ<T>::NodeQ(T data){
    this->data = data;
    this->next = NULL;
}

template<class T>
NodeQ<T>::NodeQ(T data, NodeQ<T>* next){
    this->data = data;
    this->next = next;
}

