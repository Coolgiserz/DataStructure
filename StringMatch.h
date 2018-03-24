//
// Created by 朱国伟 on 2018/3/20.
//
#include <iostream>
using namespace std;
#ifndef DATASTRUCT_STRINGMATCH_H
#define DATASTRUCT_STRINGMATCH_H


class StringMatch {
public:

    int BFTest(const string &str,const string &pattern,int index);
    int BF1(const string &str,const string &pattern);
    void KMPTest();
};
/*
 * BF算法：暴力搜索字符串
 *
 * */
int StringMatch::BF1(const string &str, const string &pattern) {
    int i=0;
    int j=0;
    int num=0;
    while(i<str.size()){
        if(str[i]==pattern[j]){
            i++;
            j++;
            num++;
        }else{
            num=0;
            j=0;
            i=i-num+1;
        }
        if(num==pattern.size()){
            cout<<"Success!";
            return i-num;
        }
    }



    return 0;
}
int StringMatch::BFTest(const string &str, const string &pattern,int index) {
    if(str.size()<pattern.size()){
//        throw('overflow!');
        cout<<"溢出";
        return 0;
    }
    int i=0;//指示str的索引
    int j=0;//指示pattern的索引
    int p=0;
    while(i<=str.size()&&j<=pattern.size()){
//
        for(;i<str.size();i++){
            if(str[i]==pattern[j]){
                j++;
                p++;
            }else{
                i=i-j+1;
                j=0;
                p=0;
            }
        }
        if(p==j){
            return i;
        }

    }

    return i-j;


}

#endif //DATASTRUCT_STRINGMATCH_H
