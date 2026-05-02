//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "sort.h"
//考研考察主要有插入排序、冒泡排序、希尔排序、快速排序、简单选择排序、堆排序等

//插入排序
void Insert(int arr[],int n) {
    for (int i = 1; i < n; i++) {
        int a = arr[i]; //a为待排序的数,
        while (arr[i-1]>a) {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[i] = a;
        print_arr(arr, n);
    }
}



//冒泡排序
void Maopao(int arrw[], int n) {
    printf("正在调用冒泡排序\n");
    for (int i = 0; i < n - 1; i++) {
        printf("开始第%d趟排序\n",i+1);
        for (int j = 0; j < n - 1 - i; j++) {
            if (arrw[j] > arrw[j + 1]) {
                int a = arrw[j];
                arrw[j] = arrw[j + 1];
                arrw[j + 1] = a;
            }
            print_arr(arrw, n);
        }
    }
    printf("冒泡排序调用完成\n");
}

//希尔排序：从局部有序趋向与全局有序
void Shell(int arr[], int n) { //DG是默认间距Defalt Gap
    printf("正在调用希尔排序\n");
    int countn = 0;
    for(int gap = n/2;gap>=1;gap/=2){
        for (int i = gap; i < n; i++) {  //i是每个子数组的下标，其所有的下标应该是i+n*gap
            int a = arr[i];
            int j = i;
            while (j >= gap && a < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j-=gap;
            }
            print_arr(arr,n);
            arr[j] = a;
        }
        printf("第%d趟排序后的数组为\n",++countn);
        print_arr(arr, n);
    }
    //printf("希尔排序好的数组为");
    //print_arr(arr, n);
}

void Qsert(int arr[],int L,int R) {
    if (L >= R)
        return;
    printf("正在使用快速排序\n");
    int a = arr[L];
    int low = L, high = R;
    while (low < high) {
        while (low < high && a <= arr[high]) high--;
        arr[low] = arr[high];
        while (low < high && a >= arr[low]) low++;
        arr[high] = arr[low];
    }
    arr[low] = a;
    print_arr(arr, 25);
    Qsert(arr,L,low-1);
    Qsert(arr,low+1,R);
}