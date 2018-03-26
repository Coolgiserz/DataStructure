/**
 * 单链表
 * 
 * 
 * **/

#include<iostream>
#include<string>
using namespace std;
// class Link{
// public:
//     string *data;
//     Link *next;
// };
class SingleLink{
public:
    string data;
    SingleLink *next;
    // SingleLink *rear;
    int length;
    // void Initialize(SingleLink &li);
    SingleLink(){
        // head = new SingleLink;
        // head->next=NULL;
        // rear = new SingleLink;
        // rear->next = NULL;
        length = 0;
    }
    ~SingleLink(){
        // delete head;
    }
    SingleLink *CreateSingleLink( string *str);
    SingleLink *CreateSingleLink();
    void Insert(string x, int i);
    string Locate(SingleLink *p, int i);
    void Delete( int i);
    void Display(SingleLink *p);
};

// SingleLink *SingleLink::CreateSingleLink( string *str){
//     // if(n<=0){
//     //     throw("are you kidding me?");
//     // }
//     // SingleLink *p = head;
//     // int count = 0;
//     SingleLink *p,*rear,*s;
//     p=NULL;
//     int n=sizeof(str);
//     for(int i=0;i<n;i++){
//         s = new SingleLink;
//         // string *x =  str[i];
//         // strcpy(x,str.substr(i,1));
//         strcpy((*s).data,(*str).substr(i,1));
//         // s->data=x;
//         if(p==NULL){
//             p=s;
//         }else{
//             rear->next=s;
//         }
    
//         rear=s;
      
//     }
//     rear->next=NULL;
//     return p;
//     // while(count < n){
//     //     SingleLink *p = new SingleLink;
//     //     p->data = &str[count];
//     //     rear->next->next=p;
//     //     p->next = NULL;
//     //     rear->next=p;
//     //     count++;
//     // }

// }

SingleLink *SingleLink::CreateSingleLink(){
    // if(n<=0){
    //     throw("are you kidding me?");
    // }
    // SingleLink *p = head;
    // int count = 0;
    SingleLink *p,*rear,*s;
    p=new SingleLink();
     p->next=NULL;
    char ch;
    int count=0;
    while(cin>>ch&&ch!='0'){
        s = new SingleLink();
        count++;
        s->data=ch;
           if(p->next==NULL){
            p->next=s;
        }else{
        //    p->next->next=s;
            rear->next=s;
           
        }
        rear=s;
    }   
    
    rear->next=NULL;
    p->length=count;
    return p;

}

void SingleLink::Insert( string x, int i){
    // length++;
    // if(i<=0||i>length){
    //     cout<<"插入位置错误！";
    //     return;
    // }
    
    // SingleLink *p = head;
    // int count = 0;
    // while(count<i-1){
    //     p = p->next;
    //     count++;
    // }
    // SingleLink *n = new SingleLink;
    // n->data=&x;
    // n->next=p->next->next;
    // p->next = n;
    
    // cout<<n->data;
    // delete n;
    // strcpy(n->data,x);
    // n->data=x;  此种做法会报错


}

string SingleLink::Locate(SingleLink *p, int i){
    //   if(i<=0||i>length){
    //     cout<<"查询位置错误！";
    //     exit(1);
    // }
    int count=0;
    SingleLink *now = p;
    while(p->next!=NULL&&count<i){
        p=p->next;
        count++;
    }
    return p->data;
}

void SingleLink::Display(SingleLink *p){
    if(p->next==NULL){
        cout<<"NULL";
    }
    while(p->next!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<p->data;
    // delete p;
}