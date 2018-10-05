//
//  String.hpp
//  DS
//
//  Created by WeiYoang on 10/3/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <iostream>

class String{
    enum {DEFAULT=100};
private:
    char* ch;
    int length;
    int size;
public:
    String();
    String(int );
    ~String();
   // void StrCopy(String& );
    bool StrEmpty()const;
    void Destray();
    int StrCompare(String &)const;
    int StrLength()const;
    void Concat(String& );
    bool SubStr(int ,int,String& );
    void NextVal(String& ,int* ,int );
    int index( String& ,int );
    bool StrInsert(int ,String& );
    bool StrDelete(int ,int  ,String& );
    friend std::ostream& operator <<(std::ostream& ,String& );
    friend std::istream& operator >>(std::istream& ,String& );
    String& operator =(String& );
};
#endif /* String_hpp */
