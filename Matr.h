

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

//稀疏矩阵数据结构
class linknode{
public:
    int i,j;
    union vnext{
        int v;
        linknode *next;
    }k;
    linknode *cpoint,*rpoint;
    linknode *createlindmat();
};
//稀疏矩阵的建立
linknode* linknode::createlindmat() {
    int m,n,terms,s,i,j,v;
    linknode *p,*q,*cp[100],*hm;
    cout<<"请输入稀疏矩阵的行、列数以及非零元的个数"<<endl;
    cin>>m>>n>>terms;
    if(m>n){
        s=m;
    }else{
        s=n;
    }
    hm = new linknode;
    hm->i=m;
    hm->j=n;
    cp[0] = hm;
    for(i=1;i<=s;i++){
        p = new linknode;
        p->i=0;
        p->j=0;
        p->rpoint = p;
        p->cpoint = p;
        cp[i] = p;
        cp[i-1]->k.next = p;
    }
    cp[s]->k.next = hm;
    for(int x=1;x<terms;x++){
        cout<<"请输入一个三元组(i,j,v)"<<endl;
        cin>>i>>j>>v;                       //输入一个非零元的三元组
        p = new linknode;
        p->i = i;
        p->j = j;
        p->k.v = v;                         //生成一个三元组的结点
        //以下是将p插入到第i行链表中
        q = cp[i];
        while ((q->rpoint!=cp[i])&&(q->rpoint->j<j)){
            q = q->rpoint;
            p->rpoint=q->rpoint;
            q->rpoint=p;//?

        }

        //以下是将p插入到第j列链表中
        q = cp[j];
        while((q->cpoint!=cp[j])&&q->cpoint->i<i){
            q = q->cpoint;
            p->cpoint = q->cpoint;
            q->cpoint = p;
        }

    }
    return hm;
}
#endif //DATASTRUCT_MATR_H
