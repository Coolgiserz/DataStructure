//
// Created by 朱国伟 on 2018/3/24.
//

#ifndef DATASTRUCT_HOSTIPAL_H
#define DATASTRUCT_HOSTIPAL_H

#include <iostream>
#include <stdlib.h>
using namespace std;
class link{
public:
    int num;
    link *next;
};

class Hostipal {
public:
    link *front,*rear;

    void initHostipal(Hostipal &s);
    static void MainApi(Hostipal &hh){
            int choice=0;
            cout<<"接下来您要作何操作？键入[1-4]"<<endl;
            cout<<1<<". 进队"<<endl;
            cout<<2<<". 查询"<<endl;
            cout<<3<<". 删除"<<endl;
            cout<<4<<". 下班"<<endl;

            cout<<"你的选择:";
            cin>>choice;
            if(choice==1){

                int ch;

                cout<<1<<". 输入"<<endl;
                cout<<2<<". 返回"<<endl;
                cout<<"选择:";
                cin>>ch;
                if(ch==1){
                    int ill_num;
                    cout<<"请输入病历号：";
                    cin>>ill_num;
                    hh.EnterQueue(hh,ill_num);
                }else{
                    hh.MainApi(hh);
                }


            }else if(choice==2){
                hh.CheckQueue(hh);

            }
            else if(choice==3){
                hh.DeleQueue(hh);
            }
            else if(choice==4){
                hh.GetOffWork();
            }
            else if(choice==4){
                hh.MainApi(hh);
            }else{
                cout<<"请按照要求操作！！！"<<endl;
                MainApi(hh);
            }
    }
    void EnterQueue(Hostipal &s,int ill);
    void DeleQueue(Hostipal &s);
    void CheckQueue(Hostipal &s);
    void GetOffWork();

};
void Hostipal::initHostipal(Hostipal &s) {
    link *p = new link;
    p->next=NULL;
    s.front=p;
    s.rear=p;
};

void Hostipal::EnterQueue(Hostipal &s,int ill) {
    link *p=new link;
    p->num=ill;
    p->next=s.rear->next;
    s.rear->next=p;
    s.rear=p;
    cout<<"成功！"<<endl;
    MainApi(s);
}

void Hostipal::CheckQueue(Hostipal &s) {
    if(s.front==s.rear){
        std::cout<<"当前无人排队！";
        MainApi(s);
        return;
    }
    link *now=s.front;
    int i = 0;
    while(now->next!=NULL){
        i++;
        now=now->next;
        std::cout<<i<<" :"<<now->num<<std::endl;
        if(now==s.rear->next){
            break;
        }
    }
    MainApi(s);
;}
void Hostipal::DeleQueue(Hostipal &s) {
    if(s.front==s.rear){
        std::cout<<"当前队列已空，您不能这么操作哦！"<<std::endl;
        return;
    }else{
        link *p=s.front;
        s.front=p->next;
        std::cout<<"操作成功！";
        delete(p);
    }
    MainApi(s);
}
void Hostipal::GetOffWork() {
    cout<<"ByeBye~";
    exit(1);
}

//static void Hostipal::MainApi(Hostipal &hh) {
//    int choice=0;
//    cout<<"接下来您要作何操作？键入[1-4]"<<endl;
//    cout<<1<<". 进队"<<endl;
//    cout<<2<<". 查询"<<endl;
//    cout<<3<<". 删除"<<endl;
//    cout<<4<<". 下班"<<endl;
//    cout<<"你的选择:";
//    cin>>choice;
//    if(choice==1){
//        int ill_num;
//        cout<<"请输入病历号：";
//        cin>>ill_num;
//        hh.EnterQueue(hh,ill_num);
//
//    }else if(choice==2){
//        hh.CheckQueue(hh);
//
//    }
//    else if(choice==3){
//        hh.DeleQueue(hh);
//    }
//    else if(choice==4){
//        hh.GetOffWork();
//    }else{
//        cout<<"请按照要求操作！！！"<<endl;
//        MainApi(hh);
//    }
//}
//void Hostipal::MainApi() {
//    int choice=0;
//    cout<<"接下来您要作何操作？键入[1-4]"<<endl;
//    cout<<1<<". 进队";
//    cout<<2<<". 查询";
//    cout<<3<<". 删除";
//    cout<<4<<". 下班";
//    if(choice==1){
//
//    }
//
//}
#endif //DATASTRUCT_HOSTIPAL_H
