//
//  main.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include <iostream>
#include "ADT/Opera.hpp"
//test for mazepath
/*int main(int argc, const char * argv[]) {
    srand(unsigned(time(0)));
    MazeMap test(20,20);
    std::cout<<test;
    int x,y,ex,ey;
    std::cout<<"the maze is all ready,plz enter a start you want to start :";
    std::cin>>x;std::cin>>y;
    std::cout<<std::endl;
    std::cout<<"enter a end you want to end: :";
    std::cin>>ex;std::cin>>ey;
    std::cout<<std::endl;
    std::cout<<"lets go!:::"<<std::endl;
    test.MazePath(x,y,ex,ey);
    std::cout<<std::endl;
    std::cout<<std::endl;

    return 0;
}*/
//test for formula calulation.
void EvaluateExpression(Operand& ,Operator& ,char* ,CompareTable& );
int main(int argc, const char * argv[]) {
    Operator OR;
    Operand OD;
    CompareTable table;
    char  p[100];
    std::cout<<"plz,enter the formula you want to caculate,and then ENTER key:";
    std::cin>>p;
    std::cout<<"so ,the result is:";
    EvaluateExpression(OD, OR, p, table);
    std::cout<<OD.pop()<<std::endl;
    return 0;
}
