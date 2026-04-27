//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//ASCII码表中，48是1，65是A，97是a
//73,32,99,97,110,32,100,111,32,105,116,33

int main()
{
	int quit_C = 0;//退出条件
	int count_n = 0;//对已输入的数进行计数
	int a = 0;//存入最近输入的数
	int ch;
	int* arr_i = (int*)malloc(10*sizeof(int));
	while (scanf("%d", &a) == 1) {
			printf("获取的数据是%d\n",a);
			arr_i[count_n++] = a;
	}
	printf("数据录入完毕\n");
	/*int len = sizeof(arr_i)/sizeof(arr_i[0]);*/
	char* result = (char*)malloc((count_n +1) * sizeof(char));
	for (int i = 0; i < count_n; i++) {
		printf("%d\n", arr_i[i]);
		//result[i] = (char)ascii_codes[i];
		result[i] = (char)arr_i[i];
	}
	for (int i = 0; i < count_n + 1; i++) {
		printf("%c\n",result[i]);
	}
	free(arr_i);
	return 0;
}