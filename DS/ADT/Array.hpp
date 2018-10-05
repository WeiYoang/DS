//
//  Array.hpp
//  DS
//
//  Created by WeiYoang on 10/5/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include <iostream>
#define MAX_DIM 8
typedef int  ElemType;

class Array{
private:
    ElemType* base;
    int dim;
    int* bounds;
    int* constants;
    int total;
public:
    Array();
    Array(int ,int* ,int );
    ~Array();
    ElemType GetValue(int* ,int );
    bool Assign(int* ,int ,int );
    friend std::ostream& operator <<(std::ostream& ,Array& );
    friend std::istream& operator >>(std::istream& ,Array& );
};





#endif /* Array_hpp */
