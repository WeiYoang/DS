//
//  ADayOfCustomer.cpp
//  DS
//
//  Created by WeiYoang on 9/28/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "ADayOfCustomer.hpp"
#include <stdlib.h>
#include <ctime>
EvList::EvList(){
    header=new Lnode[100];
    size=0;
}
EvList::~EvList(){
    Lnode* tmp;
    while (header!=nullptr){
        tmp=header;
        header=header->next;
        delete tmp;
    }
}
bool EvList::Insert(Lnode& n){
        Lnode* tmp=new Lnode;
        Lnode* tmp1=new Lnode;
        tmp=header;
        while (tmp->next){
            if (tmp->next->occurtime>=n.occurtime){
                tmp1->occurtime=n.occurtime;
                tmp1->type=n.type;
                tmp1->next=tmp->next;
                tmp->next=tmp1;
                size++;
                return true;
            } else {
                tmp=tmp->next;
            }
        }
        if (tmp->next==nullptr){
            tmp1->occurtime=n.occurtime;
            tmp1->type=n.type;
            tmp->next=tmp1;
            size++;
            return true;
        }
    return false;
}
Lnode EvList::GetHead(){
    Lnode tmp;
    Lnode* tmp1=new Lnode;
    tmp1=header->next;
    tmp.occurtime=header->next->occurtime;
    tmp.type=header->next->type;
    size--;
    header->next=header->next->next;
    delete tmp1;
    return tmp;
}
EvSqQueue::EvSqQueue(){
   size=front=rear=0;
}
bool EvSqQueue::EnQueue(Qnode& n){
    if ((rear+1)%SIZEMAX==front)
        return false;
    base[rear]=n;
    size++;
    rear=(rear+1)%SIZEMAX;
    return true;
}
bool EvSqQueue::DeQueue(Qnode& n){
    if (rear==front)
        return false;
    n=base[front];
    front=(front+1)%SIZEMAX;
    size--;
    return true;
}

void BankSimulation(EvList& ev,EvSqQueue* en,int& totaltime,int& customers){
    int nextarr,dur;
    int a,b;
    totaltime=customers=0;
    Lnode ln,ln1;
    Qnode qn;
    ln.occurtime=0;ln.type=0;
    ev.Insert(ln);
    while (!ev.empty()){
        ln1=ln=ev.GetHead();
        if (ln.type==0){
            customers++;
            nextarr=rand()%180;
            dur=rand()%500;
            qn.duringtime=dur;
            qn.arrivaltime=ln.occurtime;
            a=en[1].GetSize();
            b=1;
            for (int i=1;i<5;i++){
                if (a>en[i].GetSize()){
                    a=en[i].GetSize();
                    b=i;
                }
            }
            en[b].EnQueue(qn);
            if (ln.occurtime+nextarr<1800){
                ln.occurtime=ln.occurtime+nextarr;
                ln.type=0;
                ev.Insert(ln);
            }
        
            if (en[b].GetSize()==1){
               ln1.occurtime=ln1.occurtime+qn.duringtime;ln1.type=b;
                ev.Insert(ln1);
            }
            
        } else {
                    en[ln.type].DeQueue(qn);totaltime+=ln.occurtime-qn.arrivaltime;
            if (en[ln.type].GetSize()!=0){
                ln.occurtime=ln.occurtime+qn.duringtime;
                ev.Insert(ln);
            }
        }
    }
}

