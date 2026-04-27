//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数
#include <stdlib.h> //提供随机种子
#include <time.h> //提供时间函数

int* Maopao(int arr[]) //arr为传入数组，n为数组长度 
{
	for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - 1; j++) {
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
				//	if (i == sizeof(arr) / sizeof(arr[0]) - 1) {
				//		printf("%d\n", arr[i]);
				//	}
				//	else {
				//		printf("%d ", arr[i]);
				//	}
				//}
			}
		}
	}
	return arr;
}

int main()
{
	srand((unsigned int)time(NULL)); //根据时间创造随机种子
	int arr1[10];//初始化
	for (int i = 0; i < 10; i++) {
		arr1[i] = rand() % 100;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);
	}

	int arr[10] = { 95, 0, 89, 22, 32, 43, 8, 19, 21, 11};
	//冒泡排序
	for (int j = 0; j < sizeof(arr) / sizeof(arr[0])-1;j++) {
		for (int i = 0; i < sizeof(arr)/sizeof(arr[0])-j-1; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
				//	if (i == sizeof(arr) / sizeof(arr[0]) - 1) {
				//		printf("%d\n", arr[i]);
				//	}
				//	else {
				//		printf("%d ", arr[i]);
				//	}
				//}
			}
		}
	}


	


	return 0;
}