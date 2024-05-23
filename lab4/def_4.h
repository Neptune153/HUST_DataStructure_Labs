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
#define MAX_VERTEX_NUM 20
#define MAXLENGTH 20
typedef int status;
typedef int KeyType; 
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct {
    KeyType  key;
    char others[20];
} VertexType; //�������Ͷ���
typedef struct ArcNode {         //�������Ͷ���
   	int adjvex;                   //����λ�ñ�� 
    struct ArcNode  *nextarc;	   //��һ������ָ��
} ArcNode;
typedef struct VNode{				//ͷ��㼰���������Ͷ���
    VertexType data;              	//������Ϣ
    ArcNode *firstarc;      	 //ָ���һ����
} VNode,AdjList[MAX_VERTEX_NUM];
typedef  struct {               //�ڽӱ�����Ͷ���
    AdjList vertices;     	 //ͷ�������
    int vexnum,arcnum;   	  //������������
    GraphKind  kind;        //ͼ������
    }ALGraph;
typedef struct QUEUE
{
    ArcNode* elem[MAXLENGTH];
     int front,length;
} QUEUE;
void free0(void  *p);
#define free free0
#undef free
struct ptr{
    void *pused[100],*pfree[100];
    int len_used,len_free;
    } pm;
void free0(void *p)
{
    pm.pfree[pm.len_free++]=p;
    memset(p,0,sizeof(ArcNode));
    free(p);
}
typedef struct {
    struct 
    {
        char name[30];
        ALGraph T;
    } elem[10];
    int length;
    int listsize;
} ALGrapgLists;      
ALGrapgLists lists;
status CreateCraph(ALGraph &G, VertexType V[], KeyType VR[][2]);
status DestroyGraph(ALGraph &G);
int LocateVex(ALGraph G, KeyType u);
status PutVex(ALGraph &G, KeyType u, VertexType value);
int NextAdjVex(ALGraph G, KeyType v, KeyType w);
status InsertVex(ALGraph &G, VertexType v);
status DeleteVex(ALGraph &G, KeyType v);
status InsertArc(ALGraph &G, KeyType v, KeyType w);
status DeleteArc(ALGraph &G, KeyType v, KeyType w);
int FirstAdjVex(ALGraph G, KeyType u);
void visit(VertexType v);
void DFS(ALGraph G, int v, bool visited[], void (*visit)(VertexType));
status DFSTraverse(ALGraph &G, void (*visit)(VertexType));
void iniQueue(QUEUE &Q);
int enQueue(QUEUE &Q, ArcNode *e);
int deQueue(QUEUE &Q, ArcNode **e);
status BFSTraverse(ALGraph G, void (*visit)(VertexType));
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]);
void My_print(void);
status check(char name[]);
int less[10]={-1};
int less_k[10];
status VerticesSetLessThanK(ALGraph G, KeyType v, int k);
int visited[10];
int cmpfunc(const void *a, const void *b);
status find(ALGraph G, ArcNode *p, KeyType w, int visited[]);
status ShortestPathLength(ALGraph G, KeyType v, KeyType w);
status ConnectedComponentsNums(ALGraph G);