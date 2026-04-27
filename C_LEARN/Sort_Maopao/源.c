//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数
#include <stdlib.h> //提供随机种子
#include <time.h> //提供时间函数


//返回类型是int，其返回结果表示是否成功，成功为0，否则为1
//返回类型是int*，表示返回结果被程序存入了某个内存地址/某个指针
int* quick_sort(int arrq[], int n) {
	int temp = arrq[0];
	int LC = 0;
	int RC = 0;//LC为左半区比锚点小的计数器，RC为右半区计数器
	int* arr[] = (int*)malloc(n * sizeof(int)); //创建一个新数组
	for (int i = 1; i < sizeof(arrq) / sizeof(arr[0]);i++) {
		if (arrq[i] < temp) {
			arr[LC] = arrq[i];
			LC += 1;
		}
		else {
			arr[sizeof(arrq)/sizeof(arrq[0])-RC-1] = arrq[i];
			RC += 1;
		}
	}
	arr[LC] = temp;
	return arr;
}

//int* qsort(int arrq[], int n) {
//	int temp = arrq[0]; //取出第一个元素作为哨兵
//	int left_count = 0; //左计数变量，统计比哨兵小的数的个数，决定了哨兵最后所插入的位置
//	int right_count = 0; //右计数变量，统计比哨兵大的数的个数
//	int* new_arr = (int*)malloc(n * sizeof(int)); //创建一个动态数组，动态数组的长度为传入参数n
//	for (int i = 1; i < n - 1; i++) {
//		if (arrq[i] <= temp) //开始遍历原数组除了哨兵之外的所有的数，数组长度为10，哨兵为0，其余数的下标为1到n-1，总共遍历n-1次
//		{
//			new_arr[0] = temp; //判断第n个元素小于哨兵，存入新建数组最左边一个空位
//			left_count += 1;
//		}
//		else {
//			new_arr[n - right_count -2] = temp;//判断第n个元素大于哨兵，存入新建数组最右边一个空位
//			right_count += 1;
//		}
//	}
//	new_arr[left_count] = temp;
//	//free(new_arr);保证以后不用了再free掉动态数组占用的内存空间
//	return new_arr;
//}


int main()
{
	int arr[10] = { 14, 25, 17, 79, 5, 61, 24, 3, 55, 94 };
	int* arr_test = quick_sort(arr, sizeof(arr) / sizeof(arr[0]));
	//for (int i = 0; i < 10; i++) {
	//	printf("%d\n", arr_test[i]);
	//}
	free(arr_test);

	//srand((unsigned int)time(NULL)); //根据时间创造随机种子
	//int arr1[10];//初始化
	//for (int i = 0; i < 10; i++) {
	//	arr1[i] = rand() % 100;
	//}
	//for (int i = 0; i < 10; i++) {
	//	printf("%d ", arr1[i]);
	//}

	//冒泡排序
	//for (int j = 0; j < sizeof(arr) / sizeof(arr[0])-1;j++) {
	//	for (int i = 0; i < sizeof(arr)/sizeof(arr[0])-j-1; i++) {
	//		if (arr[i] > arr[i + 1]) {
	//			int temp = arr[i];
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//			for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
	//				if (i == sizeof(arr) / sizeof(arr[0]) - 1) {
	//					printf("%d\n", arr[i]);
	//				}
	//				else {
	//					printf("%d ", arr[i]);
	//				}
	//			}
	//		}
	//	}
	//}




	return 0;
}