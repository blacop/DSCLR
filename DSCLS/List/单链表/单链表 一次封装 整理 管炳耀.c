#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
#define ElemType int
#define Status int
typedef int ElemType
typedef int Status
/*
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
typedef struct Node { //封装 结构体 链表的结点==数据元素Elem,结点的指针==链表==数据对象Obj
	ElemType data;  //数据Domain ,数据项item
	struct Node * next; //指针,引用Reference,数据项item
}Node,*PNode;
//#define LNode *PNode
//typedef PNode LNode *
/*
//线性表的基本操作定义声明

Status InitList(SqList &L); 
//操作结果：构造一个空的线性表L。 1

Status DestroyList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：销毁线性表L。 2

Status ClearList(SqList &L);
//初始条件：线性表L已存在。
//操作结果：将L重置为空表。 3

bool ListEmpty(SqList L);
//初始条件：线性表L已存在。
//操作结果：若L为空表，则返回TRUE，否则返回FALSE。 4

int ListLength(SqList L);
//初始条件：线性表L已存在。
//操作结果：返回L中数据元素的个数。 5

Status GetElem(SqList L, int i, ElemType &e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)。
//操作结果：用e返回L中第i个数据元素的值。 6

int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
//初始条件：线性表L已存在，compare()是数据元素判定函数。
//返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0. 7

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。 8

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
//初始条件：线性表L已存在。
//操作结果：若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。9

Status ListInsert(SqList &L, int i, ElemType e);
//初始条件：线性表L已存在，1<=i<=ListLength(L)+1.
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1. 10

Status ListDelete(SqList &L, int i, ElemType &e);
//初始条件：线性表L已存在且非空，1<=i<=ListLength(L).
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1. 11

Status ListTraverse(SqList L, bool(*visit)(ElemType));
//初始条件：线性表L已存在
//操作结果：依次对L的每个元素调用函数visit().一旦visit()失败,则操作失败。 12
*/
/*
//线性表的基本操作定义声明
InitList(&L) //初始化线性表L  1
DestroyList(&L) //销毁线性表L  2
ClearList(&L) //清空线性表L  3
ListEmpty(L) //判断线性表是否为空 4
ListLength(L) //求线性表L的长度 5
GetElem(L,i,&e) //取线性表L的第i个元素 6
LocateElem(L,e,compare()) //定位检索线性表L中元素e 7
PriorElem(L,cur_e,&prio_e) //返回线性表L中元素e的直接前驱元素 8
NextElem(L,cur_e,&next_e) //返回线性表L中元素e的直接后继元素 9
ListInsert(&L,i,e) //在线性表L的第i个元素之前插入元素e,返回Bool 10
ListDelete(&L,i,e) //删除线性表L的第i个元素,被删除元素e的值,返回Bool 11
ListTraverse(L,visit()) //遍历线性表:依次对L的每个元素调用visit() 12
*/
/*进阶算法
//reverseList(&L1) //逆置 单链表 
//mergeList(&L1,L2) //合并 两个线性表L 15
//visit(e) 
//  一般是指树型链表结构中对某个节点内容进行访问的函数， 13
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”

*/

/*
单链表各种操作的C语言实现（一） 2010-07-31 13:41:43
http://blog.chinaunix.net/uid-20788636-id-1841324.html
分类： C/C++
最近，从新复习了一下数据结构中比较重要的几个部分，现在把自己的成果记录下来，主要就是仿照严蔚敏的《数据结构》（C 语言版），中的例子和后面的习题进行改编的。首先，是单链表的各种实现，其中，包含了一些常考的知识点。例如，单链表的逆置，单链表的合并，找到单链表的中间节点等的算法实现。
下面这个是单链表的结构体的定义： */
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LinkList;
/*
下面的基本的单链表的操作：其中，有一些宏，没有给出他们的一些定义，者可以通过，严蔚敏的《数据结构》（C 语言版），查看得到。
*/
Status InitList(struct LNode *L) { /* 功能：构建一个空的带头节点的单链表*/
	(*L) = (struct LNode *)malloc(sizeof(struct LNode)); //产生头节点
	if (!*L)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}
Status DestroyList(struct LNode *L) { /*销毁线性表*/
									  //pHead == L
	struct LNode *q;//temp ptr, q <==> L->next
	while (L) {
		q = L->next;//q++
		free(L);//free l //从头开始free(),一直到最后一个
		L = q;//L++
	}
	return OK;
}
Status ClearList(struct LNode *L) { /*将L重置为空表*/
	LinkList *p, *q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}
Status ListEmpty(LinkList *L) { /*判断链表是否为空表*/
	if (L->next) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
int ListLength(struct LNode *L) { /*返回单链表中元素的个数*/
	int i = 0;
	LinkList *p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
Status GetElem(struct LNode *L, int i, ElemType *e) {
	/* L为带头节点的单链表的头指针，当第i个元素存在时，其值赋给e,并返回OK */
	int j = 1;
	LinkList *p = L->next;
	while (p && j<i) { //until i-1
		p = p->next; //p++
		j++;
	}
	if (!p || j>i)
		return ERROR;
	*e = p->data;
	return OK;
}
int LocateElem(struct LNode *L, ElemType e, Status(*compare) (ElemType, ElemType)) {
	/*返回L中第一个与e满足关系compare()的数据元素的位序，
	若给存在返回值为0，compare()是数据元素的判定函数*/
	int i = 0;
	LinkList *p = L->next;
	while (p) {
		i++;
		if (compare(p->data, e))//compare(*p,e) which SqList
			return i;
		p = p->next;//p++ which SqList
	}
	return 0;
}
Status PriorElem(struct LNode *L, ElemType cur_e, ElemType *pre_e) {
	/*所cur_e是L中的数据元素，且给就第一个，则用pre_e返回它的前驱*/
	LinkList *q, *p = L->next;//p<==>node1 //2 assist Ptr
	while (p->next) {
		q = p->next;//q指向p的后继,q++, node2,no head(node0) because it's no data
		if (q->data == cur_e) { //后继's data is matching cur_e
			*pre_e = p->data; //out data is 后继's 前驱
			return OK;
		}
		p = q;//p++
	}
	return INFEASIBLE;
}
Status NextElem(struct LNode *L, ElemType cur_e, ElemType *next_e) {
	/* 若cur_e是L中的数据元素，且不是最后一个，则用next_e返回它的后继*/
	LinkList *p; //1 assist Ptr
	p = L->next; //node1
	while (p->next) { //have node
		if (p->data == cur_e) { //cur's data is matching
			*next_e = p->next->data; //out cur's next data 
			return OK;
		}
		p = p->next;//
	}
	return INFEASIBLE;
}
Status ListInsert(struct LNode *L, int i, ElemType e) {
	/* 在带头节点的单链表L中的第i个位置之前(before i means index == i-2)插入元素e*/
	int j = 0;
	struct LNode *p = L, *s = NULL; //2 assist Ptr,2个辅助指针
	while (p && j<i - 1) {
		//Loc(i)'s index==(i-1),before i means index ==(i-2) 找到 第(i-1)个位置,插入其后
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)
		return ERROR;
	s = (struct LNode *)malloc(sizeof(struct LNode));
	if (!s)
		printf("malloc error~\n");
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e) {
	/*在带头节点的单链表中删除第i个元素，并有e返回其值*/
	LinkList *p = L, *q; //2 assist Ptr,2个辅助指针
	int j = 0;
	while (p->next && j< i - 1) { // find Loc(i-1)== find index==(i-2)
		p = p->next; //p++
		j++; // now p's Loc is Loc(i-1).
	}
	if (!p->next || j>i - 1)//becase j must cirle (i-1) times.
		return ERROR;
	q = p->next;//q finger to p's 后继Subsequent,p is i's 前驱precursor,
	p->next = q->next;//
	*e = q->data; //out data
	free(q);
	return OK;
}
Status ListTraverse(struct LNode *L, void(*visit)(ElemType)) {
	/* 依次对L的每个元素调用vi(),打印输出语句*/
	LinkList *p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
void MergeList_Link_Guan(LinkList &La, LinkList &Lb) {
	//已知La和Lb升序排列
	//合并得到新的单链表Lc,Lc的元素也按值非递减排列
	LinkList pa, pb, p, q;
	pa = La->next;
	pb = Lb->next;
	q = La;//存放临时指针,q就是pa的前驱元素,q必须始终作为pa的前驱元素
	t = Lb;
	while (pa && pb) {
		if (pa->data <= pb->data) {//如果小于=，pc指针指向pa
			q = pa;//q下移 
			pa = pa->next;//pa下移
		}
		else {
			//如果 且 只有 在    pa->data > pb->data,则将pb插入到pa的前面
			//转化 判断条件 如果 pb->data > pa->data ,则将pb插入到pa的前面
			t = pb;// t 下移
			pb = pb->next;//pb下移
			t->next = pa;//pb插入到pa的前面
			q->next = t;
			q = t;//q必须始终作为pa的前驱元素,因此t赋值给q
		}//2个结合起来就是小者排前面，这个代码写的真差，不是人类看的,因为C在A和B只见跳来跳去，临时pc变量拆成2个就容易理解了
	}
	if (pb) { //pb存在
		q->next = pb; //插入所有剩余的pb
	}
}//MergeList_Link_Yan
void reverse_ite(Node * list) {
	//迭代方式  逆序 这个写法感觉还是有问题
	Node * old_head = NULL;         //原来链表的头  
	Node * new_head = NULL;      //新链表的头  
	Node * cur = list;      //获得原来链表的头  
	//每次将原来链表的头取出，并插入到新链表中，并且是新链表的头  
	while (cur != NULL) {
		old_head = cur->next;      //将原来链表的头取出，并将第二个节点作为头节点  
		cur->next = new_head;   //将取出的头设为新链表的头  
		new_head = cur;      //新链表的头就是目前新链表的头  
		cur = old_head;        //接着处理  
	}
	List = new_head;
}
//递归方式  
void reverse_recursive(Node * old_head, Node * new_head) {
	if (old_head == NULL) {
		List = new_head;
		return;
	}

	Node * tmp = old_head->next;        //将原来链表的头取出，并将第二个节点作为原来链表的头节点用于下一层递归  
	old_head->next = new_head; //将取出的头设为新链表的头  
	reverse_recursive(tmp, old_head);         //接着处理  
}
//生成链表  
void make_list() {
	List = (Node *)malloc(sizeof(Node) * LIST_LEN);
	int i = 0;
	for (i = 0; i < (LIST_LEN - 1); i++) {
		(List + i)->data = i + 1;
		(List + i)->next = List + i + 1;
	}
	(List + LIST_LEN - 1)->data = LIST_LEN;
	(List + LIST_LEN - 1)->next = NULL;
}
//打印俩表的data  
void print_list() {
	Node * cur = List;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
int main() { //测试逆序
	make_list();
	print_list();
	reverse_ite(List);     //迭代方式  
						   //reverse_recursive(List, NULL);     //递归方式  
	print_list();
}