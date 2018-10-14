//
//  Lists.hpp
//  DS
//
//  Created by WeiYoang on 10/13/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//

#ifndef Lists_hpp
#define Lists_hpp

#include <stdio.h>
typedef char AtomType;
struct  GLnode{
    enum Flag{atom=0,list=1};
    struct Ptr{
        GLnode *hp;
        GLnode *tp;
    };
    union ValueOrPtr{
        AtomType atom;
        Ptr ptr;
    }vp;
    Flag flag;
};
class lists{
private:
    GLnode* fptr;
public:
    lists(char * );
    lists(lists& ); //design for copy constructor;
    ~lists();
    void Create(GLnode** ,char* );
    void Destrayed(GLnode* );
    void Traverse(GLnode* );
    int GlistDepth();
};

#endif /* Lists_hpp */
