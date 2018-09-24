//
//  Sq_list.cpp
//  Data Structure
//
//  Created by WeiYoang on 9/22/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "Sq_list.hpp"

Sq_list::Sq_list(){
    element=new int[defaut];
    size=defaut;
    length=0;
}

bool Sq_list::List_Empty()const {
    return length;
}
int Sq_list::List_Length()const {
    return length;
}
int Sq_list::Get_Element(int n)const {
    return element[n-1];
}

bool Sq_list::Insert_Element(int n,int m){
    if (n<1||n>length+1) return false;
    if (this->length>=this->size){
        int* tmp=element;
        element=new int[size=+10];
        for (int i=0;i<this->length;i++){
            element[i]=tmp[i];
        }
        delete [] tmp;
    }
    for (int i=length;i>=n;i--){
        element[i]=element[i-1];
    }
    element[n-1]=m;
    length++;
    return true;
}
bool Sq_list::Delete_Element(int n, int& m){
    if (n<1||n>length) return false;
    m=element[n-1];
    for (int i=n;n<length;i++){
        element[i-1]=element[i];
    }
    length--;
    return true;
}

std::ostream& operator << (std::ostream& os ,Sq_list& list){
    for (int i=0;i<list.length;i++){
        os<<list.element[i]<<" ";
    }
    return os;
}
std::istream& operator >> (std::istream& is ,Sq_list& list){
    is>>list.element[list.length];
    list.length++;
    return is;
}
