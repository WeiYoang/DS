//
//  Lists.cpp
//  DS
//
//  Created by WeiYoang on 10/13/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//
//the mothed is limited by string that cant include empty char; using of '\0' marks end of string.
#include "Lists.hpp"
#include <iostream>
using namespace std;
//get suitable string
void  server(char* c1,char* c2){
    int n=0,k=0,m=0;
    for (int i=1;c1[i]!='\0';i++) n++;
    do {
        m++;
        if (c1[m]=='(') k++;
        else if (c1[m]==')') k--;
    } while (c1[m]!='\0'&&(c1[m]==','||k!=0));
    if (c1[m]!='\0'){
        c2=new char[m+1];
        c2[m]='\0';
        for (int i=1;i<m;i++)
            c2[i]=c1[i];
        for (int i=1;m+i<=n+1;i++)
            c1[i]=c1[m+i];
    } else {
        for (int i=1;c1[i]!='\0';i++)
            c2[i]=c1[i];
        c2[n+1]='\0';
        c1[1]='\0';
    }
}
lists::lists(char *ch){
    fptr=nullptr;
    Create(&fptr, ch);
}
lists::~lists(){
    Destrayed(fptr);
}
void lists::Destrayed(GLnode* L){
    if (L!=nullptr&&L->flag==GLnode::atom) delete L;
    else {
    while(L){
        GLnode* pp;
        pp=L;
        Destrayed(L->vp.ptr.hp);
        L=L->vp.ptr.tp;
        delete pp;
        }
    }
}
void lists::Create(GLnode **L,char *ch){
    if (ch[1]=='\0') *L=nullptr;
    else {
        *L=new GLnode;
        if (ch[2]=='\0') {
            (*L)->flag=GLnode::atom;
            (*L)->vp.atom=ch[1];
        } else{
            (*L)->flag=GLnode::list;
            GLnode *p,*q;
            p=(*L);
            int n=0;
            for (int i=1;ch[i]!='\0';i++) n++;
            char *c1=new char[n+2];
            for (int i=1;i+1<n;i++)
                ch[i]=ch[i+1];
            ch[n-1]='\0';
            do {
                server(ch, c1);
                Create(&(p->vp.ptr.hp), c1);
                delete [] c1;
                q=p;
                if (ch[1]!='\0') {
                    p=new GLnode;
                    q->vp.ptr.tp=p;
                    p->flag=GLnode::list;
                    c1=new char[n+2];
                }
            }while(ch[1]!='\0');
            q->vp.ptr.tp=nullptr;
        }
    }
}
void lists::Traverse(GLnode* L){
    if(L!=nullptr&&L->flag==GLnode::list){
        cout<<"(";
        while(L){
            Traverse(L->vp.ptr.hp);
            L=L->vp.ptr.tp;
        }
        if(L==nullptr){
            cout<<")";
        }
    }
    if(L!=nullptr&&L->flag==GLnode::atom){
        cout<<L->vp.atom;
    }
}
