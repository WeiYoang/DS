//
//  Static_list.cpp
//  DS
//
//  Created by WeiYoang on 9/23/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include "Static_list.hpp"

int Static_list::GiveMemory(){
        if(divide[header].Show_cur()!=0) {
            int i=divide[header].Show_cur();
            divide[header].Set_cur(divide[divide[header].Show_cur()].Show_cur());
            divide[i].Set_cur(0);
            return i;
        } else
            return 0;
}
void Static_list::FreeMemory(int n){
        divide[n].Set_cur(divide[header].Show_cur());
        divide[header].Set_cur(n);
}
void Static_list::SetValue(int m){
    divide[GiveMemory()].Set_data(m);
}
bool Static_list::Is_empty(){
    if (divide[header].Show_cur()==0)
        return true;
    else return false;
}
std::ostream& operator << (std::ostream& os,Static_list & list){
    for (int i=1;i<Static_list::Default;i++){
        if (list.divide[i].Show_cur()==0){
            os<<list.divide[i].Show_data()<<" ";
        }
    }
    return os;
}
std::istream& operator>> (std::istream& is,Static_list& list){
    int tmp;
    is>>tmp;
    list.SetValue(tmp);
    return is;
}
