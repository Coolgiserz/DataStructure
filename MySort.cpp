//
// Created by zhuge on 2018/6/6.
//

#include "MySort.h"
using namespace std;
const int maxsize=100000;
int A[maxsize];

/**
 *
 * 插入排序
 *
 *
 * */
void MySort::insertsort(int *R, int n) {
    for(int i=1;i<n;i++){
        int tmp = R[i];
        int j = i-1;
        while(j>=0&&tmp<R[j]){
            R[j+1]=R[j];j--;
        }
        R[j+1]=tmp;


    }


}
/**
 *
 * 二分插入排序
 *
 *
 * */
void MySort::binarysort(int *R, int n) {
//    for(int i=1;i<n;i++){
//        int left=0,right=i-1;int tmp=R[i];
//        while (left<=right){
//            int middle = (left+right)/2;
//            if(tmp<R[middle]){
//                right = middle-1;
//            }else{
//                left = middle+1;
//            }
//
//        }
//        for(int j=i-1;j>=left;j--){
//            R[j+1]=R[j];
//            R[left]=tmp;
//        }
//
//    }

    int i,j;
    int low,high,mid;int tmp;
    for(i=1;i<n;i++){
        tmp=R[i];
        low=0;high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(tmp<R[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for(j=i-1;j>=low;j--){
            R[j+1]=R[j];
        }
        R[low]=tmp;

    }
}



/**
 *
 * 希尔排序
 *
 *
 * */
void MySort::shellsort(int *R, int n) {
    int j;
    for(int d=n/2;d>=1;d/=2){
        for(int i=d;i<n;i++){
            int tmp = R[i];
            for( j=i-d;j>=0;j-=d){
                if(tmp<R[j]){
                    R[j+d]=R[j];

                }else{
                    break;
                }

            }
            R[j+d]=tmp;

        }
    }

}



/**
 *
 * 选择排序
 *
 *
 * */

void MySort::selectsort(int *R, int n) {
    int i,j,m;int tmp;
    for(i=0;i<n-1;i++){
        m=i;
        for(j=i+1;j<n;j++){
            if(R[j]<R[m]){
                m=j;
            }
        }if(m!=i){
            tmp=R[m];
            R[m]=R[i];
            R[i]=tmp;
        }
    }

}

/**
 *
 * 冒泡排序排序
 *
 *
 * */

void MySort::bubblesort(int *R, int n) {
    int flag=1;
    for(int i=1;i<n;i++){
        flag=0;
        for(int j=n-1;j>=i;j--){
            if(R[j]<R[j-1]){
                int tmp=R[j];
                R[j]=R[j-1];
                R[j-1]=tmp;
                flag=1;
            }
            if(flag==0){
                continue;
            }
        }


    }

}

void MySort::quick(int *R, int left, int right) {
    int i=left,j=right;
    int tmp=R[i];
    while(i<j){
        while((R[j]>tmp)&&(j>i)){
            j=j-1;

        }
        if(j>i){
            R[i]=R[j];
            i++;
        }

        while((R[i]<=tmp)&&(j>i)){
                i++;


         }
        if(i<j){
            R[j]=R[i];
            j--;
        }

    }
    R[i]=tmp;
    if(left<i-1){
        quick(R,left,i-1);
    }
    if(i+1<right){
        quick(R,i+1,right);
    }

}

void MySort::displayarray(int *R, int n) {

    for(int i=0;i<n;i++){
        cout<<R[i]<<" ";
    }
    cout<<endl;
}

/**
 * 归并排序
 * */
void MySort::merge(int *R, int *A, int s, int m, int t) {
    int i,j,k;
    i=s;j=m+1;
    k=s;
    while((i<=m)&&j<=t){
        if(R[i]<=R[j]){
            A[k]=R[i];i++;k++;
        }
        else{
            A[k]=R[j];j++;k++;
        }

    }
    while(i<=m){
        A[k]=R[i];i++;k++;
    }
    while(j<=t){
        A[k]=R[j];j++;k++;
    }



}

void MySort::mergepass(int *R, int *A, int n, int c) {

    int i,j;
    i=0;
    while((i+2*c-1)<=n-1){
        merge(R,A,i,i+c-1,i+2*c-1);
        i += 2*c;
    }
    if(i+c-1<n){
        merge(R,A,i,i+c-1,n-1);
    }else{
        for(j=i;j<=n-1;j++){
            A[j]=R[j];
        }
    }
}

void MySort::mergesort(int *R, int n) {
    int c=1;
    while(c<n){
        mergepass(R,A,n,c);
        c*=2;
        mergepass(A,R,n,c);
        c*=2;
    }
}
//void MySort::mainapi() {
//    cout<<"选择";
//
//
//}