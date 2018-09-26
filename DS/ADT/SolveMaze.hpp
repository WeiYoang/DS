//
//  SolveMaze.hpp
//  DS
//
//  Created by WeiYoang on 9/25/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef SolveMaze_hpp
#define SolveMaze_hpp
#include <iostream>
#include <stdio.h>
struct element{
    char tuken;
    int block;
    int mark;
};
struct Selement{
    int ord;
    int x; int y;
    int di;
};
class Stack{
private:
    int top;
    Selement* base;
    int size;
public:
    Stack();
    ~Stack();
    bool StackEmpty();
    bool StackNextEmpty();
    bool push(Selement& );
    bool pop(Selement& );
};
class MazeMap{
private:
    element** xy;
    int x;
    int y;
public:
    MazeMap(int x=5,int y=5);
    ~MazeMap();
    bool MazePath(int x,int y,int ,int);
    void ShowMap();
    void Changeformat(Stack& );
    friend std::ostream& operator<< (std::ostream& ,MazeMap& );
};

#endif /* SolveMaze_hpp */
