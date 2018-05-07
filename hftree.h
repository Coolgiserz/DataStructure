//
// Created by zhuge on 2018/5/5.
//

#ifndef 树和二叉树_HFTREE_H
#define 树和二叉树_HFTREE_H

#endif //树和二叉树_HFTREE_H

#include <iostream>
using namespace std;
/**
 * 双亲孩子表示法！！！
 * 需要给定叶子结点个数，即权值个数n
 * 从而得到，合并以后共有2n-1个结点
 *
 *https://github.com/Csuerzhuge/DataStructure.git
 *
 * **/

const int n = 8;                //权值个数
const int m = 2*n - 1;          //哈夫曼树结点个数
const int maxsize = 20;

//class code{
//public:
//    char value;
//    float weight;
//    int hfcode[maxsize];
//};

class tree{
public:
    float weight;
    char value;
    int parent;
    int local;      //用来存储工作指示器
    string code;
    int lchild;
    int rchild;
    int hfcode[n+1];   //用来存放哈夫曼树编码

    void creathftree();
//    void encodehf(int n,int hfcode[n+1]);
    void encodehf(int _n);

    void decodestr();

};


tree hf[m+1];       //创建哈夫数组的全局变量
//int hfcode[n+1];   //用来存放哈夫曼树编码
