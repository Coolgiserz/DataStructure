//
// Created by zhuge on 2018/6/22.
//

#include "MyLink.cpp"
#include <iostream>

using namespace std;
 int main(){
     MyLink *link;
//     link = link->hcreateLink(10);
//          link = link->hcreateLink2(10);
     link = link->rcreateLink2(10);
    link->printLink(link);
//     for(int i=1;i<=11;i++){
//         cout<<link->Find(link,i)->data;
//
//     }





 }