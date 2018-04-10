//
// Created by 朱国伟 on 2018/4/6.
//

#include "Matr.h"
#include <iostream>
using namespace std;
int main(){

    Matr a,b;
    cin>>a.cols>>a.rows>>a.terms;
    cout<<"请输入三元组表";
    for(int i=0;i<a.terms;i++){
        cin>>a.data[i].i>>a.data[i].j>>a.data[i].v;
    }
    cout<<endl;
    for(int i=0;i<a.terms;i++){
        cout<<a.data[i].i<<a.data[i].j<<a.data[i].v<<endl;
    }
    cout<<endl;
//    a.transpose(a,b);
    a.fasttrans(a,b);
}