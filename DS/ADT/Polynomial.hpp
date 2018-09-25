//
//  Polynomial.hpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include <iostream>
int compare(int ,int);
class Term{
private:
    float coef;
    int expn;
    Term* next;
public:
    Term(){
        next=nullptr;
        coef=0;
        expn=0;
    }
    void Set_next(Term* n){
        next=n;
    }
    Term* Show_next(){
        return next;
    }
    void Set_coef(float n){
        coef=n;
    }
    void Set_expn(int n){
        expn=n;
    }
    float Show_coef(){
        return coef;
    }
    int Show_expn(){
        return expn;
    }
    
};

class Polynomial{
private:
    Term* ptr;
public:
    Polynomial(){
        ptr=new Term;
    }
    ~Polynomial();
    void Destroyed();
    void CreatePoly();
    //Term* LocateTerm(int ,int (*compare)(int ,int));
    Polynomial& operator+= (Polynomial& );
    Polynomial& operator*= (Polynomial& );
    friend std::ostream& operator <<(std::ostream& ,Polynomial&);
};
#endif /* Polynomial_hpp */
