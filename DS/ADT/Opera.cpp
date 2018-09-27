//
//  Opera.cpp
//  DS
//
//  Created by WeiYoang on 9/27/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "Opera.hpp"
#include <iostream>
using namespace std;
CompareTable::CompareTable(){
    ptr=new char*[8];
    for (int i=0;i<8;i++){
        ptr[i]=new char[8];
    }
    ptr[0][1]='+';ptr[0][2]='-';
    ptr[0][3]='*';ptr[0][4]='/';
    ptr[0][5]='(';ptr[0][6]=')';
    ptr[0][7]='#';                 //0r
    ptr[1][0]='+';ptr[2][0]='-';
    ptr[3][0]='*';ptr[4][0]='/';
    ptr[5][0]='(';ptr[6][0]=')';
    ptr[7][0]='#';                 //0c
    ptr[1][1]='>';ptr[1][2]='>';
    ptr[1][3]='<';ptr[1][4]='<';
    ptr[1][5]='<';ptr[1][6]='>';
    ptr[1][7]='>';                 //1r
    ptr[2][1]='>';ptr[2][2]='>';
    ptr[2][3]='<';ptr[2][4]='<';
    ptr[2][5]='<';ptr[2][6]='>';
    ptr[2][7]='>';                //2r
    ptr[3][1]='>';ptr[3][2]='>';
    ptr[3][3]='>';ptr[3][4]='>';
    ptr[3][5]='<';ptr[3][6]='>';
    ptr[3][7]='>';                  //3r
    ptr[4][1]='>';ptr[4][2]='>';
    ptr[4][3]='<';ptr[4][4]='<';
    ptr[4][5]='<';ptr[4][6]='>';
    ptr[4][7]='>';                   //4r
    ptr[5][1]='<';ptr[5][2]='<';
    ptr[5][3]='<';ptr[5][4]='<';
    ptr[5][5]='<';ptr[5][6]='=';
    ptr[5][7]=' ';                 //5r
    ptr[6][1]='>';ptr[6][2]='>';
    ptr[6][3]='>';ptr[6][4]='>';
    ptr[6][5]=' ';ptr[6][6]='>';
    ptr[6][7]='>';                  //6
    ptr[7][1]='<';ptr[7][2]='<';
    ptr[7][3]='<';ptr[7][4]='<';
    ptr[7][5]='<';ptr[7][6]=' ';
    ptr[7][7]='=';                  //7
}
CompareTable::~CompareTable(){
    for (int i=0;i<8;i++)
        delete [] ptr[i];
}
Operand::Operand(){
    base=new int[100];
    top=0;
    size=100;
}
Operand::~Operand(){
    delete [] base;
}
void Operand::push(int n){
    base[top]=n;
    top++;
}
int Operand::pop(){
    return base[--top];
}
Operator::Operator(){
    base=new char[100];
    top=0;
    size=100;
}
Operator::~Operator(){
    delete [] base;
}
void Operator::push(char c){
    base[top]=c;
    top++;
}
char Operator::pop(){
    return base[--top];
}
char Operator::ShowTop(){
    return base[top-1];
}
Int::Int(){
    base=new int[10];
    top=0;
    size=10;
}
Int::~Int(){
    delete [] base;
}
void Int::push(int n){
    base[top]=n;
    top++;
}
int Int::pop(){
    return base[--top];
}
bool Int::empty(){
    if (top==0) return true;
    return false;
}
int Int::merge(){
    int n=pop();
    for (int i=1;!empty();i++){
        n=n+pop()*(i*10);
    }
    return n;
}
void EvaluateExpression(Operand& OD,Operator& OR,char* p,CompareTable& compare){
    char c;
    int n=0;
    int x,y;
    int a,b;
    Int mg;
    x=y=0;
    OR.push('#');
    c=p[n];
    while (c!='#'||OR.ShowTop()!='#'){
        if ((int)c>=48&&(int)c<=57){
        do{
            mg.push((int)c-48);
            n++;
            if (p[n]!='\0')
            c=p[n];
            else c='#';
        }while ((int)c>=48&&(int)c<=57);
            OD.push(mg.merge());
        } else {
            for (int i=1;i<8;i++){
                if (compare.ptr[0][i]==c)
                    y=i;
                }
            for (int i=1;i<8;i++){
                if (compare.ptr[i][0]==OR.ShowTop())
                    x=i;
            }
            switch (compare.ptr[x][y]) {
                case '<': OR.push(c);
                    if (p[++n]!='\0')
                    c=p[n];
                else c='#';
                    break;
                case '=': OR.pop();
                    if (p[++n]!='\0')
                    c=p[n];
                else c='#';
                    break;
                case '>':
                    switch (OR.pop()) {
                        case '+': a=OD.pop();b=OD.pop();OD.push(a+b);
                            break;
                        case '-': a=OD.pop();b=OD.pop();OD.push(a-b);
                            break;
                        case '*': a=OD.pop();b=OD.pop();OD.push(a*b);
                            break;
                        case '/':a=OD.pop();b=OD.pop();OD.push(a/b);
                            break;
                    }
                    break;
                }
            }
        }
    }

