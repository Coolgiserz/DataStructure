//
// Created by zhuge on 2018/6/2.
//

#include <iostream>
#include "MySearch.cpp"

using namespace std;
const int testsize =12;
//int arr[testsize];


int main(){
    int arr[12]={2,4,7,9,16,19,25,25,78,90,99,100};
    int len = sizeof(arr)/4;

//    cout<< sizeof(arr)/4;
    cout<<"序列:";
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    MySearch haha;

    /**
     *
     * 二分搜索法测试
     *
     *
     * */
    cout<<"二分搜索测试"<<endl;
    cout<<haha.binary_search(arr,len,1)<<" ";

    cout<<haha.binary_search(arr,len,25)<<" ";
    cout<<haha.binary_search(arr,len,57)<<" ";
    cout<<haha.binary_search(arr,len,99)<<" ";
    /**
       *
       * 二叉排序树测试
       *
       *
       * */
    int len1=10;
    int arr1[10]={34,15,29,63,48,94,25,46,18,7};


//    haha.build_tree(arr1);
    cout<<endl<<"二叉排序树测试"<<endl;
    tree *t =new tree;
    tree *root = NULL;

    t =haha.build_tree(arr1,len1);
    cout<<"中序遍历序列"<<endl;
    haha.inorder(t);
    cout<<endl;
    haha.binary_delete(t,15);
    cout<<endl;
    haha.inorder(t);
    cout<<endl;
//    cout<<t->lchild->data<<"hh";
//    cout<<t->data<<" "<<t->lchild->data;
//    cout<<t->data;

//    tree *q = haha.binary_tree_search(t,48);
    tree *q = haha.binary_tree_search(t,428);
    cout<<endl<<"散裂查找测试"<<endl;

    haha.hsashtable_build(arr1,len);
    haha.hashtable_linear_search(HT,63);
}