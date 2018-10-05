//
//  String.cpp
//  DS
//
//  Created by WeiYoang on 10/3/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "String.hpp"

String::String(){
    ch=new char[DEFAULT];
    length=0;
    size=DEFAULT;
    
}
String::String(int n){
    ch=new char[n];
    length=0;
    size=n;
}
String::~String(){
    delete [] ch;
}
void String::Destray(){
    delete [] ch;
    length=0;
    size=0;
}
String& String::operator =(String& str){
    this->Destray();
    if (str.length<100){
        this->ch=new char[DEFAULT];
        this->size=100;
    }
    else {
        this->ch=new char[str.length+100];
        this->size=str.length+100;
    }
    for (int i=0;i<str.length;i++){
        this->ch[i]=str.ch[i];
    }
    this->length=str.length;
    return *this;
}
bool String::StrEmpty()const{
    return length;
}
int String::StrCompare(String& str)const{
    for (int i=0;i<this->length&&i<str.length;i++)
        if(this->ch[i]!=str.ch[i]) return this->ch[i]-str.ch[i];
    return this->length-str.length;
}
int String::StrLength()const{
    return length;
}
void String::Concat(String& str){
    if (this->length+str.length>this->size){
        String tmp(this->length+str.length+100);
        tmp.length=this->length+str.length;
        for (int i=0;i<this->length;i++)
            tmp.ch[i]=this->ch[i];
        for (int i=0;i<str.length;i++)
            tmp.ch[i+this->length]=str.ch[i];
        *this=tmp;
    } else {
        for (int i=0;i<str.length;i++){
            this->ch[i+length]=str.ch[i];
        }
        this->length=this->length+str.length;
    }
}
bool String::SubStr(int pos, int n,String& str){
    if (n<1||n>this->length||pos<0||pos>this->length-1||n==0)
        return false;
    String tmp(n+10);
    for (int i=0;i<pos+n-1;i++)
        tmp.ch[i]=this->ch[i+pos-1];
    tmp.length=n;
    str=tmp;
    return true;
}
void String::NextVal(String& str,int* nextval,int number){
    int i,j;
    i=0;
    j=-1;
    nextval[0]=-1;
    while (i<number-1){
        if (j==-1||str.ch[i]==str.ch[j]){
            i++;j++;
            if (str.ch[i]!=str.ch[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }
        else j=nextval[j];
    }
}
int String::index( String& str,int pos){
    int* nextval=new int[str.length];
    String::NextVal(str,nextval,str.length);
   /* for (int i=0;i<str.length;i++) {
        std::cout<<str.ch[i]<<'/';
        std::cout<<nextval[i];
        std::cout<<std::endl;
    }
    std::cout<<std::endl;*/
    int i=pos-1,j=0;
    while (i<this->length&&j<str.length){
        if (j==-1||this->ch[i]==str.ch[j]){
            i++;j++;
        }
        else j=nextval[j];
    }
    if (j>=str.length) return i-str.length+1;
    delete [] nextval;
    return 0;
}
bool String::StrInsert(int n, String& str){
    if ((this->length+str.length)>this->size){
        char *tmp=new char[this->length+str.length+100];
        for (int i=0;i<n-1;i++){
            tmp[i]=this->ch[i];
        }
        for (int i=0;i<str.length;i++){
            tmp[n-1+i]=str.ch[i];
        }
        for (int i=n-1;i<this->length;i++){
            tmp[str.length+i]=this->ch[i];
        }
        delete [] this->ch;
        this->ch=tmp;
        this->size=this->length=this->length+str.length+100;
    } else {
        for (int i=0;i<this->length-n+1;i++){
            this->ch[length-1-i+str.length]=this->ch[this->length-1-i];
        }
        for (int i=0;i<str.length;i++){
            this->ch[n-1+i]=str.ch[i];
        }
        
    }
    this->length=this->length+str.length;
    return true;
}
bool String::StrDelete(int pos, int n, String& str){
    String tmp(n);
    if (pos<1||pos>this->length||n<=0||pos+n-1>this->length) return false;
    for (int i=0;i<n;i++){
        tmp.ch[i]=this->ch[pos-1+i];
    }
    for (int i=pos-1+n;i<this->length;i++){
        this->ch[i-n]=this->ch[i];
    }
    tmp.length=n;
    str=tmp;
    this->length=this->length-n;
    return true;
}
std::ostream& operator <<(std::ostream& os,String& str){
    for (int i=0;i<str.length;i++){
        os<<str.ch[i];
    }
    //str.ch[str.length]='\0';
    //os<<str.ch;
    return  os;
}
std::istream& operator >>(std::istream& is,String& str){
    is>>str.ch;
    int i;
    for (i=0;str.ch[i]!='\0';i++);
    str.length=i;
    return is;
}
