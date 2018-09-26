//
//  SolveMaze.cpp
//  DS
//
//  Created by WeiYoang on 9/25/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "SolveMaze.hpp"
#include <stdlib.h>
#include <ctime>
#include <iostream>
Stack::Stack(){
    base=new Selement[100];
    top=0;
    size=100;
}
Stack::~Stack(){
    delete [] base;
}
bool Stack::StackEmpty(){
    if (top==0) return true;
    return false;
}
bool Stack::StackNextEmpty(){
    if (top==1) return true;
        return false;
}
bool Stack::push(Selement& n){
    if (top+1<100){
        base[top]=n;
        top++;
        return true;
    }
    return false;
}
bool Stack::pop(Selement& n){
    if (top!=0){
        n=base[--top];
        return true;
        
    }
    return false;
}

MazeMap::~MazeMap(){
    for (int i=0;i<x+2;i++)
        delete [] xy[i];
}
MazeMap::MazeMap(int x,int y){
    this->x=x;
    this->y=y;
    xy=new element*[x+2];
    for (int i=0;i<x+2;i++){
        xy[i]=new element[y+2];
    }
    for (int i=0;i<y+2;i++){
        xy[0][i].tuken='#';
        xy[0][i].block=1;
        xy[0][i].mark=1;
    }
    for (int i=0;i<y+2;i++){
        xy[x+1][i].tuken='#';
        xy[x+1][i].block=1;
        xy[x+1][i].mark=1;
    }
    for (int i=0;i<x+2;i++){
        xy[i][0].tuken='#';
        xy[i][0].block=1;
        xy[i][0].mark=1;
    }
    for (int i=0;i<x+2;i++){
        xy[i][y+1].tuken='#';
        xy[i][y+1].block=1;
        xy[i][y+1].mark=1;
    }
    for (int i=1;i<x+1;i++){
        for (int j=1;j<y+1;j++){
            if (rand()%2){
                xy[i][j].block=1;
                xy[i][j].tuken='#';
                xy[i][j].mark=0;
            } else {
                xy[i][j].block=0;
                xy[i][j].tuken=' ';
                xy[i][j].mark=0;
            }
        }
    }
}
void MazeMap::Changeformat(Stack& sta){
    Selement e;
    sta.pop(e);
    xy[e.x][e.y].tuken='$';
    while (!sta.StackNextEmpty()){
        sta.pop(e);
        switch (e.di) {
            case 1:
            case 3:
                xy[e.x][e.y].tuken='-';
                break;
            default:xy[e.x][e.y].tuken='|';
                break;
        }
    }
    sta.pop(e);
    xy[e.x][e.y].tuken='@';
}
bool MazeMap::MazePath(int x, int y,int ex,int ey){
    int curstep;
    Stack Sta;
    Selement e;
    if (xy[x][y].block==1){
        std::cout<<"error, the start is not taken"<<std::endl;
    return false;
    }
    else {
        curstep=1;
        do {
            if (xy[x][y].block!=1&&xy[x][y].mark!=1){
                xy[x][y].mark=1;
                e.ord=curstep;e.di=1;e.x=x;e.y=y;
                Sta.push(e);
                if (e.x==ex&&e.y==ey) {
                    Changeformat(Sta);
                    std::cout<<*this;
                    return true;
                }
                y=y-1;
                curstep++;
            }
            else {
                if (!Sta.StackEmpty()){
                    Sta.pop(e);
                    while (e.di==4&&!Sta.StackEmpty()){
                        xy[e.x][e.y].mark=1; Sta.pop(e);
                        
                    }
                    x=e.x;y=e.y;
                    if (e.di<4){
                        e.di++;
                        switch (e.di) {
                            case 2: x=x-1;
                                break;
                            case 3: y=y+1;
                                break;
                            case 4: x=x+1;
                        }
                        Sta.push(e);
                    }
                }
            }
        } while(!Sta.StackEmpty());
    }
    std::cout<<std::endl;
    std::cout<<"false,becouse you are at false end";
    std::cout<<std::endl;
    return false;
}
std::ostream& operator<< (std::ostream& os,MazeMap& maze){
    os<<"   ";
    for (int i=0;i<maze.y+2;i++)
        if (i<10)
        os<<i<<"  ";
    else
        os<<i<<" ";
    os<<std::endl;
    for (int i=0;i<maze.x+2;i++){
        if (i<10)
        os<<i<<"  ";
        else os<<i<<" ";
        for (int j=0;j<maze.y+2;j++){
            os<<maze.xy[i][j].tuken<<"  ";
        }
        os<<std::endl;
    }
    os<<std::endl;
    return os;
}
