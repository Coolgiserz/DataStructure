

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
    a.transpose(a,b);
    a.fasttrans(a,b);
//    linknode *p,*q,T;
//    linknode *hm=NULL;
//    hm = T.createlindmat();
//    p = hm->k.next;
//    while(p->k.next!=hm){
//        q=p->rpoint;
//        while(q->rpoint!=p){
//            cout<<q->i<<" "<<q->j<<" "<<q->k.v<<"  ";
//            q = q->rpoint;
//        }
//        if(p!=q){
//            cout<<q->i<<" "<<q->j<<" "<<q->k.v<<" ";
//            cout<<endl;
//            p = p->k.next;
//        }
//    }
}