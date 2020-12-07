//
//  IP.h
//  Act 3.4
//
//  Created by Sebas Neira Gzz on 25/10/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef IP_h
#define IP_h


#include <string>
using namespace std;

struct IP{
    string ip;
    int num;
    
    IP();
    IP(string ip,int num);
    bool operator <(IP ip);
    bool operator >(IP ip);
    bool operator <=(IP ip);
    bool operator >=(IP ip);
    bool operator ==(IP ip);
    bool operator !=(IP ip);
    friend ostream& operator<<(ostream& os, IP ip);
    
};

bool IP::operator <(IP ip){
    int num1 = num;
    int num2 = ip.num;
    
    return num1 < num2;
}

bool IP::operator >(IP ip){
    int num1 = num;
    int num2 = ip.num;
    
    return num1 > num2;
}

bool IP::operator <=(IP ip){
    int num1 = num;
    int num2 = ip.num;
    
    return num1 <= num2;
}

bool IP::operator >=(IP ip){
    int num1 = num;
    int num2 = ip.num;
    
    return num1 >= num2;
}

bool IP::operator ==(IP ip){
    int num1 = num;
    int num2 = ip.num;
    
    return num1 == num2;
}

bool IP::operator !=(IP ip){
    int num1 = num;
    int num2 = ip.num;
    
    return num1 != num2;
}

ostream& operator<<(ostream& os, IP ip){
    os << ip.ip << " " << ip.num << endl;
    return os;
}

IP::IP(){
    this->ip = "";
    this->num = 0;
    
}

IP::IP(string ip, int num){
    this->ip = ip;
    this->num = num;
    
}




#endif /* IP_h */
