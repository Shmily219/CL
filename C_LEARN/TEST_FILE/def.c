//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "def.h"

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

void def_Swap(int* a,int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

//计算阶乘ce
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
    }
    return FBNQ(i - 1) + FBNQ(i - 2);
};

//生成随机数
int Create_random() {
    int low = 10;
    int hight = 50;
    srand(time(NULL));
    int seed = rand() % 100 + 1;  //生成一个1-100的随机数
    //printf("%d\n", seed);
    srand(rand() % 100 + 1);
    int a = rand() % (hight - low + 1) + low;
    return a;
}

//int main()
//{
//
//	return 0;
//}