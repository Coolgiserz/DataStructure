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
    MyLink *tmp = head;
    while(j<i && tmp!=NULL){
        j++;
        tmp = tmp->next;
    }
    return tmp;


}
//针对带头结点的单链表，输出
void MyLink::printLink(MyLink *L) {
    MyLink *p = L->next;
    while(p->next!=NULL){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<p->data;
    cout<<endl;





}