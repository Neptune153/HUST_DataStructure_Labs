#include"def_2.h"
status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L!=NULL)
        return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
    /********** End **********/
}
status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
	for (int i = 0; i < lists.length;i++)
	{
		if(lists.elem[i].L==L)
			*lists.elem[i].name ='\0';
	}
	while (L)
	{
		p = L;
		L = L->next;
		free0(p);
	}
	lists.length--;
	return OK;
    /********** End **********/
}
status ClearList(LinkList &L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    while(L->next)
    {
        p = L->next;
        L->next = p -> next;
        free0(p);
    }
    return OK;
    /********** End **********/
}
status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    else if(L->next)
        return FALSE;
    else
        return TRUE;

    /********** End **********/
}
int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L->next;
    int count = 0;
    while(p)
    {
        p = p->next;
        count++;
    }
    return count;
    /********** End **********/
}
status GetElem(LinkList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    int length = ListLength(L);
    if(i<=0||i>length)
        return ERROR;
    LNode *p;
    p = L->next;
    while(--i)
        p = p->next;
    e = p->data;
    return OK;
    /********** End **********/
}
status LocateElem(LinkList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L->next;
    int count = 1;
    while(p)
    {
        if(e==p->data)
            return count;
		p = p->next;
		count++;
    }
    return ERROR;
    /********** End **********/
}
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    if(L->data==e) //��λ
        return ERROR;
    LNode *p;
    p = L;
    while(p->next)
    {
        if(p->next->data==e&&p!=L)
        {
            pre = p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
    /********** End **********/
}
status NextElem(LinkList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
     if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L;
    while(p->next)
    {
        if(p->data==e)
        {
            next = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
    /********** End **********/
}
status ListInsert(LinkList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    else if(i>1+ListLength(L)||i<=0)
        return ERROR;
    else if(i==1+ListLength(L))
    {
        LNode *p;
        p = L;
        while(p->next)
            p=p->next;
        LinkList L1;
        L1=(LinkList) malloc(sizeof(LNode));
        L1->data = e;
        L1->next = p->next;
        p->next = L1;
        return OK;
    }
    else
    {
        LNode *p;
        p = L;
        while(--i)
            p = p->next;
        LinkList L1;
        L1=(LinkList) malloc(sizeof(LNode));
        L1->data = e;
        L1->next = p->next;
        p->next = L1;
        return OK;
    }
}
status ListDelete(LinkList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    else if(i<=0||i>ListLength(L))
        return ERROR;
    else
    {
        LNode *p;
        p = L;
        while(--i)
            p = p->next;
        e = p->next->data;
        LinkList p2=(LinkList) malloc(sizeof(LNode));
        p2 = p->next;
        p->next = p->next->next;
        free(p2);
    }
    return OK;
    /********** End **********/
}
status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L->next;
	printf("\n-----------all elements -----------------------\n");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
	printf("\n------------------ end ------------------------\n");
    return OK;

    /********** End **********/
}
status SaveList(LinkList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 1 *********/
    if(L==NULL)
        return INFEASIBLE;
    FILE *fp=fopen(FileName,"w");
    LNode *p;
    p = L->next;
	while(p)
    {
		fprintf(fp,"%d ",p->data);
        p = p->next;
    }
	fclose(fp);
    return OK;
    /********** End 1 **********/
}
status LoadList(char FileName[],char name[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 2 *********/
	if(strcmp(FileName,"D:/data/1.dat")!=0 && strcmp(FileName,"D:/data/2.dat")!=0)
		return ERROR;
    lists.elem[lists.length].L = (LinkList)malloc(sizeof(LNode));
	strcpy(lists.elem[lists.length].name, name);
	FILE *fp=fopen(FileName,"r");
    int a;
    LinkList L1, p;
    p = lists.elem[lists.length].L;
    while(fscanf(fp,"%d ",&a)==1)
	{
		L1=(LinkList) malloc(sizeof(LNode));
        p->next = L1;
        L1->data = a;
        L1->next = NULL;
        p=L1;
	}
    fclose(fp);
    return OK;
    /********** End 2 **********/
}
status reverseList(LinkList &L)
{
	// Lp Aq  Bm
	if(L->next==NULL)
		return ERROR;
	LNode *p, *q, *m;
	p = L;
	q = p->next;
	L->next = NULL;
	if(q!=NULL)
	{
		m = q->next;
		p = NULL;
		while(m)
		{
			q->next = p;
			p = q;
			q = m;
			m = q->next;
		}
		L->next = q;
		q->next = p;
	}
	else
		L->next = p;
	return OK;
}
status RemoveNthFromEnd(LinkList &L,int n)
{
	int i = ListLength(L)- n+1;
	if(i<=0||i>ListLength(L))
        return ERROR;
    else
    {
        LNode *p;
        p = L;
        while(--i)
            p = p->next;
        LinkList p2=(LinkList) malloc(sizeof(LNode));
        p2 = p->next;
        p->next = p->next->next;
        free(p2);
    }
    return OK;
}
status sortList(LinkList &L)
{
	if(L->next==NULL)
		return ERROR;
	LNode *p, *q;// 1 -2 -8 0
	for (p = L->next; p->next;p=p->next)
	{
		for (q = p->next; q;q=q->next)
		{
			if(p->data>q->data)
			{
				p->data = p->data + q->data;
				q->data = p->data - q->data;
				p->data = p->data - q->data;
			}
		}
	}
	return OK;
}
status check(char name[])
{
	for (int i = 0; i < lists.length;i++)
	{
		if(strcmp(name,lists.elem[i].name)==0)
			return i;
	}
	return -1;
}
status addlist(char name[])
{
	lists.elem[lists.length].L=(LinkList)malloc(sizeof(LNode));
    lists.elem[lists.length].L->next = NULL;
	strcpy(lists.elem[lists.length].name,name);
	lists.length++;
	return 0;
}
void My_print(void)
{
       system("cls");
	    printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1.  InitList      7.  LocateElem\n");
	  	printf("    	  2.  DestroyList   8.  PriorElem\n");
	  	printf("    	  3.  ClearList     9.  NextElem\n");
        printf("    	  4.  ListEmpty     10. ListInsert\n");
        printf("    	  5.  ListLength    11. ListDelete\n");
        printf("    	  6.  GetElem       12. ListTraverse\n");
		printf("-------------------------------------------------\n");
        printf("    	  13. reverseList   14.RemoveNthFromEnd\n");
        printf("    	  15. SortList      16.Save_in_file\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
		printf("%d�����Ա��ѳ�ʼ��\n",lists.length);
		for (int i = 0; i < lists.length;i++)
		{
			if(lists.elem[i].L!=NULL)
				printf("%s ", lists.elem[i].name);
		}
		printf("��ѡ����Ĳ���[0~16]:"); 
}