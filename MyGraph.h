//
// Created by 朱国伟 on 2018/5/27.
//

#ifndef DATASTRUCT_MYGRAPH_H
#define DATASTRUCT_MYGRAPH_H

#endif //DATASTRUCT_MYGRAPH_H


/***
 *
 * 1、建立有向图的邻接矩阵
 * 2、由有向图的邻接矩阵产生邻接表
 * 3、输出从0开始的深度优先遍历
 * 4、输出从0开始的广度优先遍历
 *
 *
 * ***/

const int maxsize = 10;  //six vertexs
const int egde = 10;//totally ten egdes
const int infinity = 2000;
bool visited[maxsize];
bool visited1[maxsize];
class link{
public:
    int data;
    int weight;
    link *next;
};
class MyGraph{
public:
//    void initgraph(int a[],int vNum,int eNum);
    /**
     *
     * 邻接矩阵
     * **/
    void initgraph(int vNum,int eNum);
    void display();
    void destroygraph();
    void DFS(MyGraph G,int v);
    void BFS(MyGraph G,int v);
    /**
     *
     * 邻接表
     *
     * **/
    void totable(MyGraph G);
    void display1();

    /**
     * 最短路径
     *
     * **/
    void djskl(MyGraph G,const int v1);
    void flyd(MyGraph G,const int v1);
private:
    /**
     * 邻接矩阵
     *
     * **/
    int vertexNum;
    int arcNum;
    int vertex[maxsize+1];
    int arc[maxsize+1][maxsize+1];
    /**
    *
    * 邻接表
    *
    * **/
    link table[maxsize+1];

    /**
     * 最短路径
     * **/
    int dist[maxsize+1];//存放从源点到各个顶点的最短路径
    int path[maxsize+1];//存放在最短路径上该顶点的前一顶点号
    int s[maxsize+1];   //归并后的顶点集合

    int helperpath[maxsize+1][maxsize+1];
    int helpera[maxsize+1][maxsize+1];
};


