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
/*
#define Node LNode
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//������Q�Ļ������� �з���ֵ �������� 9��CORE
Status InitQueue(LinkQueue &Q) //��ʼ��������Q 1
Status DestroyQueue(LinkQueue &Q) //����������Q 2
Status ClearQueue(LinkQueue &Q) //���������Q 3
Status QueueEmpty(LinkQueue Q) //�ж�������Q�Ƿ�Ϊ�� 4
int QueueLength(LinkQueue Q) //��������Q�ĳ��� 5
QElemType GetHead(LinkQueue Q) //ȡ������Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
Status EnQueue(LinkQueue &Q,e) //ѹ���� ����һ�����ж�Ԫ�� 7
Status Dequeue(LinkQueue &Q,&e) //������ ����һ�����ж�Ԫ�� 8
Status QueueTraverse(LinkQueue Q,visit()) //����������Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
*/
/*
//������Q�Ļ������� �޷���ֵ ��� 9��CORE
InitQueue(&Q) //��ʼ��������Q 1
DestroyQueue(&Q) //����������Q 2
ClearQueue(&Q) //���������Q 3
QueueEmpty(Q) //�ж�������Q�Ƿ�Ϊ�� 4
QueueLength(Q) //��������Q�ĳ��� 5
GetHead(Q) //ȡ������Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
EnQueue(&Q,e) //ѹ���� ����һ�����ж�Ԫ�� 7
Dequeue(&Q,&e) //������ ����һ�����ж�Ԫ�� 8
QueueTraverse(Q,visit()) //����������Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
*/
//---------------������----------------
//������ ��ʼ��InitQueue β�巨 ����EnQueue ɾ��Dequeue ����GetHead ����QueueLength
//��� β ������ ͷ
typedef struct Qnode { //��װһ��������Node Tan
	QElemType data; //������
	struct Qnode *next; //ָ���� next
}Qnode, QNode, *QueuePtr;
typedef struct LinkQueue { //��װһ�������� ����
	QueuePtr front; //ͷָ��
	QueuePtr rear; //βָ��
}LinkQueue;
Status InitQueue(LinkQueue &Q) { //��ʼ��������Q 1
	//LinkQueue &Q ָ������ô����洫����
	Q.front = Q.rear = (QueuePtr *)malloc(sizeof(QNode));//���ٿռ�
	if (!Q.front) exit(OVERFLOW);//����ʧ�����˳�
	Q.front->next = NULL; //<==> Q->rear->next = NULL;
	return TRUE;
}
Status DestroyQueue(LinkQueue &Q) //����������Q 2
{}
Status ClearQueue(LinkQueue &Q) //���������Q 3
{}
Status QueueEmpty(LinkQueue Q) //�ж�������Q�Ƿ�Ϊ�� 4
{}
int QueueLength(LinkQueue Q) //��������Q�ĳ��� 5
{}
QElemType GetHead(LinkQueue Q) //ȡ������Q�� Head Ԫ�� ȡ�ö��е� ���ڵ�Ԫ�� 6
{}
Status EnQueue(LinkQueue &Q, QElemType e) //����� ѹ���� ����һ�����ж�Ԫ�� 7
{
	QueuePtr P��LinkQueue malloc(sizeof(Qnode));//tempPtr,repos, insert new node P
	P->next = NULL;//β�� new node P is tail
	Q.rear->next = p;//βָ rearPtr finger new node
	Q.rear = P;//rearPtr++ move
}
Status Dequeue(LinkQueue &Q, QElemType &e) //������ ����һ�����ж�Ԫ�� 8
{
	e = Q.front->data;
	QueuePtr r = Q.front->next;//tempPtr finger node2
	Q.front->next = r->next;//Q.front++ move  
	free(r);
}
Status QueueTraverse(LinkQueue Q, visit()) //����������Q:���ζ�S��ÿ��Ԫ�ص���visit() 9
{}
