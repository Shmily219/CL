//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "sort.h"
//考研考察主要有插入排序、冒泡排序、希尔排序、快速排序、简单选择排序、堆排序等

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
void Sheele(int arr[], int n, int DG) { //DG是默认间距Defalt Gap
    printf("正在调用希尔排序\n");
    int countn = 0;
    if (DG == NULL)
        DG = 5;  //DG如果未传入则默认为5
    while (DG >= 1) {
        countn += 1;
        printf("正在进行第%d趟排序\n",countn);
        for (int i = 0; i < n / DG -1; i += DG) {
            if (arr[i] > arr[i + DG]) {
                int a = arr[i];
                arr[i] = arr[i + DG];
                arr[i + DG] = a;
                }
            }
        pirnt_arr(arr, 20);
        DG -= 1;
    }
    printf("排序好的数组为");
    print_arr(arr, n);
}