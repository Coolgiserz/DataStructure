//
// Created by zhuge on 2018/6/22.
//

#ifndef DATASTRUCT_MYLINK_H
#define DATASTRUCT_MYLINK_H

typedef int elemtype;

//单链表ADT
class mynode{
public:
    elemtype data;
    mynode *next;

};
class MyLink {
public:
    elemtype data;
    MyLink *next;
    int length();
    bool isEmpty(MyLink *L);
    void setNull();
    int locate(elemtype x);
    void dele(int i);
    void insert(elemtype x,int i);
    elemtype prior(elemtype x);
    elemtype succ(elemtype x);
    void printLink(MyLink *L);
    MyLink *Find(MyLink *head,int i);
    MyLink *hcreateLink(int n);
    MyLink *hcreateLink2(int n);

    MyLink *rcreateLink(int n);
    MyLink *rcreateLink2(int n);

};


#endif //DATASTRUCT_MYLINK_H
