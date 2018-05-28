//
// Created by zhuge on 2018/5/27.
//
#include "SmallestTree.h"
#include <iostream>
using namespace std;
void tree::prim(tree &t) {
    int i,j,k,min,t1,m,w;
    for(i=1;i<n;i++){
        t.ct[i].fromvex=1;
        t.ct[i].endvex=i+1;
        t.ct[i].weight=t.s[1][i+1];
    }
    for(k=2;k<=n;k++){
        min=32767;
        m=k-1;
        for(j=k-1;j<n;j++){
            if(t.ct[j].weight<min){
                min=t.ct[j].weight;
                m=j;
            }
        }
        edgeset temp=t.ct[k-1];
        t.ct[k-1]=t.ct[m];
        t.ct[m]=temp;
        j=t.ct[k-1].endvex;
        for(i=k;i<n;i++){
            t1=t.ct[i].endvex;
            w=t.s[j][t1];
            if(w<t.ct[i].weight){
                t.ct[i].weight=w;
                t.ct[i].fromvex=j;
            }
        }

    }







}