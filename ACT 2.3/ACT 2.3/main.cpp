//
//  main.cpp
//  ACT 2.3
//
//  Created by Sebas Neira Gzz on 08/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#include <iostream>
#include "DList.hpp"
using namespace std;

int main() {
    
    DoulbyList<int> lista;
    
    lista.addFirst(100);
    lista.addFirst(10);
    lista.addLast(40);
    lista.addLast(30);
    lista.print();
    
    lista.sort();
    lista.print();
    
    return 0;
}
