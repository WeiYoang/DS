//
//  Bitree.cpp
//  DS
//
//  Created by WeiYoang on 10/16/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "Bitree.hpp"
#include <iostream>
using namespace std;

//must be preOrder to enter chars;
void CreateBiTree(BiTreeNode **T,BiTreeNode *pre){
    char ch;
    if(cin.get(&ch,1)){
        if(ch=='\0') *T=nullptr;
        else {
            *T=new BiTreeNode;
            (*T)->data=ch;
            (*T)->parent=pre;
            pre=(*T);
            CreateBiTree(&((*T)->ptr.lchild),pre);
            CreateBiTree(&((*T)->ptr.rchild),pre);
        }
    }
}
void Destrayed(BiTreeNode *n){
    if (n!=nullptr){
        Destrayed(n->ptr.lchild);
        Destrayed(n->ptr.rchild);
        delete n;
    }
}
void PreOrder(BiTreeNode *T,void (*ps)(ElementType& )){
    if(T!=nullptr){
        (*ps)(T->data);
        PreOrder(T->ptr.lchild, ps);
        PreOrder(T->ptr.rchild, ps);
    }
}
void InOrder(BiTreeNode *T,void (*ps)(ElementType& )){
    if(T!=nullptr){
        InOrder(T->ptr.lchild, ps);
        (*ps)(T->data);
        InOrder(T->ptr.rchild, ps);
    }
}
void PostOrder(BiTreeNode *T,void (*ps)(ElementType& )){
    if(T!=nullptr){
        PostOrder(T->ptr.lchild, ps);
        PostOrder(T->ptr.rchild, ps);
        (*ps)(T->data);
    }
}
void InTreading(BiTreeNode *T,BiTreeNode **pre){
    if(T){
        InTreading(T->ptr.lchild, pre);
        if (!(T->ptr.lchild)){
            T->tag.ltag=BiTreeNode::thread;
            T->ptr.lchild=*pre;
        } else T->tag.ltag=BiTreeNode::link;
        if (!((*pre)->ptr.rchild)){
            (*pre)->ptr.rchild=T;
            (*pre)->tag.rtag=BiTreeNode::thread;
        } else (*pre)->tag.rtag=BiTreeNode::link;
        *pre=T;
        InTreading(T->ptr.rchild, pre);
    }
}
BiTree::BiTree(){
    Hptr=nullptr;
    BiTreeNode *pre=nullptr;
    CreateBiTree(&Hptr,pre);
}
BiTree::~BiTree(){
    Destrayed(Hptr);
}
void BiTree::PreOrderTraverse(void (*ps)(ElementType& )){
    PreOrder(Hptr, ps);
}
void BiTree::InOrderTraverse(void (*ps)(ElementType& )){
    InOrder(Hptr, ps);
}
void BiTree::PostOrderTraverse(void (*ps)(ElementType& )){
    PostOrder(Hptr, ps);
}

void BiThreadTree::InOrderTreading(){
    BiTreeNode* tmp=new BiTreeNode;
    BiTreeNode** pre=nullptr;
    tmp->tag.ltag=BiTreeNode::link;
    tmp->tag.rtag=BiTreeNode::thread;
    tmp->ptr.rchild=tmp;
    if (Hptr==nullptr) tmp->ptr.lchild=tmp;
    else {
        tmp->ptr.lchild=Hptr;
        (*pre)=tmp;
        Hptr=tmp;
        InTreading(Hptr, pre);
        (*pre)->ptr.rchild=Hptr;
        (*pre)->tag.rtag=BiTreeNode::thread;
        Hptr->ptr.rchild=(*pre);
    }
}
void BiThreadTree::PreOrderTraverse(void (*ps)(ElementType& )){
    BiTreeNode* p;
    p=Hptr->ptr.lchild;
    while (p!=Hptr){
        while (p->tag.ltag==BiTreeNode::link) p=p->ptr.lchild;
        ps(p->data);
        while (p->tag.rtag==BiTreeNode::thread&&p->ptr.rchild!=Hptr){
            p=p->ptr.rchild;
            ps(p->data);
        }
        p=p->ptr.rchild;
    }
}
