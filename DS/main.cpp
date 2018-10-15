//
//  main.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include <iostream>
#include "ADT/Lists.hpp"
 using namespace std;
int main(int argc, const char * argv[]) {
    char *n=new char[13];
    n[0]='F';n[1]='(';
    n[2]='a';n[3]=',';n[4]='d';
    n[5]=',';n[6]='(';n[7]='b';
    n[8]=',';n[9]='c';n[10]=')';
    n[11]=')';n[12]='\0';
    for (int i=1;n[i]!='\0';i++) cout<<n[i];
    cout<<endl;
    lists test1(n);
    lists test(test1);
    //test=test1;
    test.MeTraverse();
    cout<<test.GlistDepth();
    cout<<endl;
    return EXIT_SUCCESS;
}
