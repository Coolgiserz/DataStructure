//
// Created by 朱国伟 on 2018/3/20.
//
#include <iostream>
#include "StringMatch.h"
int main(){
    StringMatch *test = new StringMatch();
//    std::cout<<test->BFTest("okgkasssad","kas",0);
    string str1;
    string str2;
    std::cin>>str1;
    std::cin>>str2;
    cout<<test->BF1(str1,str2);
}