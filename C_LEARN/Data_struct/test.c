//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include <stdlib.h>
#include <time.h>
#include "def.h"


int main()
{	
	srand(time(NULL));
	Sqlist L;
	Initsq(&L);
	printf("初始化成功!现在申请的最大空间为%d，已使用空间为%d\n",L.maxlen,L.len);
	//L.max_len = 20;
	//L.p[L.len] = 34;
	//L.len++;
	for (int i = 0; i < 10; i++) {
		if (L.maxlen <= L.len) {
			Increasesq(&L, 10);
		}
		L.p[i] = rand() % 100;
		L.len++;
	}
	printf("现在申请的最大空间为%d，已使用空间为%d\n", L.maxlen, L.len);
	printsq(&L);

	Insertsq(&L, 20, 4);  //将20插入到链表L的第四个位置
	printsq(&L);

	Delectsq(&L, 6);  //删除第6个元素并打印
	printsq(&L);

	printf("未找到是-1，找到返回其位置\n%d\n",Findsq(&L, 20));
	printf("现在申请的最大空间为%d，已使用空间为%d\n", L.maxlen, L.len);
	//for (int i = 0; i < L.len; i++) {
	//	printf("L的第%d个元素为%d\n", i+1, L.p[i]);
	//}
	free(L.p);
	return 0;
}