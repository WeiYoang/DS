//
//  L_list.hpp
//  Data Structure
//
//  Created by WeiYoang on 9/22/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef L_list_hpp
#define L_list_hpp

#include <stdio.h>
#include <iostream>
class LNode{
private:
    int data;
    LNode* next;
public:
    LNode(){
        data=0;
        next=nullptr;
    }
    int Show_data(){
        return data;
    }
    LNode* Show_ptr(){
        return next;
    }
    void Set_ptr(LNode* n){
        next=n;
    }
    void Set_data(int n){
        data=n;
    }
};
class LHeader{
private:
    LNode* ptr;
public:
    LHeader(){
        ptr=new LNode;
    };
    ~LHeader();
    bool DestroyList();
    void ClearList();
    bool ListEmpty()const;
    bool GetElement(int ,int&)const;
    int ListLength()const;
    LNode* Prior(int )const;
    LNode* Next(int )const;
    bool ListInsert(int ,int);
    bool ListDelete(int ,int& );
    friend std::ostream& operator <<(std::ostream& ,LHeader&);
    friend std::istream& operator >>(std::istream& ,LHeader&);
};


#endif /* L_list_hpp */
