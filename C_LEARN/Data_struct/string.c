//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "string.h"

int Initstr(Str* S) {
	if (S == NULL) {
		printf("字符串未定义\n");
		return 0;
	}
	S->len = 0;
	S->maxlen = 10;
	return 1;
}

int Assignstr(Str* S, const char* C) {						//给字符串传入一个全新的值
	if (S == NULL || C == NULL) {
		printf("字符串未定义或传入串参数异常\n");
		return 0;
	}
	int n = strlen(C);										//记录传入字符串的长度
	if (S->ch == NULL ||S->maxlen < n + 1) {				//如果最大容量比传入串小，则重新分配空间;这里如果不写ch的判断，很可能导致后面的strcpy传入空指针，所以这种情况必须进入该if判断
		char *temp = (char*)malloc(sizeof(char) * (n + 1));	//创建一个新空间，准备传给S->ch
		if (temp == NULL) {
			printf("内存分配失败\n");
			return 0;
		}
		free(S->ch);										//这里不管ch是不是NULL，都主动把该指针置空
		S->ch = temp;										//重新给S->ch分配空间
		S->maxlen = n+1;									//加一是因为字符串结尾是\0
	}
	strcpy(S->ch, C);										//将C的内容传入S->ch
	S->len = n;
	return 1;
}

int Extendstr(Str* S, const char* C) {



	return 1;
}