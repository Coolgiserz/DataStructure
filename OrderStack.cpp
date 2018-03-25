#include<iostream>
using namespace std;


"""
顺序栈的实现




"""
// class stack{
//     public:
//         int data;
// };
const int maxsize = 100;
class OrderStack{
    public:
        int top;
        int arr[maxsize];
        void initStack(OrderStack &s);
        void push(OrderStack &s,int x);
        void pop(OrderStack &s);
        void display(OrderStack &s);
        int getTop(OrderStack &s);

};

void OrderStack::initStack(OrderStack &s){
        s.top=0;
        arr[s.top]=0;

}

void OrderStack::push(OrderStack &s,int x){
        if(s.top==maxsize-1){
            throw("overflow!!");
            return;
        }
        s.top++;
        s.arr[s.top]=x;
        
}

void OrderStack::pop(OrderStack &s){
        if(s.top==0){
            throw("underflow!!!");
        }
        s.top--;
}

void OrderStack::display(OrderStack &s){
        if(s.top==0){
            cout<<"NULL!!!!";
        }
        while(s.top!=0){
            cout<<s.arr[s.top]<<endl;
            s.top--;
        }
}

int getTop(OrderStack &s){
    return s.arr[s.top];
}

int main(){
    OrderStack *s = new OrderStack();
    s->initStack(*s);
    int x;
    while(cin>>x&&x!=0){
        s->push(*s,x);
    }
    // cout<<s->arr[s->top];
    s->display(*s);

}