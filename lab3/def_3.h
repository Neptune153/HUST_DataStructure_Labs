#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXLENGTH 100
#define LISTINCREMENT 10
#define N 10
typedef int status;
typedef int KeyType; 
typedef struct {
    KeyType  key;
    char others[20];
} TElemType;                     //������������Ͷ���
typedef struct BiTNode{  
	TElemType  data;            
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;     //����������Ķ���
typedef struct {
    struct 
    {
        char name[30];
        BiTree T;
    } elem[10];
    int length;
    int listsize;
} BiTreelists;       ////�������Ĺ������
BiTreelists lists;
typedef struct {
    int pos;
    TElemType data;
} DEF;
typedef struct QUEUE
{
    BiTree elem[MAXLENGTH];
    int front,length;
} QUEUE;
void iniQueue(QUEUE &Q);
status enQueue(QUEUE &Q, BiTree e);
status deQueue(QUEUE &Q, BiTree &e);
typedef struct STACK
{
    BiTree elem[N];
    int top1;
} STACK;
void inistack(STACK &S);
status push(STACK &S, BiTree e);
BiTree pop(STACK &S);

#define free free0
#undef free
int freed=FALSE;
KeyType e;
void visit(BiTree T);
void free0(void *p);
status CreateBiTree(BiTree &T, DEF definition[]);
status DestroyBiTree(BiTree &T);
status ClearBiTree(BiTree &T);
status BiTreeEmpty(BiTree T);
status BiTreeDepth(BiTree T);
BiTNode *LocateNode(BiTree T, KeyType e);
status Assign(BiTree &T, KeyType e, TElemType value); /********** End **********/
BiTNode *GetSibling(BiTree T, KeyType e);             // ����ֵܽڵ�
BiTNode *Get(BiTree T, KeyType e);                    // ���˫�׽ڵ�
BiTNode *Getright(BiTree p);                          // ������������ҽ�
status InsertNode(BiTree &T, KeyType e, int LR, TElemType c);
status DeleteNode(BiTree &T, KeyType e);
status PreOrderTraverse(BiTree T, void (*visit)(BiTree));   // ǰ�����
status InOrderTraverse(BiTree T, void (*visit)(BiTree));    // �������
status PostOrderTraverse(BiTree T, void (*visit)(BiTree));  // �������
status LevelOrderTraverse(BiTree T, void (*visit)(BiTree)); // �������
status MaxPathSum(BiTree T);
BiTNode *LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2);
BiTNode *InvertTree(BiTree &T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
status SaveBiTree(BiTree T, char FileName[]);
status LoadBiTree(BiTree &T, char FileName[]);
status check(char name[]);
void My_print(void);