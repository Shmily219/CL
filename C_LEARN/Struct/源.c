//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数

struct Student
{
	char name[20];
	int age;
	long long tele;
	int sex;
};

int main()
{
	struct Student stu1 = { "张三", 20, 15208432324, 1};
	printf("姓名：%s\n", stu1.name);
	printf("年龄：%d\n", stu1.age);
	printf("电话：%lld\n", stu1.tele);
	printf("%d\n",stu1.sex);
	printf("性别：%s\n", stu1.sex==1 ? "男" : "女");
	return 0;
}