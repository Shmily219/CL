//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数
//#include <windows.h>

//创建一个二元二次函数
int func(int x, int y) {
	int fun = x * x + y * y / 2;
	return fun;
}

int main()
{
	//SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为UTF-8
	//SetConsoleCP(CP_UTF8);       // 设置控制台输入为UTF-8
	//int x = 0;
	//int y = 0;
	//printf("输入你的x和y，用空格隔开\n");
	//scanf("%d %d",&x,&y);
	//printf("函数计算的结果是%d",func(x,y));

	int a[] = {10 ,11, 12, 13, 14, 15, 16, 17, 18, 19};
	printf("数组的长度为%d\n",sizeof(a)/sizeof(a[0]));
	for (int i = 0; i < 10;i++) {
		printf("%d\n",a[i]);
	};
	return 0;
}