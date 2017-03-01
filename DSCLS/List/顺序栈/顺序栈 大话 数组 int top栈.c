#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
#define SElemType int
#define Status int
typedef int SElemType
typedef int Status
#define MAXSIZE 100
#define STACK_INIT_SIZE 100
/*
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
/*
//链栈S的基本操作声明 带返回值 带初始条件 //初始条件:栈S己存在
Status InitStack(&S)
//初始化链栈S
Status DestroyStack(&S)
//初始条件:栈S己存在
//销毁链栈S
Status ClearStack(&S)
//初始条件:栈S己存在
//清空链栈S
Status StackEmpty(S)
//初始条件:栈S己存在
//判断链栈S是否为空
int StackLength(S)
//初始条件:栈S己存在
//求链栈S的长度
ElemType GetTop(S,e)
//初始条件:栈S己存在 且非空
//取链栈S的第i个元素 取得栈的上面顶部出口的元素
Status Push(&S,e)
//初始条件:栈S己存在
//压栈 加入一个栈顶元素
Status Pop(&S,&e)
//初始条件:栈S己存在 且非空
//出栈 弹出一个栈顶元素
Status StackTraverse(S,visit())
//初始条件:栈S己存在 且非空
//遍历链栈S:依次对S的每个元素调用visit()
*/
/*
//链栈S的基本操作声明带返回值
Status InitStack(&S) //初始化链栈S
Status DestroyStack(&S) //销毁链栈S
Status ClearStack(&S) //清空链栈S
Status StackEmpty(S) //判断链栈S是否为空
int StackLength(S) //求链栈S的长度
ElemType GetTop(S,e) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Status Push(&S,e) //压栈 加入一个栈顶元素
Status Pop(&S,&e) //出栈 弹出一个栈顶元素
Status StackTraverse(S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
*/
/*
//链栈S的基本操作简版
InitStack(&S) //初始化链栈S
DestroyStack(&S) //销毁链栈S
ClearStack(&S) //清空链栈S
StackEmpty(S) //判断链栈S是否为空
StackLength(S) //求链栈S的长度
GetTop(S) //取链栈S的第i个元素 取得栈的上面顶部出口的元素
Push(&S,e) //压栈 加入一个栈顶元素
Pop(&S,&e) //出栈 弹出一个栈顶元素
StackTraverse(S,visit()) //遍历链栈S:依次对S的每个元素调用visit()
//visit() //  visit 一般是指树型链表结构中对某个节点内容进行访问的函数，
//	就是取出节点内容去做某一件事，通常算法中不写出具体函数内容。
//  树型链表结构中自顶开始按照某种顺序顺藤摸瓜至某个节点的过程称为“遍历”
*/

//---------------顺序栈----------------
//顺序栈 初始化 压栈 弹栈 判断为空 求容量
/*
* 类名使用驼峰命名法（Camel Case）：VelocityResponseWriter
* 包名使用小写：com.company.project.ui
* 变量使用首字母小写的驼峰命名法（Mixed Case）：studentName
* 常量使用大写:MAX_PARAMETER_COUNT = 100
* 枚举类（enum class）采用驼峰命名法，枚举值（enum values）采用大写。
* 除了常量和枚举值以外，不要使用下划线’_’
*/
/*
typedef struct { //封装一个顺序栈结构 为SqStack
	SElemType *base;//基地址指针,栈底指针,存储空间，存放头地址,也可表示数组的名字 或地址  或第一个元素
	SElemType *top;//栈顶指针,SElemType的指针大小根据数据类型来确定
	int stackSize;//当前存储容量
}SqStack;
*/
typedef struct SqStack { //封装一个顺序栈结构 为SqStack
	SElemType data[MAXSIZE];//基地址指针,存储空间，存放头地址,也可表示数组的名字 或地址  或第一个元素
	int top;//栈顶指针,SElemType的指针大小根据数据类型来确定
}SqStack;
Status InitStack_Sq(SqStack &S) {
	S=()
}//InitStack_Sq
Status Push_Sq_Array(SqStack &S, SElemType e) {
	if (S->top = MAXSIZE - 1) { //full
		return FALSE;
	}
	S->top++;
	S->data[S->top] = e;
	return TRUE;
}

Status Push_Sq_PtrMove(SqStack &S, SElemType e) {
}//Push_Sq
Status Pop_Sq(SqStack &S, SElemType &e) {	
}//Pop
int StackEmpty_Sq(SqStack S) { //判断顺序栈S是否为空
	
}
int StackSize_Sq(SqStack S) { //求顺序栈S的存储容量
	
}




