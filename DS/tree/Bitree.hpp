//
//  Bitree.hpp
//  DS
//
//  Created by WeiYoang on 10/16/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Bitree_hpp
#define Bitree_hpp

#include <stdio.h>
#include <iostream>
typedef char ElementType;
void Visit(ElementType& n){
    std::cout<<n;
}

class BiTreeNode{
public:
    enum PointerTag{link,thread,null};
    ElementType data;
    struct {
        BiTreeNode *lchild,*rchild;
    }ptr;
    BiTreeNode* parent;
    struct {
        PointerTag ltag,rtag;
    }tag;
    BiTreeNode(){
        data='\0';
        parent=ptr.lchild=ptr.rchild=nullptr;
        tag.ltag=tag.rtag=null;
    }
};

class BiTree{
protected:
    BiTreeNode *Hptr;
public:
    BiTree();
    virtual ~BiTree();
    virtual void PreOrderTraverse(void (*)(ElementType& ));
    virtual void InOrderTraverse(void (*)(ElementType&));
    void PostOrderTraverse(void (*)(ElementType& ));
};

class BiThreadTree :public BiTree{
public:
    BiThreadTree() :BiTree(){}
    virtual ~BiThreadTree(){};
    void InOrderTreading();
    void preOrderTreaading();
    void postOrderTreading();
    virtual void PreOrderTraverse(void (*)(ElementType& ));
    virtual void InOrderTraverse(void (*)(ElementType&));
};



#endif /* Bitree_hpp */
