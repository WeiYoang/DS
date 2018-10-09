//
//  Matrix.hpp
//  DS
//
//  Created by WeiYoang on 10/5/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <iostream>
typedef int  ElemType;
struct Triple{
    int i,j;
    ElemType e;
};
struct Lnode{
    int i,j;
    ElemType e;
    Lnode *right,*down;
};
class Matrix{
private:
    Triple* data;
    int* rpos;
    Lnode **rhead,**chead;
    int mu,nu,tu;
public:
    Matrix();
    ~Matrix();
    //void CopyMatrix(Matrix& );
    Matrix& operator+=(Matrix& );
    void operator*=(Matrix& );
    void operator--();   //TransposeMatrix;
    friend std::ostream& operator <<(std::ostream& ,Matrix& );
    friend std::istream& operator >>(std::istream& ,Matrix& );
};
#endif /* Matrix_hpp */
