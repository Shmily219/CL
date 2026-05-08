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
int Findsqn(Sqlist* L, int f) {
	for (int i = 0; i < L->len; i++) {
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

//按下标查找顺序表
int Findsqi(Sqlist* L, int i) {
	return L->p[i - 1];
}

//创建新节点
Node* CreateNode(int i) {
	Node* nnode = (Node*)malloc(sizeof(Node));  //分配新的节点
	nnode->data = i;
	nnode->next = NULL;
	return nnode;
}

//初始化一个单链表(带头节点)
void InitLinkList(LinkList* L) {
	if (L == NULL) return;//判断指针是否为空
	// 如果已经初始化过，先释放旧头结点
	if (L->head != NULL) {
		free(L->head);
	}
	L->head = (Node*)malloc(sizeof(Node));
	if (L->head == NULL) {
		printf("内存分配失败\n");
		return;
	}
	L->head->next = NULL;
	L->len = 0;
}


//带头节点
//打印链表
void printlinklist(LinkList *L) {
	if (L == NULL || L->head == NULL) {
		printf("空链表\n");
	}
	Node* cur = L->head->next;				//cur是一个专门指向Node结构体的指针
	while (cur != NULL) {
		printf("%d",cur->data);
		if (cur->next != NULL) {		//cur指针如果下一个不为空，则准备打印下一个节点
			printf("->");
		}
		cur = cur->next;
	}
	printf("\n");
}

//头插法
void Yheadin(LinkList* L, int data) {
	if (L == NULL)return;
	if (L->head == NULL) return;
	Node* newnode = CreateNode(data);
	if (newnode == NULL)return;
	if (L->head->next == NULL) {
		L->head->next = newnode;
		L->len++;
		return;
	}
	newnode->next = L->head->next;
	L->head->next = newnode;
	L->len++;
}

//尾插法
void Ytailin(LinkList* L,int data) {
	if (L == NULL)return;
	if (L->head == NULL) return;
	Node* newnode = CreateNode(data);
	if (newnode == NULL)return;
	Node* p = L->head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = newnode;
	L->len++;
}

//指定位置插入
void Middlein(LinkList* L, int data, int loc) {
	if (L == NULL)return;
	if (L->head == NULL) return;
	if (loc<1 || loc>L->len+1) {
		printf("位置不合法!\n");
			return;
	}
	Node* newnode = CreateNode(data);
	if (newnode == NULL)return;
	Node* p = L->head;
	for (int i = 0; i < loc-1;i++) {  //寻找插入位置
		p = p->next;
	}
	newnode->next = p->next;			//先把新节点的后继节点接上
	p->next = newnode;					//再把新节点作为前一节点的前驱
	L->len++;
}