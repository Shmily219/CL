#pragma once
// 声明结构体
typedef struct {
	int* p;
	int maxlen;
	int len;
}Sqlist;

// 声明函数
void Initsq(Sqlist* L);
void Increasesq(Sqlist* L, int n);