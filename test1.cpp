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

int main(){
//    int sum=1;
//    test(sum);
    Stack *s = new Stack;
    s->initStack(s->top);
    s->MainApi(s->top);
}