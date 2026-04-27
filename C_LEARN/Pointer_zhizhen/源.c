//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数

//指针是一个变量，存储的是地址
//指针变量的类型决定了指针变量存储地址的类型

int main(){
	int a = 10;
	printf("%d\n",a);
	printf("%p\n",&a);

	//存地址需要用指针变量
	int* p = &a;
	printf("%p\n", p);
	printf("测试中文输出\n");

	//指针变量的大小取决于系统位数，32位系统指针变量占4个字节，64位系统指针变量占8个字节
	int* p1 = &a;
	printf("%d\n", sizeof(p1));
	printf("%d\n",sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	return 0;
}
