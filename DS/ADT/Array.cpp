//
//  Array.cpp
//  DS
//
//  Created by WeiYoang on 10/5/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "Array.hpp"

using namespace std;

Array::Array(){
    dim=2;
    bounds = new int[dim];
    bounds[0]=5;
    bounds[1]=5;
    constants = new int[dim];
    int total=25;
    constants[1]=1;
    constants[0]=5;
    base = new ElemType[total];
}
Array::Array(int d,int* n,int m){                   //igore false values;
    dim=d;
    bounds=n;
    constants = new int[dim];
    total=1;
    for (int i=0;i<m;i++){
        total*=bounds[i];
    }
    constants[dim-1]=1;
    for (int i=dim-2;i>=0;i--){
        constants[i]=bounds[i+1]*constants[i+1];
    }
    base = new ElemType[total];
}
Array::~Array(){
    delete [] base;
    delete [] bounds;
    delete [] constants;
}
ElemType Array::GetValue(int* val, int n){
    int locavalue=0;
    for (int i=0;i<dim;i++){
        locavalue+=(val[i]*constants[i]);
    }
    return base[locavalue];
}
bool Array::Assign(int* val,int n,int m){
    int locavalue=0;
    for (int i=0;i<dim;i++){
        locavalue+=(val[i]*constants[i]);
    }
    base[locavalue]=m;
    return true;
}
std::ostream& operator <<(std::ostream& os,Array& ar){
    for (int i=0;i<ar.total;i++)
        os<<ar.base[i];
    return os;
}
std::istream& operator >>(std::istream& is,Array& ar){
    for (int i=0;i<ar.total;i++)
        is>>ar.base[i];
    return is;
}
