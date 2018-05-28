//
// Created by zhuge on 2018/5/27.
//

#include "SmallestTree.cpp"
#include <iostream>


int main(){
    int i,j;tree t;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                t.s[i][j]=0;
            }else{
                t.s[i][j]=32767;
            }
        }
    }
    t.s[1][2]=t.s[2][1]=8;
    t.s[1][3]=t.s[3][1]=3;
    t.s[1][5]=t.s[5][1]=2;
    t.s[2][3]=t.s[3][2]=10;

    t.s[4][2]=t.s[2][4]=2;
    t.s[4][3]=t.s[3][4]=25;
    t.s[5][3]=t.s[3][5]=6;
    t.s[5][4]=t.s[4][5]=12;

    t.s[4][6]=t.s[6][4]=5;
    t.s[4][7]=t.s[7][4]=4;
    t.s[8][6]=t.s[6][8]=9;
    t.s[7][6]=t.s[6][7]=11;

    t.s[8][7]=t.s[7][8]=1;
    t.s[9][6]=t.s[6][9]=1;
    t.s[9][8]=t.s[8][9]=23;
    t.s[1][3]=t.s[3][1]=3;
    t.prim(t);
    for(i=1;i<n;i++){
        cout<<t.ct[i].fromvex<<" ";
        cout<<t.ct[i].endvex<<" ";
        cout<<t.ct[i].weight<<endl;
    }
}