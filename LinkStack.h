//
// Created by 朱国伟 on 2018/3/24.
//
#define DATASTRUCT_HOSTIPAL_H

#include <iostream>
#include <stdlib.h>
using namespace std;
class link{
public:
    int data;
    link *next;
};

class Stack{
public:
    link *top;
    void initStack(Stack &s);
    void push(Stack &s,int x);
    void pop(Stack &s);
    int  getTop(Stack &s);
    void showStack(Stack &s);
    bool empty(Stack &s);
    void MainApi(Stack &s);
};

void Stack::initStack(Stack &s) {
    // link *p=new link;
    // p->data=0;
    // s.top=p;
    // // s.top->next=NULL;
    s.top=new link;
     s.top->next=NULL;
}

void Stack::showStack(Stack &s) {
    if(s.top->next==NULL){
        cout<<"栈如我心，空无一物";
        MainApi(s);
    }
    
    while(s.top->next!=NULL){
        
        cout<<s.top->data<<endl;
        s.top=s.top->next;
    }
}

int  Stack::getTop(Stack &s) {
    return s.top->data;

}

void Stack::pop(Stack &s) {
    if(s.top->next==s.top){
        cout<<"栈已经空了，不能这样操作了"<<endl;
        return;
    }
    // link *p=s.top;
    link *p=s.top->next;
    s.top->next=p->next;
    delete p;
}

/*
进栈运算，先开辟一个新的结点，他将要作为栈顶元素，于是top所指的地址要给它
保管。之后top再指向它
*/
void Stack::push(Stack &s, int x) {
    link *p=new link;
    p->data=x;
    p->next=s.top->next;
    s.top->next=p;
}

bool Stack::empty(Stack &s) {
    if(s.top->next==NULL){
        cout<<"栈空";
        return true;
    }else{
        cout<<"栈未空";
        return false;
    }

}

void Stack::MainApi(Stack &s){
    cout<<"你接下来要进行什么操作？？？键入[1-5]"<<endl;
    cout<<"1. 进栈"<<endl;
    cout<<"2. 出栈"<<endl;
    cout<<"3. 取栈顶"<<endl;
    cout<<"4. 栈是否为空"<<endl;
    cout<<"5. 查看栈"<<endl;
    cout<<"6. 再见"<<endl;
    int choice = 0;
    cout<<"你的选择:";
    cin>>choice;

    switch(choice){
        case(1):{
            int x;
            cout<<"Enter 0 to exit"<<endl;
            cin>>x;
            while (x!=0){
                     push(s,x);
                     cin>>x;
            }
           cout<<"OK!";

            break;
        }
        case(2):{
            pop(s);
            break;
        }
        case(3):{
            int res = getTop(s);
            break;
        }
        case(4):{
            bool res = empty(s);
            break;
        }
        case(5):{
            showStack(s);
            break;
        }
        case(6):{
            exit(1);
            break;
        }
        // default:cout<<"操作完成！";
       
    }
     cout<<"操作完成！";
     MainApi(s);

}