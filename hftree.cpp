//
// Created by zhuge on 2018/5/5.
//

#include <iostream>
#include "hftree.h"
#include <iomanip>
#include <sstream>
using namespace std;

int main(){
    tree t;
    t.creathftree();
    //初始化hfcode数组
//    for(int i=1;i<=n;i++){
//        hfcode[i] = 0;
//    }
//    t.encodehf(n,hfcode[n+1]);
    for(int w=1;w<=n;w++){
        hf[w].local=0;
    }
    for(int i=1;i<=n;i++){
        t.encodehf(i);

    }

    /*
     * 测试代码
     *
     * */
    int g=1;
   for(g=1;g<=n;g++){
       cout<<hf[g].value<<" "<<hf[g].weight<<" ";
        for (int h = hf[g].local-1; h >= 0; h--){

            cout<< hf[g].hfcode[h];
        }
       cout<<endl;
//        cout<<"hh";
    }


    /**
     * 输入要查的编码，我给你还原
     *
     *
     * */
    cout<<"输入二进制编码，#则退出";
    int code;
    cin>>code;
    while(code!=2){
        for(g=1;g<=n;g++){
            stringstream ss;
            for (int h = hf[g].local-1; h >= 0; h--){
                ss<<hf[g].hfcode[h];
//                cout<< hf[g].hfcode[h];
            }
            string str = ss.str();
            int tmp = atof(str.c_str());
            cout<<tmp;
            cout<<endl;
//        cout<<"hh";
        }
        cin>>code;
    }
}


void tree::creathftree() {
    //初始化
    int i,j;
    int l1,l2;                //w1和w2代表每次循环中的最小权重，l1和l2代表每次循环中最小权重对应的索引

    float w1,w2;
    for(int i=1;i<=m;i++){
        hf[i].value = '#';
        hf[i].weight = 0;
        hf[i].parent = 0;
        hf[i].lchild = 0;
        hf[i].rchild = 0;
    }
//    for(int i=1;i<=n;i++){
//        cin>>hf[i].weight;
//    }
hf[1].weight=5,hf[2].weight=29,hf[3].weight=7,hf[4].weight=8,hf[5].weight=14,hf[6].weight=23;hf[7].weight=3;hf[8].weight=11;
    hf[1].value='a';
    hf[2].value='b';
    hf[3].value='c';
    hf[4].value='d';
    hf[5].value='e';
    hf[6].value='f';
    hf[7].value='g';
    hf[8].value='h';
    //建立哈夫曼树
    for( i = n+1;i<=m;i++){
        l1 = l2 = 0;
        w1 = w2 = 32767;
        for( j=1;j<=i-1;j++){                   //从前面n个元素中选出最小的两权值
            if(hf[j].parent == 0){              //当其父结点不为空时说明已经选过，要排除掉，也就是父结点为0时加入筛选队列
                if(hf[j].weight<w1){
                    w2 = w1;
                    w1 = hf[j].weight;
                    l2 = l1;
                    l1 = j;
//                    cout<<w1<<endl;
//                    cout<<w2<<endl;
//                    cout<<endl<<endl;

                }else if(hf[j].weight<w2){

                        w2 = hf[j].weight;
                        l2 = j;
//                    cout<<w1<<endl;
//
//                    cout<<w2<<endl;
//                    cout<<endl<<endl;

                    }




            }
        }
        hf[l1].parent = i;
        hf[l2].parent = i;

        hf[i].lchild = l1;
        hf[i].rchild = l2;
        hf[i].weight = hf[l1].weight+hf[l2].weight;
        cout<<hf[i].weight<<endl;
    }

    //输出哈夫曼树

    for(i=1;i<=m;i++){
        cout<<i<<setw(4)<<setw(4)<<hf[i].value<<setw(4)<<hf[i].weight<<setw(4)<<hf[i].parent<<setw(4)<<hf[i].lchild<<setw(4)<<hf[i].rchild<<endl;
    }

}
/*
 * 用栈，遍历哈夫曼树，算出每一个结点的路径
 * n表示叶子结点个数
 *
 */

void tree::encodehf(int _n) {
//    cout<<"Hello";
    int q=0;    //用座hfcode数组的指示器
    int i=1,j=1;    //循环变量
    int parent = hf[_n].parent;
    int save = _n;
    while(parent<=m&parent>0){    //要遍历整个双亲孩子表示法表示的哈夫曼树数组
//        parent = hf[i].parent;


        if(hf[parent].lchild == _n){
//                cout<<"Hello"; for(int w=1;w<=n;w++){
//            cout<<hf[j].local;

            hf[save].hfcode[hf[save].local++] = 0;
//            cout<<hf[j].local;

        }
        if(hf[parent].rchild == _n){
            hf[save].hfcode[hf[save].local++] = 1;
        }
       _n = parent;
        parent = hf[_n].parent;


    }

//    for (parent = hf[3].local-1; parent >= 0; parent--){
//        cout<<"2";
////        cout << hfcode[parent];
//    cout<< hf[3].hfcode[hf[3].local];
//
//    }

//    cout << endl;

}