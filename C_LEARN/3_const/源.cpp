//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数

//%d	打印整形
//%c	打印字符
//%s	打印字符串
//%f	打印float浮点
//%lf	打印double浮点

//枚举常量,创建一个常量类型Color，其值有RGB三种，且其值只能在定义域中修改
enum Color {
	Red,
	Green,
	Blue
};

int main()
{
	int a = 10;
	a = 20;
	printf("a的值现在是%d\n",a);
	const int b = 30; //表示b的值不能修改
	printf("b的值现在是%d\n", b);

	//保存字符
	char c = 'a';
	//保存字符串要借助数组,字符串默认结束符为\0
	char arr1[] = "abcdef";
	char arr2[] = { 'a','b','c','d','e','f'};
	int m = strlen(arr1);
	printf("这里是arr1的长度%d\n",m);
	printf("%d\n",sizeof(arr2));
	printf("arr1的值为%s\n",arr1);
	printf("arr2的值为%s\n",arr2);
	printf("%d\n",strlen("1234"));
	//printf("代码结束");

	//选择语句
	//int input;
	//printf("请输入你的年龄\n");
	//scanf("%d",&input);
	//if (input >= 18) {
	//	printf("你的年龄为%d，已成年",input);
	//}
	//else {
	//	printf("你的年龄为%d，未成年",input);
	//}

	//循环语句
	int line = 0;
	while (line < 20000) {
		printf("已经运行了%d行代码\n",line+1);
		line++;
	}



	return 0;
}