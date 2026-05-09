#pragma once
// 声明一个顺序表
typedef struct {
	int* p;
	int maxlen;
	int len;
}Sqlist;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//声明一个单链表节点
typedef struct Node {
	int data;						//数据域
	struct Node* next;				//该指针指向与Node自身属性相同的其他节点结构体
}Node;

//声明一个单链表整体
typedef struct{
	Node* head;						//指向头节点的指针
	int len;						//存储单链表的长度
}LinkList;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//声明一个双链表节点
typedef struct Dnode {
	int data;						//数据域
	struct Dnode* next, *prior;		//存储前驱指针和后继指针
}Dnode;

//声明一个双链表整体
typedef struct{
	Dnode* head;					//指向头节点的指针
	int len;						//存储双链表长度
}Dlinklist;

// 声明函数
void Initsq(Sqlist* L);
void Increasesq(Sqlist* L, int n);