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
//˳�����Q�Ļ������� �з���ֵ �������� 9��CORE
Status InitQueue(SqQueue &Q) //��ʼ��˳�����Q 1
Status DestroyQueue(SqQueue &Q) //����˳�����Q 2
Status ClearQueue(SqQueue &Q) //���˳�����Q 3
Status QueueEmpty(SqQueue Q) //�ж�˳�����Q�Ƿ�Ϊ�� 4
int QueueLength(SqQueue Q) //��˳�����Q�ĳ��� 5
QElemType GetHead(SqQueue Q) //ȡ˳�����Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
Status EnQueue(SqQueue &Q,e) //ѹ���� ����һ�����ж�Ԫ�� 7
Status Dequeue(SqQueue &Q,&e) //������ ����һ�����ж�Ԫ�� 8
Status QueueTraverse(SqQueue Q,visit()) //����˳�����Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
*/
/*
//˳�����Q�Ļ������� �޷���ֵ ��� 9��CORE
InitQueue(&Q) //��ʼ��˳�����Q 1
DestroyQueue(&Q) //����˳�����Q 2
ClearQueue(&Q) //���˳�����Q 3
QueueEmpty(Q) //�ж�˳�����Q�Ƿ�Ϊ�� 4
QueueLength(Q) //��˳�����Q�ĳ��� 5
GetHead(Q) //ȡ˳�����Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
EnQueue(&Q,e) //ѹ���� ����һ�����ж�Ԫ�� 7
Dequeue(&Q,&e) //������ ����һ�����ж�Ԫ�� 8
QueueTraverse(Q,visit()) //����˳�����Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
*/
//---------------˳�����----------------
//˳����� ��ʼ��InitQueue β�巨 ����EnQueue ɾ��Dequeue ����GetHead ����QueueLength
//��� β ������ ͷ
typedef struct SqQueue { //��װһ��˳�����Node Tan,
						 //ѭ�����У����α�ʵ�ַ�
	QElemType *base; //base �����ռ��׵�ַ
	int front;//ָ����е�ͷһ��Ԫ��
	int rear;//ָ���β����һ��Ԫ�أ�������==>top
}SqQueue;
Status InitQueue(SqQueue &Q) { //��ʼ��˳�����Q 1
	//SqQueue &Q ָ������ô����洫����
	Q->base = (SqQueue *)malloc(MAX_QSIZE * sizeof(SqQueue));//���ٿռ�
	if (!Q->front) exit(OVERFLOW);//����ʧ�����˳�
	Q->front = Q->rear = 0;//Q->front->next = NULL; //<==> Q->rear->next = NULL;	
	return TRUE;
}
Status DestroyQueue(SqQueue &Q) //����˳�����Q 2
{}
Status ClearQueue(SqQueue &Q) //���˳�����Q 3
{}
Status QueueEmpty(SqQueue Q) //�ж�˳�����Q�Ƿ�Ϊ�� 4
{
	//���� ���
}
int QueueLength(SqQueue Q) //��˳�����Q�ĳ��� 5
{}
QElemType GetHead(SqQueue Q) //ȡ˳�����Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
{}
Status EnQueue(SqQueue &Q, QElemType e) { //����� ѹ���� ����һ�����ж�Ԫ�� 7
	//ѭ��ָ��++ move ������ģ (rear+1) mod MAX_QSIZE
	QueuePtr P��SqQueue malloc(sizeof(Qnode));//tempPtr,repos, insert new node P
	P->next = NULL;//β�� new node P is tail
	Q->rear->next = p;//βָ rearPtr finger new node
	Q->rear = P;//rearPtr++ move
}
Status Dequeue(SqQueue &Q, QElemType &e) { //������ ����һ�����ж�Ԫ�� 8
	//ѭ�� ָ��++ move ������ģ (rear+1) mod MAX_QSIZE
	e = Q->front->data;
	QueuePtr r = Q->front->next;//tempPtr finger node2
	Q->front->next = r->next;//Q->front++ move  
	free(r);
}
Status QueueTraverse(SqQueue Q, visit()) //����˳�����Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
{}
