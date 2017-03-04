#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE  -1
#define OVERFLOW -2
//#define Status int
typedef int ElemType;
typedef int Status;
/*
#define Node Node
#define LEN sizeof(Node)
#define MLC (Node *)malloc
#define MLCS (Node *)malloc(sizeof(Node))
*/
#define MAX_STR_LEN 255
typedef unsigned char String[MAX_STR_LEN + 1];
//下标为0的分量存放串的实际长度
StrAssign(&T, chars) {}
StrCopy(&T，S) {}
StrEmpty(S) {}
StrCompare(S, T) {}
StrLength(S) {}
ClearString(&S) {}
Status Concat(SString &T,SString S1, SString S2) {
	//串联结
	//S1,S2联接后成为新串送入T,0下标变量存放串的长度
	if (s1[0] + s2[0] <= MAX_STR_LEN) {
		T[]
	}
	else if (s1[0]< MAX_STR_LEN) {

	}
}
SubString(&Sub, S, pos, len) {}
Index(S, T, pos) {}
Replace(&S, T, V) {}
StrInsert(&S, pos, T) {}
StrDelete(&S，pos, len) {}
DestroyString(&S) {}