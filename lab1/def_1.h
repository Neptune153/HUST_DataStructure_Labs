#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include"string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���
typedef struct{  //˳���˳��ṹ���Ķ���
	      int * elem;
	      int length;
	      int listsize;
}SqList;

typedef struct{  //���Ա�Ĺ������
     struct { 
		char name[30];
     	SqList L;	
      } elem[10];
      int length;
      int listsize;
}LISTS;


LISTS lists;

int cmp(const void *a, const void *b);
status InitList(SqList &L); 
status DestroyList(SqList &L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L, int i, ElemType &e);
status LocateElem(SqList L, ElemType e);
status PriorElem(SqList L, ElemType e, ElemType &pre);
status NextElem(SqList L, ElemType e, ElemType &next);
status ListInsert(SqList &L, int i, ElemType e);
status ListDelete(SqList &L, int i, ElemType &e);
status ListTraverse(SqList L);
status SaveList(SqList L, char FileName[]);
status LoadList(SqList &L, char FileName[]);
status AddList(LISTS &Lists, char ListName[]);
status RemoveList(LISTS &Lists, char ListName[]);
int LocateList(LISTS Lists, char ListName[]);
status MaxSubArray(SqList L);
status SubArrayNum(SqList L, int K);
void My_print(void);
