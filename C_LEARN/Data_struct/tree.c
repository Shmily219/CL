//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include "tree.h"
#include "def.c"

//定义队列结点
typedef struct Queuenode {
	int data;
	struct Queuenode* next;
}Queuenode;

//定义队列
typedef struct QueueLink {
	struct Queuenode* rear, * front;
	int len;
}QueueLink;

//队列判空
int Queueempty(QueueLink* Q) {
	if (!Q)return 1;
	return Q->front == Q->rear;
}


//初始化队列
int Initqueue(QueueLink* Q) {
	if (Queueempty(Q))return 0;
	Q->len = 0;
	Q->rear = Q->front = NULL;
	return 1;
}

//入队
int Inqueue(QueueLink *Q,int data) {
	if (!Q)return 0;
	Queuenode* newnode = malloc(sizeof(Queuenode));
	if (!newnode)return 0;
	newnode->data = data;
	newnode->next = NULL;
	//处理空结点
	if (!Q->rear) {
		Q->front = Q->rear = newnode;
	}
	else {
		Q->rear->next = newnode;
		Q->rear = newnode;
	}
	Q->len++;
	return 1;
}

//出队(数据没有0的情况下)
int Outqueue(QueueLink* Q) {
	if (!Q)return 0;
	int data = Q->front->data;
	Queuenode* p = Q->front;
	if (!Q->front->next) {
		Q->front = Q->rear = NULL;
	}else {
		Q->front = Q->front->next;
	}
	free(p);
	Q->len--;
	return data;
}

//声明一个树以及结点
typedef struct Treenode {
	struct Treenode *lc, *rc;
	int data;
	struct Treenode* ltag, * rtag;
}Treenode,*Tree;

//创建树的结点
Treenode* Createtreenode(int data) {
	Treenode* newnode = malloc(sizeof(Treenode));
	if (!newnode)return 0;
	newnode->data = data;
	newnode->lc = newnode->rc = NULL;
	newnode->ltag = newnode->rtag = 0;//0指向孩子，1指向前驱或后继
	return newnode;
}

//层序遍历
int LevelOrder(Treenode* T,Treenode* root) {
	if (!T || !root)return 0;
	QueueLink Q;
	Initqueue(&Q);
	Inqueue(&Q,root->data);
	
}

