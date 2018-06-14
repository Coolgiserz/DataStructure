//
// Created by zhuge on 2018/6/2.
//

#ifndef DATASTRUCT_MYSEARCH_H
#define DATASTRUCT_MYSEARCH_H

#include <iostream>

const int m = 13;//散列表内存方位
const int n = 10;//序列长度
int HT[m];

class tree{
public:
    int data;
    tree *lchild,*rchild;
};
class MySearch {
public:
    int binary_search(int *a,int len,int x);//注意要将数组长度传进来！！
    tree* binary_tree_search(tree *t,int x);
//    tree* build_tree(tree *root,int *a,int len);
    tree* build_tree(int *a,int len);
    void inorder(tree *root);
    void binary_delete(tree *t,int x);
    void insert(tree *r,int x);
//    static void insert(tree *r,int x){
//
//
//        if(r==NULL){
////            r = new tree;
////            r->data=x;r->lchild=r->rchild=NULL;
//            tree *p = new tree;
//            p->data = x;
//            p->lchild = NULL;
//            p->rchild = NULL;
//            r = p;
//            std::cout<<"请求集合";
//
//        }else if(r->data>=x){
//            std::cout<<x;
//            MySearch::insert(r->lchild,x);
//        }else{
//            std::cout<<x;
//
//            MySearch::insert(r->rchild,x);
//        }
//    };

//    tree *root;
    void hsashtable_build(int *H,int m);
    void hashtable_linear_search(int *T,int key);
};


#endif //DATASTRUCT_MYSEARCH_H
