//
// Created by zhuge on 2018/4/30.
//

#ifndef 树和二叉树_BITREECALC_H
#define 树和二叉树_BITREECALC_H

#endif //树和二叉树_BITREECALC_H
#include <iostream>
using namespace std;
const int maxsize = 100;
char pre[maxsize]="ABDGHCEFI";
char ind[maxsize]="GDHBAECIF";
//const int maxsize = 100;

//char pre[50]="ABDGCEFH";
//char ind[50]="BGDAECFH";//若用静态数组，则求子树高度以及……等会出错哦
/**
 * 功能：输入二叉树的中序、前序序列可以建立二叉树
 * 输出某一结点的左右孩子结点的值
 * 输出二叉树的深度
 * 输出二叉树的结点个数
 * 输出二叉树的叶子结点个数
 * 用递归算法和非递归算法实现二叉树的先序遍历、中序遍历和后序遍历
 * 输出层次遍历的结果
 * 将一棵二叉树的左右子树互换
 *
 * **/

typedef char elemtype;
class Bitree{
public:
    elemtype data;
//    char pre[] = new char;
//    char ind[] = new char;
    Bitree *lchild,*rchild;
//        Bitree(){
//          cout<<"请输入前序序列："<<endl;
//            cout<<"请输入中序序列："<<endl;
//        }
    Bitree *creat(int l1,int h1,int l2,int h2);
     int treehigh(Bitree *t);
    int treeleaf(Bitree *root,int &n);
    int treenode(Bitree *t);
    void displaychild(Bitree *t,char x);
//    Bitree find
    void preorder(Bitree *root);
    void inorder(Bitree *root);
    void postorder(Bitree *root);
    void preorder1(Bitree *root);
    void inorder1(Bitree *root);
    void postorder1(Bitree *root);
    void lorder(Bitree *root);
    void exchange(Bitree *root);
};

//build a bitree according to the preorder and inorder result最后返回一棵二叉树
Bitree* Bitree::creat(int l1,int h1,int l2,int h2) {
    Bitree *tree;int s;
    if(h2-l2!=h1-l1){
        cout<<"input error!";
    }else{
        if(l1>h1){
            tree = NULL;
        }else{
            tree = new Bitree;
            tree->data = pre[l1];
            s = l2;
            while((s<h2)&&(pre[l1]!=ind[s])){
                s++;

            }
            if(ind[s]!=pre[l1]){
                cout<<"input error!";
            }else{
                tree->lchild = creat(l1+1,s-l2+l1,l2,s-1);
                tree->rchild = creat(s-l2+l1+1,h1,s+1,h2);
            }
        }

    }
    return tree;
}
/*******************************求孩子结点************************************************/
void Bitree::displaychild(Bitree *root,char x) {
    Bitree *p = root;

    if(p!=NULL){
        if(p->data==x){
            cout<<"找到了";
            if(p->lchild!=NULL){
                cout<<"左孩子:";
                cout<<p->lchild->data<<endl;
//                cout<<"左孩子不存在哦";
            }else{
                cout<<"左孩子不存在哦";
            }
            if(p->rchild!=NULL){
                cout<<"右孩子:";
                cout<<p->rchild->data<<endl;
            }else{
                cout<<"右孩子不存在哦";
            }

        }
        displaychild(p->lchild, x);
        displaychild(p->rchild, x);

    }




}
/*******************************二叉树高度************************************************/
int Bitree::treehigh(Bitree *t) {
    int h,lh,rh;
    if(t==NULL){
        h=0;
    }else{
        lh = treehigh(t->lchild);
        rh = treehigh(t->rchild);
        if(lh>=rh){
            h = lh+1;
        }else{
            h = rh+1;
        }
    }
    return h;
}
/*******************************结点个数************************************************/
int Bitree::treenode(Bitree *t) {
    int count1=0,count2=0;
    if(t==NULL){
        return 0;
    }else{

        int i=0;
        while(pre[i]!='\0'){
            count1++;
            i++;
        }
        i=0;
        while(pre[i]!='\0'){
            count2++;
            i++;
        }
        if(count1!=count2){
            cout<<"不存在这棵树";
        }
    }
    return count1;


}
/*****************************叶子结点个数************************************************/
int Bitree::treeleaf(Bitree *root, int &n) {
    if (root!=NULL){
        if((root->lchild==NULL)&&(root->rchild==NULL)){
            n++;
        }
        n=treeleaf(root->lchild,n);
        n=treeleaf(root->rchild,n);

    }
    return n;

}

/*****************************遍历算法************************************************/
//前序递归遍历
void Bitree::preorder(Bitree *root) {
    Bitree *p = root;

   if(p!=NULL){
        cout<<p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

//中序递归遍历
void Bitree::inorder(Bitree *root) {
    Bitree *p = root;

    if(p!=NULL){

        inorder(p->lchild);
        cout<<p->data;
        inorder(p->rchild);
    }
}

//后序递归遍历
void Bitree::postorder(Bitree *root) {
    Bitree *p = root;

    if(p!=NULL){

        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data;
    }
}
//前序非递归遍历.栈
void Bitree::preorder1(Bitree *root) {
    Bitree *s[maxsize];//栈：用于存储整树与子树根结点
    int top=0;        //栈顶指示器
    Bitree *p = root;
    //当栈不为空或者沿着工作指针不为空就循环
    while(p!=NULL || top>0){
        while(p!=NULL){
            s[++top]=p;
            cout<<p->data;
            p = p->lchild;
        }
        if(top>0){
            p = s[top--];
            p = p->rchild;
        }
    }

}
//中序非递归遍历
void Bitree::inorder1(Bitree *root) {
    Bitree *s[maxsize];//栈：用于存储整树与子树根结点
    int top=0;        //栈顶指示器
    Bitree *p = root;
    //当栈不为空或者沿着工作指针不为空就循环
    while(p!=NULL || top>0){
        while(p!=NULL){
            s[++top]=p;
            p = p->lchild;
        }
        if(top>0){
            p = s[top--];
            cout<<p->data;
            p = p->rchild;
        }
    }

}
//后序非递归遍历
void Bitree::postorder1(Bitree *root) {
    Bitree *p,*s1[maxsize];
    int s2[maxsize],top=0,b;
    p = root;
    do{
        while(p!=NULL){
            s1[top]=p;s2[top++]=0;
            p = p->lchild;
        }
        if(top>0){
            b = s2[--top];
            p = s1[top];
            if(b==0){
                s1[top]=p;s2[top++]=1;
                p = p->rchild;
            }else{
                cout<<p->data;
                p = NULL;
            }

        }
    }while(top>0);


}
//层次遍历
void Bitree::lorder(Bitree *root) {
    Bitree *q[maxsize],*p;      //100为队列的最大容量
    int f,r;
    q[0]=root;f=r=0;        //如果从q[1] 开始则会报错abort 6
    while(f<=r){
        p = q[f];
        f++;
        cout<<p->data;
        if(p->lchild!=NULL){
            r++;
            q[r]=p->lchild;
        }
        if(p->rchild!=NULL){
            r++;
            q[r]=p->rchild;
        }
    }
}
/*****************************遍历算法结束************************************************/
/*****************************互换左右子树************************************************/

void Bitree::exchange(Bitree *root) {
    Bitree *p = root;
    Bitree *t = new Bitree;
    if(p!=NULL){
        exchange(p->lchild);
        t = p->rchild;
        p->rchild = p->lchild;
        p->lchild = t;
        exchange(p->rchild);
    }



}
