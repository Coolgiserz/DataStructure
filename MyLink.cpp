//
// Created by zhuge on 2018/6/22.
//

#include "MyLink.h"
#include <iostream>
using namespace std;
//头插法建立单链表,不带头结点;头结点的结构与表结点结构一样，只是数据域为空，或用于存放表长等附加信息
MyLink* MyLink::hcreateLink(int n) {

    MyLink *p,*tmp;
    p = NULL;
    int i;
    for(i=0;i<n;i++){
        tmp = new MyLink;
        cin>>tmp->data;
        tmp->next=p;
        p = tmp;
    }

    return p;
}
//带头结点的头插法建立单链表
MyLink* MyLink::hcreateLink2(int n) {

    MyLink *p,*tmp;
    p = new MyLink;
    p->next = NULL;
    int i;

    for(i=0;i<n;i++){
        tmp = new MyLink;
        cin>>tmp->data;
        tmp->next = p->next;
        p->next = tmp;

    }
    return p;

}
//尾插法建立单链表,不带头结点
MyLink* MyLink::rcreateLink(int n) {
    MyLink *p,*tmp,*r;
    int i;
    p = NULL;
    for(i=1;i<=n;i++){
        tmp = new MyLink;
        cin>>tmp->data;
        if( p == NULL){
            p = tmp;
        }else{
            r->next = tmp;
        }
        r = tmp;



    }
    r->next = NULL;
    return p;


}

MyLink* MyLink::rcreateLink2(int n) {
    MyLink *p,*tmp,*r;
    int i;
    p =r = new MyLink;
    p->next = NULL;
    for(i=1;i<=n;i++){
        tmp = new MyLink;
        cin>>tmp->data;
        r->next = tmp;
        r = tmp;
    }
    r->next = NULL;
    return p;
}
MyLink* MyLink::Find(MyLink *head, int i) {

    int j = 1;
    MyLink *tmp = head;//如果要针对带头结点的链表，则将head改为head->next
    while(j<i && tmp!=NULL){
        j++;
        tmp = tmp->next;
    }
    return tmp;


}
//返回链表L中元素数据为x的结点

MyLink* MyLink::locate(MyLink *L, elemtype x) {
    MyLink *tmp;
    tmp = L;
    while(tmp!=NULL&&tmp->data!=x){
        tmp = tmp->next;
    }
    return tmp;
}
//返回链表L中元素为x的结点的次序
//int MyLink::locate(MyLink *L, elemtype x) {
//    MyLink *tmp = L;
//    int j=0;
//    while(tmp!=NULL&&tmp->data!=x){
//        j++;
//        tmp = tmp->next;
//    }
//    return j;
//
//}

//在链表L中的元素为y的结点后插入元素为x的结点:先定位到元素为y的结点，而后再做调整
void MyLink::insert(MyLink *L, elemtype x, elemtype y) {
    MyLink *p = locate(L,y);
    if(p==NULL){
        cerr<<"cannot match the y!";
        return;
    }else{
        MyLink *tmp = new MyLink;
        tmp->data = x;
        tmp->next = p->next;
        p->next = tmp;
    }

}

void MyLink::setNull(MyLink *L) {

    MyLink *tmp = L->next;MyLink *t;
    L->next = NULL;
    while(tmp!=NULL){
        t = tmp->next;
        delete tmp;
        tmp = t;
    }

}
bool MyLink::isEmpty(MyLink *L) {

    return L->next==NULL;

}

//void MyLink::insert(MyLink *L,elemtype x, int i) {
//    MyLink *tmp = Find(L,i);
//    if(tmp==NULL){
//        cout<<"不存在"<<i<<"位元素";
//        return;
//    }else{
//        MyLink *p = new MyLink;
//        p->data = x;
//        p->next = tmp->next;
//        tmp->next = p;
//    }
//
//
//}
//删除链表第i个结点
void MyLink::dele(MyLink *L,int i) {
    MyLink *tmp = Find(L,i-1);
    if(tmp==NULL){
        cout<<"不存在"<<i<<"位元素";
        return;
    }else{
        MyLink *p =  tmp->next;
        tmp->next = p->next;
        delete p;
    }


}
//针对带头结点的单链表，输出
void MyLink::printLink(MyLink *L) {
    MyLink *p = L->next;//如果将L->next改成L，则成为针对不带头结点的单链表输出例程
    while(p->next!=NULL){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<p->data;
    cout<<endl;

}
