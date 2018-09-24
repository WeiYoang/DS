//
//  Static_list.hpp
//  DS
//
//  Created by WeiYoang on 9/23/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Static_list_hpp
#define Static_list_hpp

#include <stdio.h>
#include <iostream>
class Component{
private:
    int cur;
    int data;
public:
    Component(){
        cur=0;
        data=0;
    }
    int Show_cur(){
        return cur;
    }
    int Show_data(){
        return data;
    }
    void Set_cur(int n){
        cur =n;
    }
    void Set_data(int n){
        data=n;
    }
};
class Static_list{
    enum {Default=10};
private:
    Component divide[Default];
    int header;
public:
    Static_list(){
        header=0;
        for (int i=0;i<Default-1;i++){
            divide[i].Set_cur(i+1);
        }
        divide[Default-1].Set_cur(101);
    }
    void SetValue(int );
    int GiveMemory();
    void FreeMemory(int n);
    bool Is_empty();
    friend std::ostream& operator<< (std::ostream& ,Static_list&);
    friend std::istream& operator>> (std::istream& ,Static_list&);
};
#endif /* Static_list_hpp */
