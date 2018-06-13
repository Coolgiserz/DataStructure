//
// Created by zhuge on 2018/6/6.
//


#include <iostream>
#include "MySort.cpp"
#include "time.h"
#include "random"
//const int maxsize=15;

//void main_api(MySort sort,int R[]);
void main_api(MySort *sort,int *R){
    clock_t start;
    clock_t end;
    cout<<"原数组:"<<endl;
    sort->displayarray(R,maxsize);
    cout<<"选择(输入0结束程序)"<<endl;
    cout<<1<<".直接插入"<<endl;
    cout<<2<<".二分排序"<<endl;
    cout<<3<<".希尔排序"<<endl;
    cout<<4<<".冒泡排序"<<endl;
    cout<<5<<".选择排序"<<endl;
    cout<<6<<".快速排序"<<endl;
    cout<<7<<".归并排序"<<endl;
    cout<<8<<".原数组"<<endl;
    int choose;
    cin>>choose;


        switch(choose){
            case 1:
                 start=clock();
                 sort->insertsort(R,maxsize);
                 end=clock();
                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;

//                main_api(sort,R);
                break;

            case 2:

                cout<<"二分排序以后"<<endl;
                start=clock();

                 sort->binarysort(R,maxsize);
                end=clock();

                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;

//                main_api(sort,R);
                break;
            case 3:
                cout<<"希尔排序以后"<<endl;
                start=clock();

                sort->shellsort(R,maxsize);
                end=clock();


                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;
                break;
            case 4:
                cout<<"冒泡排序以后"<<endl;
                start=clock();

                sort->bubblesort(R,maxsize);
                end=clock();
                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;

                break;
            case 5:
                cout<<"选择排序以后"<<endl;
                start=clock();

                sort->selectsort(R,maxsize);
                end=clock();
                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;

                break;
            case 6:
                cout<<"快速排序以后"<<endl;
                start=clock();

                sort->quick(R,0,maxsize-1);
                end=clock();
                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;

                break;
            case 7:
                cout<<"归并排序以后"<<endl;
                start=clock();

                sort->mergesort(R,maxsize);
                end=clock();
                sort->displayarray(R,maxsize);
                cout<<"程序运行时间:"<<(end-start)/CLOCKS_PER_SEC<<endl;

                break;

            case 8:
                cout<<"原数组"<<endl;
                sort->displayarray(R,maxsize);
                break;

        }



}
int main(){
//    int R[maxsize]={13,24,53,34,45,64,23,54,20,69,64,24,63,33,35};
    int R[maxsize];
    for(int j=0;j<maxsize;j++){
        R[j]=j;
    }
    for(int j=maxsize-1;j>=1;--j){
        swap(R[j],R[rand()%j]);
    }
//    for(int j=0;j<maxsize;j++){
//        LARGE_INTEGER seed;
//        QueryPerformanceFrequency(&seed);
//        QueryPerformanceCounter(&seed);
//        srand(seed.QuadPart);
//        R[j]=rand();
//    }
    int i;
//    for(i=0;i<maxsize;i++){
//        cout<<R[i]<<" ";
//    }
//    cout<<endl;
    MySort *sort = new MySort;
    main_api(sort,R);
//    cout<<"原数组"<<endl;
//    sort->displayarray(R,maxsize);
    /*************直接插入排序******************/
//    cout<<"直接插入排序以后"<<endl;
//    clock_t start=clock();
////    sort->insertsort(R,maxsize);
//    clock_t end=clock();
//    cout<<"程序运行时间:"<<end-start<<endl;
//    sort->displayarray(R,maxsize);
//    /**************二分排序*****************/
//
//    cout<<"二分排序以后"<<endl;
//    start=clock();
//
////    sort->binarysort(R,maxsize);
//    end=clock();
//    cout<<"程序运行时间:"<<end-start<<endl;
//
//    sort->displayarray(R,maxsize);
//    /************希尔排序*******************/
//
//    cout<<"希尔排序以后"<<endl;
//    start=clock();
//
//    sort->shellsort(R,maxsize);
//    end=clock();
//    cout<<"程序运行时间:"<<end-start<<endl;
//
//    sort->displayarray(R,maxsize);
//    /*************冒泡排序******************/
//
//    cout<<"冒泡排序以后"<<endl;
//    start=clock();
////    sort->bubblesort(R,maxsize);
//
//    end=clock();
//    cout<<"程序运行时间:"<<end-start<<endl;
//    sort->displayarray(R,maxsize);
//
//    cout<<"选择排序以后"<<endl;
//    start=clock();
////    sort->selectsort(R,maxsize);
//    end=clock();
//
//    cout<<"程序运行时间:"<<end-start<<endl;
//    sort->displayarray(R,maxsize);
//
//    cout<<"快速排序以后"<<endl;
//    start=clock();
////    sort->quick(R,0,maxsize-1);
//    end=clock();
//    cout<<"程序运行时间:"<<end-start<<endl;
//    sort->displayarray(R,maxsize);


}