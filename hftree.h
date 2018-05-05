//
// Created by zhuge on 2018/5/5.
//

#ifndef 树和二叉树_HFTREE_H
#define 树和二叉树_HFTREE_H

#endif //树和二叉树_HFTREE_H

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

class code{
public:
    char value;
    float weight;
};

class tree{
public:
    float weight;
    char value;
    int parent;
    int lchild;
    int rchild;
    void creathftree();
    void encodehf();
    void decodestr();

};
tree hf[m+1];
code hfcode[n+1];   //用来存放哈夫曼树编码


