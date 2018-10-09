//
//  Matrix.cpp
//  DS
//
//  Created by WeiYoang on 10/5/18.
//  Copyright © 2018 WeiYoang. All rights reserved.
//
//have a lots of problems
#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(){
    data=nullptr;
    rpos=nullptr;
    rhead=chead=nullptr;
    mu=nu=tu=0;
}
Matrix::~Matrix(){
    delete [] data;
    delete [] rpos;
    for (int i=1;i<=mu;i++){
        for (Lnode *j=rhead[i],*ptr=nullptr;j;j=ptr){
            ptr=j->right;
            delete j;
        }
    }
    delete [] rhead;
    delete [] chead;
}
std::istream& operator >>(std::istream& is,Matrix& matrix){
    std::cout<<"pls,enter all rows:";
    is>>matrix.mu;
    matrix.rpos=new int[matrix.mu+1];
    std::cout<<"pls,enter all volumes:";
    is>>matrix.nu;
    matrix.rhead=new Lnode*[matrix.mu+1];
    matrix.chead=new Lnode*[matrix.nu+1];
    for (int i=0;i<matrix.mu+1;i++)
        matrix.rhead[i]=nullptr;
    for (int i=0;i<matrix.nu+1;i++)
        matrix.chead[i]=nullptr;
    std::cout<<"pls,enter all number of values:";
    is>>matrix.tu;
    matrix.data =new Triple[matrix.tu+1];
    for (int i=0;i<matrix.tu+1;i++){
        matrix.data[i].j=matrix.data[i].i=0;
    }
    std::cout<<"pls,enter values of Matrix acounting to number of row frist and volume second,ultimate value:";
    std::cout<<std::endl;
    int n;
    Lnode* p;
    for (n=0;n<matrix.tu;n++){
        p=new Lnode;
        p->right=nullptr;
        is>>p->i;
        is>>p->j;
        is>>p->e;
        
        if (matrix.rhead[p->i]==nullptr||matrix.rhead[p->i]->j>p->j) {
            p->right=matrix.rhead[p->i];
            matrix.rhead[p->i]=p;
        } else {
            Lnode* i;
            for (i=matrix.rhead[p->i];(i->right)&&i->right->j<p->j; i=i->right);
            p->right=i->right;i->right=p;
        }
        if (matrix.chead[p->j]==nullptr||matrix.chead[p->j]->i>p->i){
            p->down=matrix.chead[p->j];
            matrix.chead[p->j]=p;
        } else {
            Lnode* i;
            for (i=matrix.chead[p->j];(i->down)&&(i->down->i<p->i);i=i->down);
            p->down=i->down;
            i->down=p;
        }
        int i=1;
        if (n==0){
            matrix.data[1].i=p->i;
            matrix.data[1].j=p->j;
            matrix.data[1].e=p->e;
        } else{
            while (i<=n){
                if (matrix.data[i].i==p->i){
                    for (;i<=n&&matrix.data[i].i==p->i&&matrix.data[i].j<p->j;i++);
                    break;
                } else{
                    i++;
                }
            }
        }
        if (i>n) {
            matrix.data[i].i=p->i;
            matrix.data[i].j=p->j;
            matrix.data[i].e=p->e;
        } else{
            for (int z=n;z>=i;z--){
                matrix.data[z+1]=matrix.data[z];
            }
            matrix.data[i].i=p->i;
            matrix.data[i].j=p->j;
            matrix.data[i].e=p->e;
        }
        std::cout<<"ok,got("<<p->i<<","<<p->j<<","<<p->e<<")"<<std::endl;
        std::cout<<"so ,pls next"<<std::endl;
    }
    for (int z=0;z<matrix.mu+1;z++)
        matrix.rpos[z]=0;
    int l=1,z=l;
    matrix.rpos[matrix.data[l].i]=1;
    do {
        for (;(matrix.data[z].i+1)<=matrix.data[l].i;matrix.data[z].i++)
            matrix.rpos[matrix.data[z].i+1]=l;
        for (z=l;l<=n&&matrix.data[l].i==matrix.data[z].i;l++);
    }while(l<=n);
    if (matrix.data[n].i!=matrix.mu){
        for (int i=matrix.data[n].i+1;i<=matrix.mu;i++)
            matrix.rpos[i]=n+1;
    }
    
    return is;
}
std::ostream& operator <<(std::ostream& os,Matrix& matrix){
    for (int i=1;i<=matrix.tu;i++)
        os<<"("<<matrix.data[i].i<<","<<matrix.data[i].j<<","<<matrix.data[i].e<<")";
    os<<std::endl;
    for (int i=1;i<=matrix.mu;i++){
        for (Lnode *j=matrix.rhead[i];j;j=j->right)
            os<<"("<<i<<","<<j->j<<","<<j->e<<")";
    }
    os<<std::endl;
    for (int i=1;i<=matrix.nu;i++){
        for (Lnode *j=matrix.chead[i];j;j=j->down)
            os<<"("<<j->i<<","<<i<<","<<j->e<<")";
    }
    os<<std::endl;
    for (int i=1;i<=matrix.mu;i++){
        os<<matrix.rpos[i];
    }
    return os;
}
//the method is not perfect ,because be limited by perform only on List ,and more problem is the result that only update data stored in List but all such as in Array. i will take time to fix this problems.
Matrix& Matrix::operator+=(Matrix& matrix){
    Lnode *pa,*pb,*pre,*tmp;
    Lnode **hl=new Lnode*[matrix.nu+1];
    pre=nullptr;
    for (int i=0;i<matrix.nu+1;i++)
        hl[i]=this->chead[i];
    for (int n=1;n<=this->mu;n++){
        pa=this->rhead[n];
        pb=matrix.rhead[n];
        pre=nullptr;
        while (pb){
            if (pa==nullptr||pa->j>pb->j){
                tmp=new Lnode;
                tmp->i=pb->i;
                tmp->j=pb->j;
                tmp->e=pb->e;
                if (pre==nullptr) this->rhead[pb->i]=tmp;
                else pre->right=tmp;
                tmp->right=pa;pre=tmp;
                if (!this->chead[pb->j]||this->chead[pb->j]->i>tmp->i){
                    tmp->down=this->chead[pb->j]; this->chead[pb->j]=tmp;
                } else{
                    while (hl[pb->j]->down&&hl[pb->j]->i<tmp->i){
                        hl[pb->j]=hl[pb->j]->down;
                    }
                    tmp->down=hl[pb->j]->down;hl[pb->j]->down=tmp;
                    hl[pb->j]=tmp;
                }
                pb=pb->right;
            } else if (pa!=nullptr&&pa->j<pb->j){
                pre=pa;pa=pa->right;
            } else if (pa->j==pb->j) {
                pa->e+=pb->e;
                if (pa->e==0){
                    Lnode* tmp;
                    if (pre==nullptr) this->rhead[pa->i]=pa->right;
                    else pre->right=pa->right;
                    tmp=pa;pa=pa->right;
                    if (this->chead[tmp->j]==tmp) this->chead[tmp->j]=hl[tmp->j]=tmp->down;
                    else {
                        while (hl[tmp->j]->down&&hl[tmp->j]->i<tmp->i){
                            hl[tmp->j]=hl[tmp->j]->down;
                        }
                        hl[tmp->j]->down=tmp->down;
                        delete tmp;
                    }
                }
                pb=pb->right;pa=pa->right;
            }
        }
    }
    delete [] hl;
    return *this;
}
//in like above manner,just on Array ,not on List and update in Array
void Matrix::operator--(){
    int col;
    int* cpot =new int[nu+1];
    Triple* tmp=new Triple[tu+1];
    if (tu){
        for (col=1;col<=nu;++col) cpot[col]=0;
        for (int t=1;t<=tu;t++) ++cpot[data[t].j];
        int t=cpot[1],i;
        cpot[1]=1;
        for (col=2;col<=nu;++col){
            i=cpot[col];
            cpot[col]=cpot[col-1]+t;
            t=i;
        }
        for (int p=1;p<=tu;p++){
            col=data[p].j;i=cpot[col];
            tmp[i].i=data[p].j;
            tmp[i].j=data[p].i;
            tmp[i].e=data[p].e;
            ++cpot[col];
        }
        delete [] data;
        data=tmp;
        for (int z=0;z<mu+1;z++)
             rpos[z]=0;
        int l=1;
        do {
            rpos[data[l].i]=l;
            for (int z=l;l<=tu&&data[l].i==data[z].i;l++);
        }while(l<=tu);
        t=mu;
        mu=nu;
        nu=t;
    }
}
//in like above manner,just on Array ,not on List and update in Array
void Matrix::operator*=(Matrix& matrix){
    if (nu==matrix.mu&&tu*matrix.tu!=0){
        Triple tmp[(mu*matrix.nu)+1];
        int* rposi=new int[mu+1];
        int tutu=0,tp=0,brow,t;
        int ctemp[matrix.nu+1];
        for (int arrow=data[1].i;arrow<=mu;arrow++){
            for (int i=0;i<=matrix.nu;i++)
                ctemp[i]=0;
            rposi[arrow]=tutu+1;
            if (arrow<mu)tp=rpos[arrow+1];
                else tp=tu+1;
            for (int p=rpos[arrow];p<tp;p++){
                brow=data[p].j;
                if(brow<matrix.mu) t=matrix.rpos[brow+1];
                else t=matrix.tu+1;
                for (int q=matrix.rpos[brow],ccol;q<t;++q){
                    ccol=matrix.data[q].j;
                    ctemp[ccol]+=data[p].e*matrix.data[q].e;
                }
            }
            for (int ccol=1;ccol<=matrix.nu;++ccol){
                if(ctemp[ccol]){
                    tutu++;
                    tmp[tutu].e=ctemp[ccol];
                    tmp[tutu].i=arrow;
                    tmp[tutu].j=ccol;
                }
            }
        }
        Triple* dep=new Triple[tutu+1];
        for (int i=1;i<=tutu;i++) {
            dep[i].i=tmp[i].i;
            dep[i].j=tmp[i].j;
            dep[i].e=tmp[i].e;
        }
        delete [] data;
        delete [] rpos;
        data=dep;
        rpos=rposi;
        nu=matrix.nu;
        tu=tutu;
    }
}
