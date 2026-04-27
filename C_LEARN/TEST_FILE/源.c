//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库

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
int FBNQ(int i) {
    if (i == 1 || i == 2) {
        return 1;
    /*}*/
    return FBNQ(i - 1) + FBNQ(i - 2);
}

int main(void)
{
    //计算n的阶乘
    printf("输入你准备计算阶乘的数\n");
    int a = 0;
    scanf("%d",&a);
    printf("阶乘的结果为%d\n",Count_jiecheng(a));
    
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
    return 0;
}