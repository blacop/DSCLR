#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
#define QElemType int
#define Status int
#define MAX_QSIZE 100
/*
#define Node LNode
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//顺序队列Q的基本操作 有返回值 参数类型 9个CORE
Status InitQueue(SqQueue &Q) //初始化顺序队列Q 1
Status DestroyQueue(SqQueue &Q) //销毁顺序队列Q 2
Status ClearQueue(SqQueue &Q) //清空顺序队列Q 3
Status QueueEmpty(SqQueue Q) //判断顺序队列Q是否为空 4
int QueueLength(SqQueue Q) //求顺序队列Q的长度 5
QElemType GetHead(SqQueue Q) //取顺序队列Q的 Head 元素 取得队列的 出口的元素 6
Status EnQueue(SqQueue &Q,e) //压队列 加入一个队列顶元素 7
Status Dequeue(SqQueue &Q,&e) //出队列 弹出一个队列顶元素 8
Status QueueTraverse(SqQueue Q,visit()) //遍历顺序队列Q:依次对S的每个元素调用visit() 9
*/
/*
//顺序队列Q的基本操作 无返回值 简版 9个CORE
InitQueue(&Q) //初始化顺序队列Q 1
DestroyQueue(&Q) //销毁顺序队列Q 2
ClearQueue(&Q) //清空顺序队列Q 3
QueueEmpty(Q) //判断顺序队列Q是否为空 4
QueueLength(Q) //求顺序队列Q的长度 5
GetHead(Q) //取顺序队列Q的 Head 元素 取得队列的 出口的元素 6
EnQueue(&Q,e) //压队列 加入一个队列顶元素 7
Dequeue(&Q,&e) //出队列 弹出一个队列顶元素 8
QueueTraverse(Q,visit()) //遍历顺序队列Q:依次对S的每个元素调用visit() 9
*/
//---------------顺序队列----------------
//顺序队列 初始化InitQueue 尾插法 插入EnQueue 删除Dequeue 查找GetHead 长度QueueLength
//入口 尾 ，出口 头
typedef struct SqQueue { //封装一个顺序队列Node Tan,
						 //循环队列，用游标实现法
	QElemType *base; //base 连续空间首地址
	int front;//指向队列的头一个元素
	int rear;//指向队尾的下一个元素，类似于==>top
}SqQueue;
Status InitQueue(SqQueue &Q) { //初始化顺序队列Q 1
	//SqQueue &Q 指针或引用从外面传进来
	Q->base = (SqQueue *)malloc(MAX_QSIZE * sizeof(SqQueue));//开辟空间
	if (!Q->front) exit(OVERFLOW);//开辟失败则退出
	Q->front = Q->rear = 0;//Q->front->next = NULL; //<==> Q->rear->next = NULL;	
	return TRUE;
}
Status DestroyQueue(SqQueue &Q) //销毁顺序队列Q 2
{}
Status ClearQueue(SqQueue &Q) //清空顺序队列Q 3
{}
Status QueueEmpty(SqQueue Q) //判断顺序队列Q是否为空 4
{
	//出队 入队
}
int QueueLength(SqQueue Q) //求顺序队列Q的长度 5
{}
QElemType GetHead(SqQueue Q) //取顺序队列Q的 Head 元素 取得队列的 出口的元素 6
{}
Status EnQueue(SqQueue &Q, QElemType e) { //入队列 压队列 加入一个队列顶元素 7
	//循环指针++ move 必须求模 (rear+1) mod MAX_QSIZE
	QueuePtr P＝SqQueue malloc(sizeof(Qnode));//tempPtr,repos, insert new node P
	P->next = NULL;//尾插 new node P is tail
	Q->rear->next = p;//尾指 rearPtr finger new node
	Q->rear = P;//rearPtr++ move
}
Status Dequeue(SqQueue &Q, QElemType &e) { //出队列 弹出一个队列顶元素 8
	//循环 指针++ move 必须求模 (rear+1) mod MAX_QSIZE
	e = Q->front->data;
	QueuePtr r = Q->front->next;//tempPtr finger node2
	Q->front->next = r->next;//Q->front++ move  
	free(r);
}
Status QueueTraverse(SqQueue Q, visit()) //遍历顺序队列Q:依次对S的每个元素调用visit() 9
{}
