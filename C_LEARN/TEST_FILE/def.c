//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "def.h"
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//判断一个数是否是素数
int judge_sushu(int a) {
    if (a < 2) {
        return 0;
    }
    else if (a == 2) {
        return 1;
    }
    else {
        for (int i = 2; i <= a / 2; i++) {
            if (a % i == 0) {
                return 0;
            }
            if (i >= a / 2) {
                return 1;
            }
        }
    }
};

//交换两数的值
void def_Swap(int* a,int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

//计算阶乘
int Count_jiecheng(int i)
{
    //int m = 1;
    //for (int j = i; j > 0;j--) {
    //    m *= j;
    //}
    //return m;

    if (i == 0)
        return 1;
    return i * Count_jiecheng(i - 1);
};

//计算斐波那契的第n项
int FBNQDG(int i) {
    if (i == 1 || i == 2) {
        return 1;
    }
    return FBNQDG(i - 1) + FBNQDG(i - 2);
};
int FBNQDD(int i) {
    if (i <= 0) {
        return -1;
    }
    else if (i < 3) {
        return 1;
    }
    int a = 1;
    int b = 1;
    int c = 0;
    while (i >= 3) {
        c = a + b;
        a = b;
        b = c;
        i--;
    }
    return c;
}



//生成随机数
int Create_random(int low,int hight) {
    //srand((unsigned int)time(NULL));  //设置时间随机种子
    //int a = rand() % (hight - low + 1) + low;
    return rand() % (hight - low + 1) + low;
}

//判断一年是否是闰年
int judge_runnian(int a) {
    if ((a%400 == 0)||(a%100 != 0 && a%4 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

//随机创建一个数组，使用了动态数组，用完后记得free
//int* create_random_arr(int size, int low, int high) {
//    if (size <= 0 || high < low) return NULL;//判断size和上下限是否合法
//    int *arr1 = (int*)malloc(size * sizeof(int));//创建动态数组，c++中兼容性更好，
//    //int* arr1 = malloc((size_t)size * sizeof(int));
//    if (!arr1) return NULL;//判断是否为空指针，是的话返回NULL
//
//    for (int i = 0; i < size; i++) {
//        arr1[i] = rand() % (high - low + 1) + low;
//    }
//    printf("生成的随机数组为\n");
//    for (int i = 0; i < size; i++) {
//        if (i == 0)
//            printf("{");
//        if (i != size - 1) {
//            printf("%d,",arr1[i]);
//        }
//        else {
//            printf("%d}",arr1[i]);
//        }
//    }
//    return arr1;
//}


int* cra(int size, int low, int high) {
    if (low > high || size<=0)
        return NULL;
    int* arr1 = (int*)malloc(size * sizeof(int));
    if (!arr1)
        return NULL;
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % (high - low + 1) + low;
    }
    return arr1;
}

void print_arr(int arr1[], int n) {
    printf("数组为");
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("{");
        if (i != n - 1) {
            printf("%d,", arr1[i]);
        }
        else {
            printf("%d}\n", arr1[i]);
        }
    }
}

