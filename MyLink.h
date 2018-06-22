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
    void setNull(MyLink *L);
    MyLink* locate(MyLink *L,elemtype x);
//    int locate(MyLink *L,elemtype x);
    void dele(MyLink *L,int i);
//    void insert(MyLink *L,elemtype x,int i);
    void insert(MyLink *L,elemtype x,elemtype y);
    elemtype prior(elemtype x);
    elemtype succ(elemtype x);
    void printLink(MyLink *L);
    MyLink *Find(MyLink *head,int i);
    MyLink *hcreateLink(int n);
    MyLink *hcreateLink2(int n);

    MyLink *rcreateLink(int n);
    MyLink *rcreateLink2(int n);

    void swaplink(MyLink *L);

};


#endif //DATASTRUCT_MYLINK_H
