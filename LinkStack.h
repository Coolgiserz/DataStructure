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
    Stack(){
        top = new link;
    }
    void initStack(link *top);
    void push(link *top,int x);
    void pop(link *top);
    int  getTop(link *top);
    void showStack(link *top);
    bool empty(link *top);
    void MainApi(link *top);
};

void Stack::initStack(link *top) {
    // link *p=new link;
    // p->data=0;
    // top=p;
    // // top->next=NULL;
    top->next=NULL;
}

void Stack::showStack(link *top) {
    if(top->next==NULL){
        cout<<"栈如我心，空无一物";
        MainApi(top);
    }
    
    while(top->next!=NULL){
        
        cout<<top->data<<endl;
        top=top->next;
    }
     cout<<top->data<<endl;
}

int  Stack::getTop(link *top) {
    return top->data;

}

void Stack::pop(link *top) {
    if(top->next==top){
        cout<<"栈已经空了，不能这样操作了"<<endl;
        return;
    }
    // link *p=top;
    link *p=top->next;
    top->next=p->next;
    delete p;
}

/*
进栈运算，先开辟一个新的结点，他将要作为栈顶元素，于是top所指的地址要给它
保管。之后top再指向它
*/
void Stack::push(link *top, int x) {
    link *p=new link;
    p->data=x;
    p->next=top->next;
    top->next=p;
}

bool Stack::empty(link *top) {
    if(top->next==NULL){
        cout<<"栈空";
        return true;
    }else{
        cout<<"栈未空";
        return false;
    }

}

void Stack::MainApi(link *top){
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
            while (cin>>x && x!=0){
                     push(top,x);
                    //  cout<<top->next->data;
                     
            }
           cout<<"OK!";

            break;
        }
        case(2):{
            pop(top);
            break;
        }
        case(3):{
            int res = getTop(top);
            break;
        }
        case(4):{
            bool res = empty(top);
            break;
        }
        case(5):{
            showStack(top);
            break;
        }
        case(6):{
            exit(1);
            break;
        }
        // default:cout<<"操作完成！";
       
    }
     cout<<"操作完成！";
     MainApi(top);

}