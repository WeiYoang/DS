//
//  Polynomial.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "Polynomial.hpp"
int compare(int n,int m){
    if (n<m) return -1;
    else if (n==m) return 0;
    return 1;
}
Polynomial::~Polynomial(){
    Term* tmp;
    while (ptr){
        tmp=ptr;
        ptr=ptr->Show_next();
        delete tmp;
    }
}
void Polynomial::CreatePoly(){
    std::cout<<"plz,enter a number of Polynomail:";
    int all;
    std::cin>>all;
    std::cout<<std::endl;
    float n;
    int m;
    Term* tmp=nullptr;
    Term* exchange=nullptr;
    for (int i=1;i<=all;i++){
        std::cout<<"plz,enter next expn:";
        std::cin>>m;
        //std::cout<<std::endl;
        std::cout<<"plz,enter next coef:";
        std::cin>>n;
        if (i==1){
            tmp=new Term;
            tmp->Set_coef(n);
            tmp->Set_expn(m);
            ptr->Set_next(tmp);
        } else{
            tmp=ptr;
            while (tmp->Show_next()->Show_next()){
                if (tmp->Show_next()->Show_expn()==m){
                    tmp->Show_next()->Set_coef(tmp->Show_next()->Show_coef()+n);
                    break;
                } else{
                    if (tmp->Show_next()->Show_expn()>m){
                        exchange=new Term;
                        exchange->Set_expn(m);
                        exchange->Set_coef(n);
                        exchange->Set_next(tmp->Show_next());
                        tmp->Set_next(exchange);
                        break;
                    } else {
                        tmp=tmp->Show_next();
                    }
                }
            }
            if (tmp->Show_next()->Show_next()==nullptr){
                if (tmp->Show_next()->Show_expn()==m){
                     tmp->Show_next()->Set_coef(tmp->Show_next()->Show_coef()+n);
                } else {
                    if (tmp->Show_next()->Show_expn()>m){
                        exchange=new Term;
                        exchange->Set_expn(m);
                        exchange->Set_coef(n);
                        exchange->Set_next(tmp->Show_next());
                        tmp->Set_next(exchange);
                    } else {
                        exchange=new Term;
                        exchange->Set_expn(m);
                        exchange->Set_coef(n);
                        tmp->Show_next()->Set_next(exchange);
                    }
                }
            }
        }
    }
}
Polynomial& Polynomial::operator +=(Polynomial& poly){
    Term* tmp1;
    Term* tmp2;
    Term* tmp3;
    tmp1=this->ptr;
    tmp2=poly.ptr->Show_next();
    delete poly.ptr;
    poly.ptr=nullptr;
    while (tmp1->Show_next()&&tmp2){
        if (tmp1->Show_next()->Show_expn()==tmp2->Show_expn()){
            tmp1->Show_next()->Set_coef(tmp1->Show_next()->Show_coef()+tmp2->Show_coef());
            tmp3=tmp2;
            tmp2=tmp2->Show_next();
            delete tmp3;
            tmp1=tmp1->Show_next();
        } else {
            if(tmp1->Show_next()->Show_expn()>tmp2->Show_expn()){
                tmp3=tmp2;
                tmp2=tmp2->Show_next();
                tmp3->Set_next(tmp1->Show_next());
                tmp1->Set_next(tmp3);
                tmp1=tmp1->Show_next()->Show_next();
            } else {
                tmp1=tmp1->Show_next();
            }
        }
    }
    if (tmp2){
        tmp1->Set_next(tmp2);
    }
    return *this;
}
Polynomial& Polynomial::operator*=(Polynomial& poly){
    Polynomial rape1;
    Polynomial rape2;
    Term* tmp1;
    Term* tmp2=poly.ptr->Show_next();
    Term* tmp3;
    Term* tmp4;
    delete poly.ptr;
    poly.ptr=nullptr;
    while(tmp2){
        tmp1=this->ptr->Show_next();
        rape2.ptr=new Term;
        tmp4=rape2.ptr;
    while (tmp1){
            tmp3=new Term;
            tmp3->Set_expn((tmp1->Show_expn())*(tmp2->Show_expn()));
            tmp3->Set_coef((tmp1->Show_coef())*(tmp2->Show_coef()));
            tmp4->Set_next(tmp3);
            tmp4=tmp3;
            tmp1=tmp1->Show_next();
        }
            rape1+=rape2;
        tmp2=tmp2->Show_next();
    }
    this->Destroyed();
    this->ptr=new Term;
    *this+=rape1;
    return *this;
}
void Polynomial::Destroyed(){
    Term* tmp;
    while (ptr){
        tmp=ptr;
        ptr=ptr->Show_next();
        delete tmp;
    }
}
std::ostream& operator <<(std::ostream& os, Polynomial& poly){
    Term* tmp=poly.ptr->Show_next();
    os<<"0";
    while (tmp){
        os<<"+"<<tmp->Show_coef()<<"x^"<<tmp->Show_expn();
        tmp=tmp->Show_next();
    }
    return os;
}
