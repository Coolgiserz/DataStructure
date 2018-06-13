//
// Created by zhuge on 2018/6/6.
//

#ifndef DATASTRUCT_MYSORT_H
#define DATASTRUCT_MYSORT_H


class MySort {
public:
    void insertsort(int R[],int n);
    void binarysort(int R[],int n);
    void shellsort(int R[],int n);
    void bubblesort(int R[],int n);
    void quick(int R[],int left,int right);
    void selectsort(int R[],int n);
    void displayarray(int R[],int n);
    void merge(int R[],int A[],int s,int m,int t);
    void mergepass(int R[],int A[],int n,int e);
    void mergesort(int R[],int n);
//    void te
    void mainapi();

};


#endif //DATASTRUCT_MYSORT_H
