#pragma once
// 声明结构体
typedef struct {
	int* p;
	int max_len;
	int len;
}Sqlist;

// 声明函数
void Initsq(Sqlist* L);
void Increasesq(Sqlist* L, int n);