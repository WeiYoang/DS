//
//  Sq_list.hpp
//  Data Structure
//
//  Created by WeiYoang on 9/22/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Sq_list_hpp
#define Sq_list_hpp

#include <stdio.h>
#include <iostream>
class Sq_list{
    enum { defaut=100};
private:
    int* element;
    int size;
    int length;
public:
    Sq_list();
    ~Sq_list(){
        delete [] element;
    }
   // void Clear_List();
    bool List_Empty()const;
    int List_Length()const;
    int Get_Element(int )const;
    //int Locate_Element(int ,bool (*compare)(int a,int b))const;
    bool Insert_Element(int , int);
    bool Delete_Element(int ,int& );
    friend std::ostream& operator <<(std::ostream& , Sq_list& );
    friend std::istream& operator >>(std::istream& , Sq_list& );
};


#endif /* Sq_list_hpp */
