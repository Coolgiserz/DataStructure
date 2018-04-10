//
// Created by 朱国伟 on 2018/4/6.
//

#ifndef DATASTRUCT_MATR_H
#define DATASTRUCT_MATR_H

#include <iostream>
using namespace std;
const int maxsize=100;
class node{
public:
    int i,j;
    int v;
};
class Matr {
public:
    int rows,cols;
    int terms;
    node data[maxsize];
    void transpose(Matr a,Matr b);
    void fasttrans(Matr a,Matr b);
};

//按照列序进行转置
void Matr::transpose(Matr a, Matr b) {
    b.rows = a.cols;
    b.cols = a.rows;
    b.terms = a.terms;
    if(b.terms>0){
        int bno=0;
        for(int col=0;col<a.cols;col++){
            for(int ano=0;ano<a.terms;ano++){
                if(a.data[ano].j==col){
                    b.data[bno].j =a.data[ano].i;
                    b.data[bno].i = a.data[ano].j;
                    b.data[bno].v = a.data[ano].v;
                    bno++;
                }
            }
        }
    }for(int i=0;i<a.terms;i++){
        std::cout<<b.data[i].i<<" "<<b.data[i].j<<" "<<b.data[i].v<<std::endl;
    }

}

//按照行序进行转置
void Matr::fasttrans(Matr a, Matr b) {
    b.rows = a.cols;
    b.cols = a.rows;
    b.terms = a.terms;
    int col;
    int num[maxsize];
    if(b.terms>0){
        for(col=0;col<=a.cols;col++){
            num[col]=0;
        }

        for(int i=0;i<a.terms;i++){
            col = a.data[i].j;
            num[col]++;
        }
        int pos[maxsize];
        pos[0]=0;
        for(col=1;col<a.cols;col++){
            pos[col]=pos[col-1]+num[col-1];
        }
        for(int i=0;i<a.terms;i++){
            col = a.data[i].j;
            int bno = pos[col];
            b.data[bno].i = a.data[i].j;
            b.data[bno].j = a.data[i].i;
            b.data[bno].v = a.data[i].v;
            pos[col]++;
        }

        for(int i=0;i<b.terms;i++){
            cout<<b.data[i].i<<" "<<b.data[i].j<<" "<<b.data[i].v<<endl;
        }

    }



}

#endif //DATASTRUCT_MATR_H
