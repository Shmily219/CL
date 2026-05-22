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


//赋值给字符串
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
		S->maxlen = 2*n+1;									//加一是因为字符串结尾是\0
	}
	strcpy(S->ch, C);										//将C的内容传入S->ch
	S->len = n;
	return 1;
}

//拼接字符串
int Extendstr(Str* S, const char* C) {
	if (S == NULL || C == NULL) {						//检查参数是否规范
		printf("传参异常\n");
		return 0;
	}
	int n = strlen(C);									//记录待接入字符串的长度
	if (!n) return 0;									
	if (n + S->len >= S->maxlen||S->ch == NULL) {		//如果两个字符串的长度和超出了maxlen，则扩容。同时为了避免另一分支传入空指针，故再此处理空指针情况
		char* temp = malloc(n + S->len + 1);			//创建新空间，准备写入
		if (temp == NULL) {								//防御
			printf("内存分配失败\n");			
			return 0;
		}
		if (S->ch == NULL) {							//处理空指针
			temp[0] = '\0';								//将temp设置为空字符串，随后的赋值会将该\0覆盖掉
		}else {	
			memcpy(temp, S->ch,S->len);					//不是空指针，直接把旧空间数据迁移
		}
		memcpy(temp+S->len, C, n+1);					//旧数据处理完毕，这里把待接入的字符串进行拼接，要留一个空间给\0
		S->maxlen = S->len + 1 + n;						//重新设置最大的容量。可以根据情况调整扩容大小，这里刚好扩容到len
		free(S->ch);
		S->ch = temp;
	}
	else {
		memcpy(S->ch + S->len, C, n + 1);				//直接拼接
	}
	S->len += n;										//更新len
	return 1;
}

//比较字符串
int Comparestr(Str* a, Str* b) {
	if (!a || !b || !a->ch || !b->ch) return -2;
	int i = 0;
	while (a->ch[i] != '\0' && b->ch[i] != '\0') {
		if (a->ch[i] == b->ch[i]) {
			i++;
		}
		if (a->ch[i] > b->ch[i]) {
			return 1;
		}
		else {
			return -1;
		}
	}
	if (a->ch[i] == '\0' && b->ch[i] == '\0') return 0;
	if (a->ch[i] == '\0') return -1;
	if (b->ch[i] == '\0') return 1;
}