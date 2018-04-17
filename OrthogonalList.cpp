//
// Created by 朱国伟 on 2018/4/14.
//

#include "OrthogonalList.h"
#include<iostream>
using namespace std;

int main(){
    linknode T;
    linknode *ha = NULL,*hb = NULL,*hc = NULL;

    ha = T.createlindmat();
    T.display(ha);
    T.display_(ha);
    hb = T.createlindmat();
    T.display(hb);
    T.display_(hb);
    hc = T.addlindmat(ha,hb);
    cout<<"结果"<<endl;
    T.display(hc);
    T.display_(hc);

}