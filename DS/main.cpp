//
//  main.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include <iostream>
#include "ADT/Matrix.hpp"
 using namespace std;
void test(char** );
int main(int argc, const char * argv[]) {
    char *ch=nullptr;
    test(&ch);
    cout<<ch;
    return EXIT_SUCCESS;
}
void test(char **ch){
    *ch=new char;
    cin>>*ch;
}
