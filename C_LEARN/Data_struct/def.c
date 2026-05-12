//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //io功能库
#include <stdlib.h>
#include "def.h"
#include <stdbool.h>

//初始化一个顺序表
void Initsq(Sqlist *L) {
	L->p = (int*)malloc(10 * sizeof(int));					//p为存储顺序表的一维数组
	if (L->p == NULL) {
		printf("顺序表的数组分配失败！\n");
		return;
	}
	L->maxlen = 10;											//顺序表的最大容量
	L->len = 0;												//顺序表的当前占用量
}

//输出顺序表的内容
void printsq(Sqlist* L) {
	if (L == NULL) {										//检查顺序表是否初始化，是否合规
		return;
	}
	if (L->len == 0) {
		printf("空表{}\n");
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
void Increasesq(Sqlist* L, int n) {	
	if (L == NULL || n <= 0) {
		printf("链表不规范或扩展数位不合理!\n");
		return;
	}
	//int* data = L->p;
	int* new_data = malloc((L->maxlen + n) * sizeof(int));	//新创建一个指针指向新开辟的数组内存空间
	if (new_data == NULL) {									//防御性排错
		printf("内存分配失败!\n");
		return;
	}
	for (int i = 0; i < L->len; i++) {						//将旧空间的数据复制到新空间
		new_data[i] = L->p[i];
	}
	L->maxlen += n;											//顺序表基础属性变更
	free(L->p);												//释放旧空间
	L->p = new_data;										//将旧空间的指针指向新空间
}

//顺序表的插入，d->data是数据，l->location是位置
bool Insertsq(Sqlist* L, int d, int l) {
	if (l<0||l>(L->len)-1) {								//防御性排错
		printf("位置不合法\n");
		return false;
	}
	while (L->len >= L->maxlen) {
		Increasesq(L, 5);
	}
	int move_num = (L->len) - l + 1;						//假设顺序表有len个数，插入到l处，则插入的下标为l-1，需要移动的个数是len-(l-1)=len-l+1
	for (int i = L->len; i > L->len - move_num; i--) {
		 L->p[i] = L->p[i-1];								//数据后移
	}
	L->p[l-1] = d;											//插入数据
	L->len++;
	return true;
}

//删除一个顺序表中的元素
int Delectsq(Sqlist* L, int l) {
	if (l<0 || l>(L->len) - 1) {
		printf("位置不合法\n");
		return 1;
	}
	int result = L->p[l-1];									//删除第l个元素，其下标为l-1
	for (int i = l; i < L->len+1; i++) {					//删除第l个元素，则l-1个元素不动，需要移动的元素为len-(l-1) = len-l+1
		L->p[i-1] = L->p[i];								//朝前赋值
	}
	L->len--;
	printf("删除的值为%d\n",result);
	return result;
}

//查找一个元素是否在顺序表中
int Findsqn(Sqlist* L, int f) {								
	for (int i = 0; i < L->len; i++) {						//遍历顺序表
		if (L->p[i] == f) {
			printf("已找到，在链表的第%d个位置\n", i + 1);
			return i + 1;
		}
		if (i == L->len-1) {								//如果最后一个判断依旧匹配不上，则返回对应信心		
			printf("未找到\n");
			return -1;
		}
	}
}

//按下标查找顺序表
int Findsqi(Sqlist* L, int i) {
	return L->p[i - 1];
}

//创建新节点
Node* CreateNode(int i) {
	Node* nnode = malloc(sizeof(Node));						//分配新的节点		
	if (nnode == NULL)return;
	nnode->data = i;
	nnode->next = NULL;
	return nnode;
}

//初始化一个单链表(带头节点)
void InitLinkList(LinkList* L) {
	if (L == NULL) return;									//判断指针是否为空
	Node* cur = L->head;									//创建指向头节点的指针
	L->head = malloc(sizeof(Node));							//顺序表链头创建节点实例
	if (L->head == NULL) {									//防御性
		printf("内存分配失败\n");
		return;
	}
	L->head->next = NULL;									//头节点指空
	L->len = 0;									
}


//带头节点
//打印链表
void printlinklist(LinkList *L) {
	if (L == NULL || L->head == NULL) {						//防御
		printf("空链表\n");
	}
	Node* cur = L->head->next;								//cur是一个专门指向Node结构体的指针
	while (cur != NULL) {									//cur为空时说明指向了最后一个节点的next指针，表明所有的链表已经遍历完毕
		printf("%d",cur->data);
		if (cur->next != NULL) {							//cur指针如果下一个不为空，则准备打印下一个节点
			printf("->");
		}
		cur = cur->next;
	}
	printf("\n");
}

//头插法
void Yheadin(LinkList* L, int data) {			
	if (L == NULL||L->head == NULL)return;					//防御
	Node* newnode = CreateNode(data);						//创建拟插入的新节点
	if (newnode == NULL)return;								//防御
	if (L->head->next == NULL) {							//已经实例化的空链表特殊处理，因为L->head->next要赋值给新节点，主动赋值点不能为空，也就是不能出现空指针
		L->head->next = newnode;
		L->len++;
		return;
	}
	newnode->next = L->head->next;							//优先设置新节点的后继节点关系
	L->head->next = newnode;								//插入节点作为头节点的后继节点
	L->len++;
}

//尾插法
void Ytailin(LinkList* L,int data) {
	if (L == NULL || L->head == NULL)return;
	Node* newnode = CreateNode(data);						//创建拟插入节点
	if (newnode == NULL)return;								//防御
	Node* p = L->head;										//创建一个节点指针，使其寻找最后一个元素，结合下面的while循环
	while (p->next != NULL) {								//不依赖len属性能让链表更具安全性
		p = p->next;
	}
	p->next = newnode;
	L->len++;
}

//指定位置插入
void Middlein(LinkList* L, int data, int loc) {
	if (L == NULL || L->head == NULL)return;				//防御性
	if (loc<1 || loc>L->len+1) {
		printf("位置不合法!\n");
			return;
	}
	Node* newnode = CreateNode(data);						//创建新节点
	if (newnode == NULL)return;								
	Node* p = L->head;										//创建指针以寻找插入位置
	for (int i = 0; i < loc-1;i++) {						//寻找插入位置
		p = p->next;
	}
	newnode->next = p->next;								//先把新节点的后继节点接上
	p->next = newnode;										//再把新节点作为前一节点的前驱
	L->len++;
}

//指定位置删除节点
int Delectnode(LinkList* L, int loc) {
	if (L == NULL || L->head == NULL) { 
		printf("链表未初始化\n");
		return -1; 
	}
	if (loc<1 || loc>L->len) {
		printf("位置不合法!\n");
		return -1;
	}
	Node* cur = L->head;
	for (int i = 1; i < loc; i++) {
		cur = cur->next;
	}
	Node* waittodelect = cur->next;
	int a = waittodelect->data;
	cur->next = cur->next->next;  //可以加cur下下个节点的判空if，但是一般来说链表都是规范的，我也就懒得写了
	free(waittodelect);
	L->len--;
	return a;
}


//双链表
//创建双链表专属的节点
Dnode* Creatednode(int data) {
	Dnode* newnode = malloc(sizeof(Dnode));
	if (newnode == NULL){
		printf("内存分配失败!\n");
		return NULL;
	}
	newnode->data = data;
	newnode->prior = NULL;
	newnode->next = NULL;
	return newnode;
}

//初始化双链表
void InitDLinklist(Dlinklist* L) {
	if (L == NULL)return;
	//如果分配的L是一个脏数据中的旧链表，则进行free
	if (L->head != NULL) {
		Dnode* p = L->head->next;	//待删除节点
		while (p != NULL) {
			Dnode* next = p->next;	//待删除节点的下一节点
			free(p);
			p = next;
		}
		free(L->head);
	}

	L->head = malloc(sizeof(Dnode));
	if (L->head == NULL) {
		printf("内存分配失败！\n");
		return;
	}
	L->head->next = NULL;
	L->head->prior = NULL;
	L->len = 0;
	return;
}

//双链表头插法
void Dheadin(Dlinklist* L, int data) {
	if (L == NULL || L->head == NULL)return;
	Dnode* newnode = Creatednode(data);
	if (newnode == NULL) {
		printf("内存分配失败！\n");
		return;
	}
	newnode->next = L->head->next;	//优先处理新节点
	newnode->prior = L->head;
	if (L->head->next != NULL) {
		L->head->next->prior = newnode;	//如果链表非空，先把后面节点的前驱改为新节点，不然指针要判空
	}
	L->head->next = newnode;
	L->len++;
}

//双链表尾插法
void Dtailin(Dlinklist* L, int data) {
	if (L == NULL || L->head == NULL)return;
	Dnode* newnode = Creatednode(data);
	if (newnode == NULL) {
		printf("内存分配失败!\n");
		return;
	}
	Dnode* cur = L->head;
	while(cur->next!=NULL) cur = cur->next;
	newnode->prior = cur;
	cur->next = newnode;
	L->len++;
}

//双链表指定位置插入法
void Dmiddlein(Dlinklist* L, int data, int loc) {
	if (L == NULL || L->head == NULL)return;
	if (loc<1 || loc>L->len + 1) {
		printf("位置不合法！\n");
		return;
	};
	Dnode* newnode = Creatednode(data);
	if (newnode == NULL) {
		printf("内存分配失败！\n");
		return;
	}
	Dnode* cur = L->head;
	for (int i = 1; i < loc; i++) {
		cur = cur->next;
	}
	newnode->next = cur->next;
	newnode->prior = cur;
	if (cur->next != NULL) cur->next->prior = newnode;
	cur->next = newnode;
	L->len++;
}

//双链表删除指定位置的元素
int Delectdnode(Dlinklist* L, int loc) {
	if (L == NULL || L->head == NULL) {
		printf("链表未初始化！\n");
		return -1;
	}
	if (loc<1 || loc>L->len) {
		printf("删除位置不合法!\n");
		return -1;
	}
	Dnode* cur = L->head;
	for (int i = 1; i < loc; i++) {
		cur = cur->next;
	}
	Dnode* waittodelect = cur->next;
	int a = waittodelect->data;
	cur->next = waittodelect->next;
	if (waittodelect->next != NULL)waittodelect->next->prior = cur;
	free(waittodelect);
	L->len--;
	return a;
}

//循环链表就是把上面所有的尾节点接上头节点，复试再搞

//初始化一个栈表
void Initstack(Sqstack* S) {
	if (S == NULL) {
		printf("链表未声明\n");
		return;
	}
	S->top = -1;
}

//栈表插入元素
int Stackin(Sqstack* S, int data) {
	if (S == NULL) {
		printf("链表异常\n");
		return 1;
	}
	if (S->top == sizeof(S->data)/sizeof(S->data[0])) {
		printf("栈表已满无法插入\n");
		return 1;
	}
	S->top += 1;
	S->data[S->top] = data;
	return 0;
}

//栈表删除元素
int Stackout(Sqstack* S) {
	if (S == NULL) {
		printf("链表异常\n");
		return -1;
	}
	if (S->top == -1) {
		printf("链表已空\n");
		return -1;
	}
	int i = S->data[S->top--];
	return i;
}

//初始化一个队列
int Initqueue(Queue* Q) {
	if (Q==NULL) {
		printf("队列异常\n");
		return -1;
	}
	Q->front = 0;
	Q->rear = 0;
	return 0;
}

//队列判空
int Queueempty(Queue* Q) {
	return Q->front == Q->rear;
}

//队列判满
int Queuefull(Queue* Q) {
	return Q->front == (Q->rear + 1) % 20;
}

//入队
int Queuein(Queue* Q,int data) {
	if (Queuefull(Q)) {
		printf("队列已满\n");
		return -1;
	}
	Q->data[Q->rear] = data;
	Q->rear = (Q->rear + 1) % 20;
	return 0;
}

//出队
int Queueout(Queue* Q) {
	if (Queueempty(Q)) {
		printf("队列已空\n");
		return -1;
	}
	Q->front = (Q->front + 1) % 20;
	return 0;
}