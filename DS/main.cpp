//
//  main.cpp
//  DS
//
//  Created by WeiYoang on 9/24/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#include <iostream>
#include "list/Static_list.cpp"
int main(int argc, const char * argv[]) {
    Static_list test;
    test.SetValue(1000);
    std::cout<<test;
    return 0;
}
