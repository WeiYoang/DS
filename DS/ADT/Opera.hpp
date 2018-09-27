//
//  Opera.hpp
//  DS
//
//  Created by WeiYoang on 9/27/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Opera_hpp
#define Opera_hpp

#include <stdio.h>
struct CompareTable{
    char** ptr;
    CompareTable();
    ~CompareTable();
};
class Operand{
private:
    int top;
    int* base;
    int size;
public:
    Operand();
    ~Operand();
    void push(int );
    int pop();
};
class Operator{
private:
    int top;
    char* base;
    int size;
public:
    Operator();
    ~Operator();
    void push(char );
    char pop();
    char ShowTop();
};
class Int{
private:
    int top;
    int* base;
    int size;
public:
    Int();
    ~Int();
    void push(int );
    bool empty();
    int pop();
    int merge();
};
#endif /* Opera_hpp */
