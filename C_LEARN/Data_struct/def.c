//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include <stdlib.h>
#include "def.h"
#include <stdbool.h>

//初始化一个顺序表
void Initsq(Sqlist *L) {
	L->p = (int*)malloc(10 * sizeof(int));
	L->maxlen = 10;
	L->len = 0;
}

//输出顺序表的内容
void printsq(Sqlist* L) {
	if (L == NULL) {
		return;
	}
	for (int i = 0; i < L->len; i++) {
		if (i == 0) {
			printf("{%d,",L->p[i]);
		}
		else if (i == (L->len) - 1) {
			printf("%d}\n",L->p[i]);
		}
		else {
			printf("%d,",L->p[i]);
		}
	}
}

//扩展一个顺序表
void Increasesq(Sqlist* L,int n) {
	//int* 
	//int* data = (int*)malloc(L->max_len + n);
	int* data = L->p;
	L->p = (int*)malloc((L->maxlen + n) * sizeof(int));
	for (int i = 0; i < L->maxlen; i++) {
		L->p[i] = data[i];
	}
	L->maxlen += n;
	free(data);
}

//顺序表的插入，d->data是数据，l->location是位置
bool Insertsq(Sqlist* L, int d, int l) {
	if (l<0||l>(L->len)-1) {
		printf("位置不合法\n");
		return false;
	}
	while (L->len >= L->maxlen) {
		Increasesq(L, 5);
	}
	int move_num = (L->len) - l + 1;
	//printf("移动数目为%d\n",move_num);
	for (int i = L->len; i > L->len - move_num; i--) {
		 L->p[i] = L->p[i-1];//数据后移
	}
	L->p[l-1] = d;
	L->len++;
	return true;
}

//删除一个顺序表中的元素
int Delectsq(Sqlist* L, int l) {
	if (l<0 || l>(L->len) - 1) {
		printf("位置不合法\n");
		return 1;
	}
	int result = L->p[l-1];
	for (int i = l; i <+ L->len; i++) {
		L->p[i-1] = L->p[i];//朝前赋值
	}
	L->len--;
	printf("删除的值为%d\n",result);
	return result;
}

//查找一个元素是否在顺序表中
int Findsq(Sqlist* L, int f) {
	for (int i = 0; i <= L->len; i++) {
		if (i == L->len) {
			printf("未找到\n");
			return -1;
		}
		if (L->p[i] == f) {
			printf("已找到，在链表的第%d个位置\n", i + 1);
			return i + 1;
		}
	}
}