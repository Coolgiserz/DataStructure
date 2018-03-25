#include <iostream>
#include "LinkStack.h"
using namespace std;
void test(int &sum){
    int x;
    cin>>x;
    if(x==0){
        sum=0;
    }else{
        test(sum);
        sum=sum+x;
    }
    cout<<sum<<endl;
}
//将test函数的递归实现以非递归的方式实现
void test_plus(){
    int x;
    Stack *s = new Stack;
    while(cin>>x && x!=0){
        s->push(s->top,x);
    }
    int sum=0;
    while(s->empty(s->top)!=true){
        int now = s->getTop(s->top);
        cout<<sum+now;
    }
    
}

void test_link_stack(){
    Stack *s = new Stack;
    s->initStack(s->top);
    s->MainApi(s->top);
}
int main(){

   test_link_stack();
    // int sum=2;
    // test(sum);
}