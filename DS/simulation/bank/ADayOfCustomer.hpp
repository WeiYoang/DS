//
//  ADayOfCustomer.hpp
//  DS
//
//  Created by WeiYoang on 9/28/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef ADayOfCustomer_hpp
#define ADayOfCustomer_hpp

#include <stdio.h>
struct Lnode{
    int occurtime;
    int type;
    Lnode* next;
    Lnode(){
        occurtime=type=0;
        next=nullptr;
    }
};
struct Qnode{
    int arrivaltime;
    int duringtime;
};
class EvList{
private:
    Lnode* header;
    int size;
public:
    EvList();
    ~EvList();
    bool Insert(Lnode& );
    Lnode GetHead();
    bool empty(){
        if (size==0) return true;
        return false;
    }
};
class EvSqQueue{
public:
    enum {SIZEMAX=100};
private:
    int front;
    int rear;
    Qnode base[SIZEMAX];
    int size;
public:
    EvSqQueue();
    ~EvSqQueue(){};
    bool EnQueue(Qnode& );
    bool DeQueue(Qnode& );
    int GetSize(){
        return size;
    }
};
#endif /* ADayOfCustomer_hpp */
