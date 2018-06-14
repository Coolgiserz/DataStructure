//
// Created by zhuge on 2018/6/2.
//

#include "MySearch.h"
#include <iostream>

int MySearch::binary_search(int *a,int len, int x) {


    int high= len-1;
    int low = 0;

    while(low<=high){
        int mid = (high+low)/2;
//        std::cout<<a[mid]<<" ";
        if(a[mid]>x){
            high = mid-1;
        }else if(a[mid]<x){
            low = mid+1;
        }
        if(a[mid]==x){
            return mid;
        }
    }
    return -1;


}
//int MySearch::binary_search(int a[], int x) {
//
//}


tree* MySearch::binary_tree_search(tree *t, int x) {
    tree *p = t;
    while(p!=NULL){
        if(x==p->data){
            std::cout<<"找到了"<<p->data<<"hh";

            return p;
        }else if(x>p->data){
            p = p->rchild;
        }else if(x<p->data){
            p = p->lchild;
        }
    }
    std::cout<<"没找到";
    return NULL;
}

//tree* MySearch::build_tree(tree *root,int *a,int len) {
////    tree *t = NULL;
//    for(int i = 1;i<=len;i++){
//
//        insert(root,a[i]);
//    }
//
//    return root;
//}

tree* MySearch::build_tree(int *a, int len) {
//    tree *tr = new tree;
//    tr->data=;
//    for(int i=1;i<=len;i++){
//        std::cout<<"第"<<i<<"次插入:"<<a[i-1]<<std::endl;
//        insert(tr,a[i-1]);
//       // tr的地址并没有改变
//    }
//    return tr;
    bool flag;
    tree *tmp;
    tree *tr = new tree;
    tr->data = a[0];
    tr->lchild = NULL;
    tr->rchild = NULL;

    for(int i=1;i<len;i++){
        tmp = tr;
        while(true){
            if(a[i]>tmp->data){
                if(tmp->rchild!=NULL){
                    tmp = tmp->rchild;
                    flag = true;
                }else{
                    flag = true;
                    break;
                }


            }else if(a[i]<=tmp->data){
                if(tmp->lchild!=NULL){
                    tmp = tmp->lchild;
                    flag = false;
                }else{
                    flag = false;
                    break;
                }
            }else{

                break;
            }



        }
        tree *h = new tree;
        h->data = a[i];
        h->lchild =NULL;
        h->rchild= NULL;

        if(flag){
            tmp->rchild = h;
        }else{
            tmp->lchild = h;
        }


    }

    return tr;
}
void MySearch::hsashtable_build(int *H, int m) {
    for(int i = 0;i<m;i++){
        HT[i]=0;
    }
    for(int i = 0;i<n;i++){

        int j = H[i]%13;
        HT[j] = H[i];
//        std::cout<<HT[j]<<" ";

    }



}
void MySearch::hashtable_linear_search(int *T, int key) {

    int p = key%13;
    if(T[p]==key){
        std::cout<<"找到"<<p<<":"<<T[p];

    }else{
        std::cout<<"没找到";

    }


    std::cout<<"找到"<<T[p];

}

void MySearch::inorder(tree *root) {

    tree *p =  root;
    if(p!=NULL){
        inorder(p->lchild);
        std::cout<<p->data<<" ";
        inorder(p->rchild);
    }


}

void MySearch::binary_delete(tree *t, int x) {
    tree *p = t,*s = NULL;
    while(p!=NULL){
        if(p->data==x){
            break;
        }else if(p->data>=x){
            s  = p;
            p  = p->lchild;
        }else{
            s  = p;
            p = p->rchild;
        }
    }
    if(p==NULL){
        std::cout<<"不存在的结点";
        return;   //表示没找到
    }

    //当待删除结点是叶子结点的时候
    if(p->lchild==NULL&&p->rchild==NULL){
        if(p==t){
            t =NULL;
        } else{
            p->lchild=NULL;
            p->rchild=NULL;
        }
        delete p;

        //当待删除结点仅仅是左孩子或者右孩子时

    }else if(p->lchild==NULL||p->rchild==NULL){
        if(p==t){
            if(p->lchild==NULL){
                t = p->rchild;
            }else{
                t = p->lchild;
            }
        }else{
            if(p==s->lchild&&p->lchild==NULL){
                s->lchild = p->rchild;

            }else if(p==s->lchild&&p->rchild==NULL){

                s->lchild = p->lchild;

            }else if(p==s->rchild&&p->lchild==NULL){
                s->rchild = p->rchild;
            }else if(p==s->rchild&&p->rchild == NULL){

                s->rchild = p->lchild;

            }



        }
        delete p;


    }else{
        tree *tmp = p,*q = p->lchild;
        while(q->rchild!=NULL){

            tmp = q;
            q = q->rchild;


        }

        p->data = q->data;
        if(tmp ==p){
            p->lchild = q->lchild;
        }else{
            tmp->rchild = q->lchild;
        }
        delete q;
    }
    //待删除结点的根结点有两个孩子的时候







}
//void MySearch::insert(tree *t, int x) {
//
//    std::cout<< static_cast<const void *>(t)<<" ";
//
//    if(0==t->data){
//        std::cout<<x<<"  ";
//
//        tree *p = new tree;
//        p->data = x;
//        p->lchild = new tree;
//        p->rchild = new tree;
//        p->lchild->data = 0;
//        p->rchild->data = 0;
//        t = p;
//        std::cout<<t->data<<"hh";
////        std::cout<< static_cast<const void *>(t)<<" ";
//    }else if(t->data>x){
//        std::cout<<x<<"h1";
//        insert(t->lchild,x);
//    }else{
//        std::cout<<x<<"h2";
//
//        insert(t->rchild,x);
//    }
//
//}