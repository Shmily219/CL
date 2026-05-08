#pragma once
// 声明一个顺序表
typedef struct {
	int* p;
	int maxlen;
	int len;
}Sqlist;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//声明一个单链表节点的结构体
typedef struct Node {
	int data;  //数据域
	struct Node* next;  //该指针指向与Node自身属性相同的其他节点结构体
}Node;

//声明一个单链表整体的结构体
typedef struct{
	Node* head;  //指向头节点的指针
	int len;
}LinkList;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//声明一个双链表节点的结构体
typedef struct Dnode {
	int data;
	struct Dnode* next, prior;
}Dnode;

//声明一个双链表整体的结构体
typedef struct{
	Dnode* head;
	int len;
}Dlinklist;

// 声明函数
void Initsq(Sqlist* L);
void Increasesq(Sqlist* L, int n);