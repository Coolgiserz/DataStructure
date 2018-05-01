//
// Created by 朱国伟 on 2018/4/30.
//

#include <iostream>
#include "bitreeCalc.h"
using namespace std;

int main(){

    Bitree *tree;
    int n=0;
//    cout<<"请输入前序序列"<<endl;
//    cout<<"请输入中序序列"<<endl;
    int count=tree->treenode(tree);
//    int i=0;
//    while(pre[i]!='\0'){
//        count++;
//        i++;
//    }
//    cout<<count;
    tree = tree->creat(0, count-1,0, count-1);
//    tree = tree->creat(0, sizeof(pre)-1,0, sizeof(ind)-1);
    tree->preorder1(tree);
    cout<<endl<<"----------------"<<endl;
    tree->inorder1(tree);
    cout<<endl<<"----------------"<<endl;

//    tree->postorder1(tree);
//    tree->lorder(tree);
    cout<<tree->treeleaf(tree,n);
    cout<<tree->treehigh(tree);
    cout<<tree->treenode(tree);
    tree->displaychild(tree,'A');
    tree->displaychild(tree,'E');
}