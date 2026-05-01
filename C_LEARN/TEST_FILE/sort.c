//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "sort.h"
//考研考察主要有插入排序、冒泡排序、希尔排序、快速排序、简单选择排序、堆排序等

//冒泡排序
void Maopao(int arrw[], int n) {
    printf("正在调用冒泡排序\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arrw[j] > arrw[j + 1]) {
                int a = arrw[j];
                arrw[j] = arrw[j + 1];
                arrw[j + 1] = a;
            }
        }
    }
    printf("冒泡排序调用完成\n");
}

//希尔排序