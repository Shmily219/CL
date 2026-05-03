//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "def.h"
#include "sort.h"
#include "find.h"
#include <math.h>

int main() {
    srand((unsigned int)time(NULL));
    //打印1到400的素数并统计个数
    //int count_n = 0;
    //for (int i = 2; i <= 400; i++) {
    //    for (int j = 2; j <= i; j++) {
    //        if (j > i / 2) {
    //            count_n += 1;
    //            printf("第%d个素数是%d\n", count_n, i);
    //            break;
    //        };
    //        if (i == 2) {
    //            count_n += 1;
    //            printf("第%d个素数是%d\n", count_n, i);
    //            break;
    //        }
    //        if (i % j == 0) {
    //            break;
    //        }
    //    }
    //}
    //printf("%d\n",count_n);

    //打印1到400的素数并统计个数
    //int count_n = 0;
    //for (int i = 1; i <= 400; i++) {
    //    if (judge_sushu(i)) {
    //        count_n++;
    //        printf("第%d个素数是%d\n",count_n, i);
    //    }
    //}
    //printf("%d\n",count_n);

    //写函数交换两个数的和
    //int a = 0;
    //int b = 0;
    //scanf("%d %d",&a,&b);
    //printf("a和b的值是%d,%d\n", a, b);
    //def_Swap(&a, &b);
    //printf("a和b的值是%d,%d\n", a, b);

    ////判断字符串是否相等
    //char arr1[] = "I got it!";
    //char arr2[20] = {0};
    //printf("输入文本\n");
    //scanf("%[^\n]",arr2); //%[^\n]可以读取输入的一整行字符串
    ////printf("%d\n",strcmp(arr1,arr2));
    //printf("arr1和arr2的匹配结果是%d\n",strcmp(arr1,arr2));
    //printf("arr1和语句的匹配结果是%d\n",strcmp(arr1, "I got it!"));
    //printf("arr2和语句的匹配结果是%d\n",strcmp(arr2, "I got it!"));

    //生成随机数
    //for (int i = 0; i < 10; i++) {
    //    Sleep(1000);
    //    printf("%d\n", Create_random(10, 100));
    //}

    ////字符串截取,
    //char arr1[] = "welcome to Xihua!";
    //char arr2[] = "#################";
    //int left = 0;
    //int right = strlen(arr1) - 1; //字符串末尾有一个\0转义,要减去
    //while (left<=right){
    //    //for (int i = 0; i <= left;i++) {
    //    arr2[left] = arr1[left];
    //    arr2[right] = arr1[right];
    //    printf("%s\n",arr2);
    //    Sleep(1000);
    //    system("cls");
    //    //}
    //    left++;
    //    right--;
    //}

    //计算n的阶乘
    //printf("输入你准备计算阶乘的数\n");
    //int a = 0;
    //scanf("%d",&a);
    //printf("阶乘的结果为%d\n",Count_jiecheng(a));
    

    //计算斐波那契
    //printf("输入你准备计算斐波那契的数\n");
    //int b = 0;
    //scanf("%d",&b);
    //printf("斐波那契的第%d项是%d\n",b,FBNQ(b));

    //四数找最大
    //int a, b, c, d, e;
    //int arrf[4] = {0};
    //for (int i = 0; i < 4; i++) {
    //    scanf("%d", &arrf[i]);
    //}
    //e = arrf[0];
    //for (int i = 0; i < 2; i++) {
    //    if (e < arrf[i + 1]) {
    //        e = arrf[i + 1];
    //    }
    //}
    //printf("最大值是%d\n", e);

    //输入学号以及三科成绩
    //int id;
    //float Chinese;
    //float Math;
    //float English;
    //scanf("%d;%f,%f,%f",&id, &Chinese, &Math, &English);
    //printf("The each subject score of No.%d is %.2f, %.2f, %.2f.\n",id, Chinese, Math, English);

    //输入一个八位int，返回出生年月日
    //int Y;
    //int M;
    //int D;
    //scanf("%4d%2d%2d",&Y,&M,&D);
    //printf("年份为%d\n月份为%02d\n日期为%02d\n",Y,M,D);
    ////printf("月份为%02d\n",M);
    ////printf("日期为%02d\n", D);

    //开方计算
    //double a = 0;
    //scanf("%lf", &a);
    //printf("读取到的a的值为%.1lf\n", a);
    //double b = sqrt(a);
    //printf("%.1lf\n",b);
    //printf("%.1lf\n", sqrt(a));

    //判断闰年
    //int count_n = 0;
    //for (int i = 1000; i <= 2000; i++) {
    //    if (judge_runnian(i)) {
    //        count_n += 1;
    //        printf("%d\n",i);
    //    }
    //}
    //printf("%d\n", count_n);

    //生成一个随机的数组
    //int* arr2 = cra(25, 1, 100);
    //int arr2[25] = {56,19,41,25,90,29,55,25,64,77,27,25,14,63,34,14,51,4,69,24,97,68,100,34,32}
    //print_arr(arr2, 25);
    //Maopao(arr2,25);
    //Insert(arr2, 25);
    //Shell(arr2, 25);
    //Qsert(arr2, 0, 24);
    //print_arr(arr2, 25);
    //two_find(arr2, 20, 72);
    //free(arr2);

    char* buf = (int*)malloc(20 * sizeof(char));
    //char buf[100];
    int a = 0;
    char s[10];
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %9s", &a, s);
    for (int i = 0; buf[i] != NULL; i++) {
        printf("%c ",buf[i]);
    }


    return 0;
}


