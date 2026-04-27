//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数

#define ADD(x,y) ((x)+(y))

int main()
{
	int a = 10;
	int b = 20;
	int c = ADD(a, b);
	printf("%d\n",c);
	printf("%d\n",ADD(a,b));
	return 0;
}