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
     link->insert(link,5,2);
     link->printLink(link);
     cout<<link->isEmpty(link);
//     cout<<link->Find(link,5)->data;

     link->dele(link,4);
     link->swaplink(link);
     link->printLink(link);

//     link->setNull(link);
//     cout<<link->isEmpty(link);
//     cout<<link->locate(link,5)->data;
//     for(int i=1;i<=11;i++){
//         cout<<link->Find(link,i)->data;
//
//     }





 }