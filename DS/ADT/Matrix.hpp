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

class Matrix{
private:
    Triple* data;
    int mu,nu,tu;
public:
    Matrix();
    ~Matrix();
    void CopyMatrix(Matrix& );
    void AddMatrix(Matrix& );
    void SubMatrix(Matrix& );
    void MultMatrix(Matrix& );
    void TransposeMatrix(Matrix& );
    friend std::ostream& operator <<(std::ostream& ,Matrix& );
    friend std::istream& operator >>(std::istream& ,Matrix& );
    
};
#endif /* Matrix_hpp */
