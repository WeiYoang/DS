//
//  L_list.cpp
//  Data Structure
//
//  Created by WeiYoang on 9/22/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "L_list.hpp"

LHeader::~LHeader(){
    LNode* tmp;
    while((*ptr).Show_ptr()){
        tmp=ptr;
        ptr=(*ptr).Show_ptr();
        delete tmp;
    }
    delete ptr;
}

bool LHeader::DestroyList(){
    LNode* tmp;
    while((*ptr).Show_ptr()){
        tmp=ptr;
        ptr=(*ptr).Show_ptr();
        delete tmp;
    }
    delete ptr;
    return true;
}
void LHeader::ClearList(){
    LNode* tmp;
    LNode* del;
    tmp=ptr->Show_ptr();
    del=nullptr;
    while (tmp->Show_ptr()){
        del=tmp;
        tmp=tmp->Show_ptr();
        delete del;
    }
    delete tmp;
}
bool LHeader::ListEmpty()const{
    if (ptr->Show_ptr())
        return false;
        else
            return true;
}
bool LHeader::GetElement(int n,int& m)const{
    LNode* tmp;
    tmp=ptr->Show_ptr();
    for (int i=1;i<n;i++){
        if (tmp->Show_ptr())
            tmp=tmp->Show_ptr();
        else return false;
    }
        m=tmp->Show_data();
        return true;
}
int LHeader::ListLength()const{
    int sum=1;
    LNode* tmp=ptr->Show_ptr();
    while (tmp->Show_ptr()){
        sum++;
        tmp=tmp->Show_ptr();
    }
    return sum;
}
LNode* LHeader::Prior(int n)const{
    LNode* tmp;
    tmp=ptr->Show_ptr();
    for (int i=1;i<n-1;i++){
        if (tmp->Show_ptr())
            tmp=tmp->Show_ptr();
        else return nullptr;
    }
    return tmp;
}
LNode* LHeader::Next(int n)const{
    LNode* tmp;
    tmp=ptr->Show_ptr();
    for (int i=1;i<n;i++){
        if (tmp->Show_ptr())
            tmp=tmp->Show_ptr();
        else return nullptr;
    }
    return tmp->Show_ptr();
}
bool LHeader::ListInsert(int n, int m){
    LNode* tmp;
    tmp=ptr->Show_ptr();
    for (int i=1;i<n-1;i++){
        if (tmp->Show_ptr())
            tmp=tmp->Show_ptr();
        else return nullptr;
    }
    LNode* s=new LNode;
    s->Set_ptr(tmp->Show_ptr());
    s->Set_data(m);
    tmp->Set_ptr(s);
    return true;
}
bool LHeader::ListDelete(int n,int& m){
    LNode* tmp;
    tmp=ptr->Show_ptr();
    for (int i=1;i<n-1;i++){
        if (tmp->Show_ptr())
            tmp=tmp->Show_ptr();
        else return false;
    }
    m=tmp->Show_ptr()->Show_data();
    tmp->Set_ptr(tmp->Show_ptr()->Show_ptr());
    return true;
}
std::ostream& operator <<(std::ostream& os,LHeader& n){
    LNode* tmp;
    tmp=n.ptr->Show_ptr();
    while (tmp->Show_ptr()){
        os<<tmp->Show_data()<<" ";
        tmp=tmp->Show_ptr();
    }
    os<<tmp->Show_data();
    return os;
}
std::istream& operator >> (std::istream& is,LHeader& n){
    LNode* tmp;
    if(n.ptr->Show_ptr()!=nullptr){
        tmp=n.ptr->Show_ptr();
    while (tmp->Show_ptr()!=nullptr){
        tmp=tmp->Show_ptr();
    }
    LNode* s=new LNode;
        int a;
        is>>a;
    s->Set_data(a);
    s->Set_ptr(nullptr);
    tmp->Set_ptr(s);
    } else{
        LNode* s=new LNode;
        int a;
        is>>a;
        s->Set_data(a);
        s->Set_ptr(nullptr);
        n.ptr->Set_ptr(s);
    }
    return is;
}
