//
// Created by 朱国伟 on 2018/4/14.
//

#include "OrthogonalList.h"
#include<iostream>
using namespace std;

int main(){
    linknode *p,*q,T;
    linknode *hm = NULL;
    p = new linknode;
    q = new linknode;
    hm = T.createlindmat();
    p = hm->k.next;
    while(p->k.next!=hm){
        cout<<"here1";
        q = p->rpoint;
//        cout<<q->i<<" "<<q->j<<" "<<q->k.value<<" "<<endl;
        while(q->rpoint!=p){
            cout<<"here2";
            cout<<q->i<<" "<<q->j<<" "<<q->k.value<<" "<<endl;
            q = q->rpoint;
        }

        if(p!=q){
            cout<<"here3";
            cout<<q->i<<" "<<q->j<<" "<<q->k.value<<" ";
        }
        cout<<endl;
        p=p->k.next;
    }


}