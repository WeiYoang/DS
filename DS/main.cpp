//
//  main.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include <iostream>
#include "list/Static_list.cpp"
#include "ADT/Polynomial.hpp"
int main(int argc, const char * argv[]) {
    Polynomial test1;
    test1.CreatePoly();
    Polynomial test2;
    test2.CreatePoly();
    std::cout<<(test1*=test2)<<std::endl;
    return 0;
}
