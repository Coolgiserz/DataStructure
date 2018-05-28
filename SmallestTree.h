//
// Created by zhuge on 2018/5/27.
//

#ifndef DATASTRUCT_SMALLESTTREE_H
#define DATASTRUCT_SMALLESTTREE_H

#endif //DATASTRUCT_SMALLESTTREE_H
const int n=9;
const int e=16;
class edgeset{
public:int fromvex;
    int endvex;
    int weight;
};

class tree{
public:
    int s[n+1][n+1];
    edgeset ct[n+1];
    void prim(tree &t);
};

