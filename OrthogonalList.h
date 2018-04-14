//
// Created by 朱国伟 on 2018/4/14.
//

#ifndef DATASTRUCT_ORTHOGONALLIST_H
#define DATASTRUCT_ORTHOGONALLIST_H
#include<iostream>
using namespace std;

class linknode {
public:
    int i,j;
    union vnext{
        int value;
        linknode *next;
    }k;
    linknode *rpoint,*cpoint;
    linknode *createlindmat();
    void display_(linknode *hm);
    void display(linknode *hm);
};

linknode *linknode::createlindmat(){
    int m,n,terms,s,i,j,v;
    linknode *hm,*p,*q,*cp[100];
    cout<<"请输入稀疏矩阵的行数、列数以及非零元个数:"<<endl;
    cin>>m>>n>>terms;

    if(m>n){
        s=m;
    }else{
        s=n;
    }
    hm = new linknode;
    hm->i = m;
    hm->j = n;
    cp[0] = hm;

    //建立表头结点循环链表

    for(i=1;i<=s;i++){
        p = new linknode;
        p->i = 0;
        p->j = 0;
        p->rpoint = p;
        p->cpoint = p;
        cp[i] = p;
        cp[i-1]->k.next = p;
    }
    cp[s]->k.next = hm;

    //输入稀疏矩阵中非零元组成的三元组表
    for(int x=1;x<=terms;x++){
        cout<<"请输入三元组:"<<endl;
        cin>>i>>j>>v;
        p = new linknode;
        p->i = i;
        p->j = j;
        p->k.value = v;
        //将p插入到第i行链表中
        q = cp[i];
        while((q->rpoint!=cp[i])&&(q->rpoint->j<j)){
            q = q->rpoint;
        }
        p->rpoint = q->rpoint;
        q->rpoint = p;

        //将p插入到第j列链表中
        q = cp[j];
        while((q->cpoint!=cp[j])&&(q->cpoint->i<i)){
            q = q->cpoint;
        }
        p->cpoint = q->cpoint;
        q->cpoint = p;



    }

    return hm;

}
//按照三元组表的形式输出
void linknode::display(linknode *hm) {
    linknode *p,*q;
    p = hm->k.next;
    while(p->k.next!=hm){

        q = p->rpoint;
//        cout<<q->i<<" "<<q->j<<" "<<q->k.value<<" "<<endl;
        while(q->rpoint!=p){

            cout<<q->i<<" "<<q->j<<" "<<q->k.value<<" "<<endl;
            q = q->rpoint;
        }

        if(p!=q){
 
            cout<<q->i<<" "<<q->j<<" "<<q->k.value<<" ";
        }
        cout<<endl;
        p=p->k.next;
    }
}
//按照正常矩阵的形式输出
void linknode::display_(linknode *hm) {

}


#endif //DATASTRUCT_ORTHOGONALLIST_H
