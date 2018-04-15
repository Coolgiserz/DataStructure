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
    linknode *addlindmat(linknode *ha, linknode *hb);
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

linknode* linknode::addlindmat(linknode *ha, linknode *hb) {
    linknode *pa,*pb,*qa,*ca,*cb,*p,*q;
    linknode *hl[100];
    int i,j,n;
    if((ha->i!=hb->i)||(ha->j!=ha->j)){
        cout<<"矩阵不匹配，不能相加！"<<endl;
    }else{
        p = ha->k.next;
        n = ha->j;
        for(i=1;i<=n;i++){
            hl[i] = p;
            p = p->k.next;
        }
        ca = ha->k.next;
        cb = hb->k.next;
        while(ca->i==0){
            pa = ca->rpoint;pb = cb->rpoint;
            qa = ca;
            while(pb->j!=0){
                if((pa->j<pb->j)&&(pa->j!=0)){

                }else if((pa->j<pb->j)||pa->j==0){
                    p = new linknode;
                    p->i = pb->i;
                    p->j = pb->j;
                    p->k.value = pb->k.value;
                    qa->rpoint = p;
                    p->rpoint = pa;
                    qa = p;
                    pb = pb->rpoint;
                    j = p->j;
                    q = hl[j]->cpoint;
                    while((q->i<p->i)&&(q->i!=0)){
                        hl[j] = q;
                        q = hl[j]->cpoint;
                    }
                    hl[j]->cpoint = p;
                    p->cpoint = q;
                    hl[j] = p;
                }else{
                    pa->k.value = pa->k.value + pb->k.value;
                    if(pa->k.value == 0){
                        qa->rpoint = pa->rpoint;
                        j = pa->j;
                        q = hl[j]->cpoint;
                        while(q->i<pa->i){
                            hl[j] = q;
                            q = hl[j]->cpoint;
                        }
                        hl[j]->cpoint = q->cpoint;
                        pa = pa->rpoint;
                        pb = pb->rpoint;
                        delete q;
                    }else{
                        qa = pa;
                        pa = pa->rpoint;
                        pb = pb->rpoint;
                    }
                }
            }
            ca = ca->k.next;
            cb = cb->k.next;
        }
    }

    return ha;
}

#endif //DATASTRUCT_ORTHOGONALLIST_H
