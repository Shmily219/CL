//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include <stdlib.h>
#include "def.h"

void Initsq(Sqlist *L) {
	L->p = (int*)malloc(10 * sizeof(int));
	L->max_len = 10;
	L->len = 0;
}

void Increasesq(Sqlist* L,int n) {
	//int* 
	//int* data = (int*)malloc(L->max_len + n);
	int* data = L->p;
	L->p = (int*)malloc((L->max_len + n) * sizeof(int));
	for (int i = 0; i < L->max_len; i++) {
		L->p[i] = data[i];
	}
	L->max_len += n;
	free(data);
}
//int main()
//{
//
//	return 0;
//}