//
//  main.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include <iostream>
#include "ADT/Matrix.hpp"
int main(int argc, const char * argv[]) {
    using namespace std;
    Matrix test,test1;
    cin>>test;
    cout<<endl;
   // --test;
    cin>>test1;
    cout<<endl;
    cout<<test1;
    cout<<endl;
    test*=test1;
    cout<<test;
    return EXIT_SUCCESS;
}
