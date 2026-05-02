//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "find.h"


//二分查找
void two_find(int arrw[], int n, int fn) {//fn是find number
    int min = 0;
    int high = n - 1;
    int countn = 0;
    while (min <= high && countn<1000) {
        int mid = min + (high - min) / 2;  //动态且防止了溢出风险
        countn += 1;
        printf("此时，上下限为%d和%d,中间数是%d\n", high, min, mid);
        if (arrw[mid] == fn) {
            printf("找到了，该数在第%d个位置", mid + 1);
            break;
        }
        else if (fn > arrw[mid]) {
            printf("比中间数大\n");
            min = mid + 1;
        }
        else {
            printf("比中间数小\n");
            high = mid - 1;
        }
    }
    if (countn >= 1000) {
        printf("未找到且疑似死循环\n");
    }
    if (min > high) {
        printf("未找到\n");
    }

}