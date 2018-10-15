//
//  Lists.cpp
//  DS
//
//  Created by WeiYoang on 10/13/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//
//the mothed is limited by string that cant include empty char; using of '\0' marks end of suitable string.
/*
 #include <iostream>
 #include "ADT/Lists.hpp"
 using namespace std;
 int main(int argc, const char * argv[]) {
 char *n=new char[13];
 n[0]='F';n[1]='(';
 n[2]='a';n[3]=',';n[4]='d';
 n[5]=',';n[6]='(';n[7]='b';
 n[8]=',';n[9]='c';n[10]=')';
 n[11]=')';n[12]='\0';
 for (int i=1;n[i]!='\0';i++) cout<<n[i];
 cout<<endl;
 lists test1(n);
 lists test(test1);
 //test=test1;
 test.MeTraverse();
 cout<<test.GlistDepth();
 cout<<endl;
 return EXIT_SUCCESS;
 }
 */
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
    } while (c1[m]!='\0'&&(c1[m]!=','||k!=0));
    if (c1[m]!='\0'){
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
lists::lists(){
    fptr=nullptr;
}
lists::lists(char *ch){
    fptr=nullptr;
    Create(&fptr, ch);
    delete [] ch;
}
lists::~lists(){
    Destrayed(fptr);
}
lists::lists(lists& L){
    *this=L;
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
    while(L!=nullptr&&L->flag==GLnode::list){
        cout<<"(";
            Traverse(L->vp.ptr.hp);
            L=L->vp.ptr.tp;
    }
        if(L==nullptr){
            cout<<")";
        }
    if(L!=nullptr&&L->flag==GLnode::atom){
        cout<<L->vp.atom;
    }
}
void lists::MeTraverse(){
    Traverse(fptr);
    cout<<endl;
}
int GetDepth(GLnode* L){
    if (!L) return 1;
    if (L->flag==GLnode::atom) return 0;
    int max,dep;
    max=0;
    for (GLnode *pp=L;pp;pp=pp->vp.ptr.tp){
        dep=GetDepth(pp->vp.ptr.hp);
        if (dep>max) max=dep;
    }
    return max+1;
}
int lists::GlistDepth(){
    return GetDepth(fptr);
}
void CopyLists(GLnode **T,GLnode* L){
    if (!L) *T=nullptr;
    else {
        *T=new GLnode;
        (*T)->flag=L->flag;
        if (L->flag==GLnode::atom) (*T)->vp.atom=L->vp.atom;
        else {
            CopyLists(&((*T)->vp.ptr.hp), L->vp.ptr.hp);
            CopyLists(&((*T)->vp.ptr.tp), L->vp.ptr.tp);
        }
        
    }
}
lists& lists::operator=(lists& L){
    CopyLists(&(this->fptr), L.fptr);
    return *this;
}
