/**
 * 通过栈和队列判断字符串是否为回文
 * 通过单链表判断回文
 * 
*/

#include "SingleLink.h"
#include<iostream>
using namespace std;
int main(){
string p = "Iloveyou";
// string *sr = &p;

// cout<<sr[1];
// cout<<sr[5];
SingleLink *s = new SingleLink();
// SingleLink *head = s->CreateSingleLink(p);
SingleLink *head = s->CreateSingleLink();
int n=0;
string shunxu,daoxu;
// cout<<"Enter n=";
n=head->length;
// cin>>n;
for(int i=1;i<=n;i++){
    // cout<<s->Locate(head,i);
    shunxu+=s->Locate(head,i);
}
for(int i=n;i>=1;i--){
    // cout<<s->Locate(head,i);
    daoxu+=s->Locate(head,i);
}

cout<<shunxu<<endl;
cout<<daoxu<<endl;
if(shunxu==daoxu){
    cout<<"回文没错了";
}else{
    cout<<"不是回文";
}
// s->Display(head);
// cout<<s->data<<endl;
// cout<<s->length<<endl;
// cout<<s->head->data;
// s->Insert(*s,'b',1);
// cout<<s->Locate(*s,1);

}