//
// Created by zhuge on 2018/5/27.
//

#include "MyGraph.h"
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

void MyGraph::initgraph( int vNum, int eNum) {

//    for(int i=0;i<vNum;i++){
//        this->vertex[i]=a[i];
//    }
    //输入所有顶点
    for(int i=1;i<=vNum;i++){
        cin>>this->vertex[i];
    }
    //初始化邻接矩阵
    this->vertexNum=vNum;
    this->arcNum=eNum;
    for(int i=1;i<=vNum;i++){
        for(int j=1;j<=vNum;j++){
            if(i!=j) {

                this->arc[i][j] = infinity;
            }else{
                this->arc[i][j] = 0;
            }
        }
    }

    int i,j,w;
    //赋值
    for(int k=0;k<eNum;k++){
        cout<<"依次输入i、j、w"<<endl;
        cin>>i>>j>>w;
        this->arc[i][j]=w;

    }

}

void MyGraph::display() {
    for(int i=1;i<=this->vertexNum;i++){
        for(int j=1;j<=this->vertexNum;j++){
            cout<<this->arc[i][j]<<"    ";
        }
        cout<<endl;
    }

}

/**
 *
 * 递归实现深度优先遍历
 *
 * **/
void MyGraph::DFS(MyGraph G,int i) {
    cout<<G.vertex[i]<<" ";
    visited[i]=true;

    int j,k;
    k=0;
    for( j=1;j<=G.vertexNum;j++) {

        if(G.arc[i][j]!=0 &&G.arc[i][j]!=infinity && !visited[j]){
            k=j;
            break;
        }
    }
    while(k>0){
        DFS(G,k);
        for(j=1;j<=G.vertexNum;j++){
            if(!visited[j]&&G.arc[i][j]!=0 &&G.arc[i][j]!=infinity){
                k=j;
                break;
            }else{
                k=0;
            }
        }
    }


}
/**
 *
 * 递归实现广度优先遍历
 *
 * **/
queue<int> q;
void MyGraph::BFS(MyGraph G, int v) {
    int i,k;
    cout<<G.vertex[v]<<" ";
    visited1[v]=true;
    q.push(v);
    while(!q.empty()){
        k = q.front();
        q.pop();
        for(i=1;i<=G.vertexNum;i++){
            if(!visited1[i]&&G.arc[k][i]!=0&&G.arc[k][i]!=infinity){
                cout<<G.vertex[i]<<" ";
                visited1[i]=true;
                q.push(i);
            }
        }
    }




}
/**
 *
 * 由邻接矩阵转换成邻接表的结构
 *
 * **/
void MyGraph::totable(MyGraph G) {
    int i,j,k;
    link *s;
    //建立邻接表的表头结点
    for(i=1;i<=G.vertexNum;i++){
        G.table[i].data=i-1;
        G.table[i].next=NULL;
    }

    for(i=1;i<=G.vertexNum;i++){
        for(j=1;j<=G.vertexNum;j++){
            if(G.arc[i][j]!=0&&G.arc[i][j]!=infinity){
//                cout<<"ha";
                s = new link;
                s->data=j;
                s->next = G.table[i].next;
                G.table[i].next = s;
//                cout<<"ha1";
//                s->weight=G.vertex[i][j];
            }
        }
    }

    for(int i=1;i<=G.vertexNum;i++){
        link *p=G.table[i].next;
        cout<<"("<<i<<":"<<i-1<<")"<<"->";
        while(p->next!=NULL){
            cout<<p->data-1<<"->";
            p=p->next;
        }
        cout<<p->data-1<<endl;
    }

}
/**
 * 迪杰斯科拉求有源点到其余各点的最短路径
 *
 *
 * **/
void MyGraph::djskl(MyGraph G,const int v1) {
    int i;int n=G.vertexNum;
     for(i=1;i<=G.vertexNum;i++){
         G.dist[i]=G.arc[v1][i];
         G.s[i]=0;
         if((i!=v1)&&(G.dist[i]<infinity)){
             G.path[i]=v1;
         }else{
             G.path[i]=0;
         }

     }
    G.s[v1]=1;G.dist[v1]=0;
    for(i=1;i<G.vertexNum;i++){
        int min = infinity;int u=v1;
        for(int j=1;j<=G.vertexNum;j++){
            if(!G.s[j]&&G.dist[j]<min){
                u=j,min=G.dist[j];
            }
            G.s[u]=1;
        }
        for(int w=1;w<=G.vertexNum;w++){
            if(!G.s[w]&&G.arc[u][w]<infinity&&G.dist[u]+G.arc[u][w]<G.dist[w]){
                G.dist[w]=G.dist[u]+G.arc[u][w];
                G.path[w]=u;
            }
        }
    }
    for(i=1;i<=G.vertexNum;i++){
        if(i!=v1){
            cout<<G.dist[i]<<": ";
            cout<<i-1;
            int pre=G.path[i];
            while(pre!=0){
                cout<<"<-"<<pre-1;
                pre=G.path[pre];
            }
            cout<<endl;
        }
    }

}

void MyGraph::flyd(MyGraph G, const int v1) {
    int i,j;int n=G.vertexNum;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            G.helpera[i][j]=G.arc[i][j];
            if(i!=j&&G.helpera[i][j]<infinity){
                G.helperpath[i][j]=i;
            }else{
                G.helperpath[i][j]=0;
            }

        }
    }
    for(int k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                { if(G.helpera[i][k]+G.helpera[k][j]<G.helpera[i][j]){
                        G.helpera[i][j]=G.helpera[i][k]+G.helpera[k][j];
                        G.helperpath[i][j]=G.helperpath[k][j];
                    }
                }

            }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j){
                cout<<"距离"<<G.helpera[i][j]<<":";
                int next=G.helperpath[i][j];
                cout<<j-1;
                while(next!=i){
                    cout<<"<-"<<next-1;
                    next=G.helperpath[i][next];
                }
                cout<<"<-"<<i-1<<endl;
            }
        }
    }


}
//void MyGraph::display1() {
//
//
//}