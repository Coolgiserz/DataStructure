//
// Created by 朱国伟 on 2018/3/24.
//

#include "Hostipal.h"
#include <iostream>
//void MainApi(Hostipal &hh) {
//    int choice=0;
//    cout<<"接下来您要作何操作？键入[1-4]"<<endl;
//    cout<<1<<". 进队"<<endl;
//    cout<<2<<". 查询"<<endl;
//    cout<<3<<". 删除"<<endl;
//    cout<<4<<". 下班"<<endl;
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
int main(){
        Hostipal *hh = new Hostipal;
        std::cout<<"仁医济世，天下无双"<<std::endl;
       hh->initHostipal(*hh);
        hh->MainApi(*hh);
};

