#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
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
int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem!=NULL)
		return INFEASIBLE;
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
	/********** End **********/
}
status DestroyList(SqList& L)
// ������Ա�L���ڣ��п����Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	free(L.elem);
	L.elem = NULL;
	return OK;
	/********** End **********/
}
status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
  	L.length = 0;
	return OK;
	/********** End **********/
}
status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	else if(L.length==0)
		return TRUE;
	else 
		return FALSE;
	/********** End **********/
}
status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	return L.length;

	/********** End **********/
}
status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	if(i>L.length||i<=0)
		return ERROR;
	e=L.elem[i-1];
	return OK;
	/********** End **********/
}
status LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	for (int i = 0; i<L.length; i++)
	{
		if(L.elem[i]==e)
		{
			e = i+1;
			return i+1;
		}
	}
	return 0;

	/********** End **********/
}
status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	if(L.elem[0]==e)
		return ERROR;
	for (int i = 1; i < L.length;i++)
	{
		if(e==L.elem[i])
		{
			pre = L.elem[i - 1];
			return OK;
		}
	}
	return ERROR;
	/********** End **********/
}
status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	for (int i = 0; i <=L.length-2;i++)
	{
		if(e==L.elem[i])
		{
			next = L.elem[i+1];
			return OK;
		}
	}
	return ERROR;
}
status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	else if(i<=0||i>L.length+1)
		return ERROR;
	else if(L.length==L.listsize)
	{
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if(newbase==NULL)
			return OVERFLOW;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	for (int j = L.length - 1; j >= i - 1;j--) // �����ƶ�
		L.elem[j + 1] = L.elem[j];
	L.elem[i-1] = e;//����
	L.length++;
	return OK;
	/********** End **********/
}
status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	if(i<=0||i>L.length)
		return ERROR;
	else if(i==L.length)
		e=L.elem[i-1];
	else 
	{
        e=L.elem[i-1];
		for (int a = 0; a< L.length-i+1;a++)
		{
			L.elem[i -1+a]=L.elem[i + a] ;
		}
	}
	L.length--;
	return OK;
    /********** End **********/
}
status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	printf("\n-----------all elements -----------------------\n");
	for (int i = 0; i < L.length;i++)
		printf("%d ", L.elem[i]);
	printf("\n------------------ end ------------------------\n");
	return OK;
	/********** End **********/
}
status SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;	
 	FILE *fp=fopen(FileName,"w");
	if(fp==NULL)
		printf("�ļ���ʧ��");
	else 
		printf("�ɹ����ļ�");
	for (int i =0; i < L.length;i++)
		fprintf(fp,"%d ",L.elem[i]);
	fclose(fp);
	return OK;
	/********** End **********/
}
status LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	if(strcmp(FileName,"D:/data/1.dat")!=0 && strcmp(FileName,"D:/data/2.dat")!=0)
		return ERROR;
	if(L.elem!=NULL)
		return INFEASIBLE;
	L.listsize = LIST_INIT_SIZE;
	L.length = 0;
	L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	FILE *fp=fopen(FileName,"r");
	int a, i = 0;
	while(fscanf(fp,"%d ",&a)==1)
	{
		L.elem[i++]=a;
		L.length++;
	}
	fclose(fp);
	return OK;
	/********** End **********/
}
status AddList(LISTS &Lists,char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	Lists.elem[Lists.length].L.elem = NULL;
	InitList(Lists.elem[Lists.length].L);
	strcpy(Lists.elem[Lists.length].name,ListName);
	Lists.length++;
	return 0;
	/********** End **********/
}
status RemoveList(LISTS &Lists,char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
     for (int i = 0; i < Lists.length;i++)
    {
        if(strcmp(ListName,Lists.elem[i].name)==0)
        {
            
            for(int t=i;t<Lists.length-1;t++)
            {
               Lists.elem[t]=Lists.elem[t+1];
               strcpy(Lists.elem[t].name, Lists.elem[t+1].name);
            }
            Lists.length--;
            return OK;
        }
    }
	return INFEASIBLE;
}
int LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
	for (int i = 0; i < Lists.length;i++)
	{
		if(strcmp(ListName,Lists.elem[i].name)==0)
			return i+1;
	}
	return 0;
	/********** End **********/
}
status MaxSubArray(SqList L)
{
	if(L.length==0)
		return INFEASIBLE;
    int res=-999999,sum=0;
    for(int i=0;i<L.length;i++)
	{
        if(sum<0){
            sum=L.elem[i];
        }else{
            sum+=L.elem[i];
        }
        res=res>sum?res:sum;
    }
    return res;
}
status SubArrayNum(SqList L,int K)
{
	if(L.elem==NULL)
		return INFEASIBLE;
	else if(L.length==0)
		return ERROR;
	else 
	{
		int sum = 0, count = 0;
		for (int i = 0; i < L.length;i++)
		{
			for (int j = i; j < L.length;j++)
			{
				sum += L.elem[i];
				if(sum==K)
					count++;
			}
		}
		return count;
	}
}



int main(void)
{
	LISTS lists;
	lists.length = 0;
	lists.listsize = 10;
	for (int i = 0; i < 10;i++)
		lists.elem[i].L.elem = NULL;
	SqList L;  int op=1;
	int count = 0;
	while(op)
	{
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
        printf("    	  13. MaxSubArray   14.SubArrayNum\n");
        printf("    	  15. SortList      16.Save_in_file\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
		printf("���Ա�");
		for (int i = 0; i < 10;i++)
		{
			if(lists.elem[i].L.elem!=NULL)
				printf("%d ", i);
		}
		printf("�ѳ�ʼ��\n");
		printf("��ѡ����Ĳ���[0~16]:"); 
		}              
	   	scanf("%d",&op);
		getchar();
		switch(op)
	   	{
		case 0:
			break;
		case 1:
			{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=InitList(lists.elem[id].L);
				if (result ==INFEASIBLE)
					printf("���Ա� %d �Ѵ��ڣ�\n",id);
				else
					printf("���Ա� %d �����ɹ�!\n",id);
	            printf("���Enter������һ��");getchar();
				break;
			}
		case 2:
			{
				printf("������Ҫ���ٵ����Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=DestroyList(lists.elem[id].L);
		   		if(result==OK)
		            printf("���Ա� %d ���ٳɹ���\n",id);
		   		else 
					printf("���Ա� %d �����ڣ�\n",id);
	   			printf("���Enter������һ��");
				getchar();
				break;
			}
		case 3:
			{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=ClearList(lists.elem[id].L);
		   		if(result==OK)
			   printf("���Ա� %d ��ճɹ���\n",id);
		   		else printf("���Ա� %d �����ڣ�\n",id);
	            printf("���Enter������һ��");
				getchar();
			 
			break;
			}
		case 4:
		   	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=ListEmpty(lists.elem[id].L);
				if(result==TRUE)
			   		printf("���Ա� %d �ǿյģ�\n",id);
		   		else 
					printf("���Ա� %d �ǿգ�\n",id);
	   			printf("���Enter������һ��");
				getchar();
				break;
			}
		case 5:
			{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=ListLength(lists.elem[id].L);
		   	if(result==INFEASIBLE)
			   	printf("���Ա� %d �����ڣ�\n",id);
		   	else printf("���Ա� %d ����Ϊ %d\n",id,result);
	            printf("���Enter������һ��");
				getchar();
			break;
			}
		case 6:
		   	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int i = 0,e;
	        	printf("���������ȡ�ĵ�i��Ԫ��: ");
		   		scanf("%d", &i);
				int result=GetElem(lists.elem[id].L,i,e);
		   		if (result!=OK)
			   	printf("��ȡʧ��\n");
		   		else 
				printf("�� %d ��Ԫ���� %d\n", i, e);
	        	printf("���Enter������һ��");
				getchar();
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("����������ҵ�Ԫ��e�Ĵ�С: ");
			int e1;
			scanf("%d", &e1);
			int result = LocateElem(lists.elem[id].L, e1);
			if(result==0)
				printf("���в�����Ԫ��%d\n", e1);
		   else if(result==INFEASIBLE)
			   printf("���Ա� %d ������\n",id);
		   else
			   printf("%d �������: %d\n", e1, result);
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
		  	}
		case 8:
		  	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("����������ҵ�Ԫ��e��ǰ��: ");
			int e2=0, pre=0;
			scanf("%d", &e2);
			int result =PriorElem(lists.elem[id].L,e2,pre);
			if(result==ERROR)
				printf("%d��ǰ��������\n",e2);
		   	else if(result==INFEASIBLE)
			   printf("���Ա� %d ������",id);
		   	else
			   printf("%d ��ǰ����: %d\n", e2, pre);
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
		 	}
		case 9:
		  	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
	        printf("����������ҵ�Ԫ��e�ĺ��: ");
			int e=0,next=0;
			scanf("%d", &e);
			int result =NextElem(lists.elem[id].L,e,next);
			if(result==ERROR)
				printf("%d�ĺ�̲�����\n",e);
		   	else if(result==INFEASIBLE)
			   printf("���Ա� %d ������\n",id);
		   	else
			   printf("%d �ĺ����: %d\n", e, next);
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
		  	}
		case 10:
		  	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("������������Ԫ��e��λ��i:  ");
			int i, e;
			scanf("%d %d", &e, &i);
			int result = ListInsert(lists.elem[id].L, i, e);
			if(result==INFEASIBLE)
			   printf("���Ա� %d ������\n",id);
		   	else if(result==ERROR)
			   printf("����λ�ô���\n");
		   	else
			   printf("��������ɹ�\n");
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
		  	}
		case 11:
		  	{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("��������ɾ����Ԫ�ص�λ��i:  ");
			int i, e;
			scanf("%d",&i);
			int result = ListDelete(lists.elem[id].L, i, e);
			if (result == INFEASIBLE)
				 printf("���Ա� %d ������\n",id);
			else if (result == ERROR)
				 printf("ɾ��λ�ô���\n");
			else
				 printf("ɾ�������ɹ���ɾ����Ԫ���� %d\n",e);
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
			}
		case 12:
		  	{
			printf("���������Ա��id(0-9): ");
			int id;
			scanf("%d", &id);
			getchar();
		   	int result=ListTraverse(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("���Ա� %d �ǿձ�\n",id);
			printf("���Enter������һ��");
			getchar();
			break;
		  	}
		case 13:
		{
			printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			int result=MaxSubArray(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("���Ա� %d �ǿձ�\n",id);
			else
				printf("���������������Ϊ��%d\n", result);
			printf("���Enter������һ��");
			getchar();
			break;
		}
	   	case 14:
		{
			printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			int K;
			printf("����������� K ��ֵ��");
			scanf("%d", &K);
			getchar();
			int result=SubArrayNum(lists.elem[id].L,K);
			if(result==ERROR)
			   printf("���Ա��ǿձ�\n");
			else if(result==INFEASIBLE)
				printf("���Ա�����");
			else
				printf("��Ϊ %d ���������� %d ��\n", K, result);
			printf("���Enter������һ��");
			getchar();
			break;
		}
		case 15:
		{
			printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			if(lists.elem[id].L.length==0)
			   	printf("���Ա��ǿձ�\n");
			else if(lists.elem[id].L.elem==NULL)
				printf("���Ա�����");
			else
			{
				qsort(lists.elem[id].L.elem,lists.elem[id].L.length,sizeof(ElemType),cmp);
				printf("�ѳɹ���С��������\n");
				ListTraverse(lists.elem[id].L);
			}
			printf("���Enter������һ��");
			getchar();
			break;
		}
		case 16:
		{
			int opp;
			do
			{
			printf("��ѡ��������� 0.�˳�ϵͳ  1. ��ʾ�����Ա�����ļ��� 2. ��ʾ���ļ��������Ա�");
			scanf("%d", &opp);
			getchar();
			FILE *fp;char filename[30];int i;
			if(opp==1)
			{
				printf("������һ�����Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				strcpy(filename, "D:/data/3.dat");
				int result = SaveList(lists.elem[id].L, filename);
				if(lists.elem[id].L.elem==NULL)
					printf("���Ա�δ��ʼ��\n");
				else if(result==INFEASIBLE)
					printf("���Ա�Ϊ��\n");
				else
					printf("�ɹ�����·��Ϊ D:/data/3.dat ���ļ���\n");
				printf("���Enter������һ��");
				getchar();
			}
			else if(opp==2)
			{
				printf("��ѡ���ļ���ַ�� D:/data/1.dat   or  D:/data/2.dat\n");
				printf("input file name: ");
				gets(filename);
				printf("������һ��δ��ʼ�������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=LoadList(lists.elem[id].L, filename);
				if(result==INFEASIBLE)
					printf("���Ա� %d �ѳ�ʼ��\n",id);
				else if(result==ERROR)
					printf("�ļ���ַ����\n");
				else
					printf("�ѽ��ļ����ݶ������Ա� %d ��\n",id);
				printf("���Enter������һ��");
				getchar();
			}
			else
				printf("����������\n");
			} while(opp != 1 && opp != 2);
		}
	}
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	}
}

/*
SqList L={{{'a',1,1.1},{'b',2,2.2},{'c',3,3.3},{'d',4,4.4}}, 4};

int main(intargc, char *argv[])
{
FILE  *fp;char filename[30];int i; 
printf("input file name: ");
scanf("%s",filename);

//д�ļ��ķ���
if ((fp=fopen(filename,"wb"))==NULL)
	{
	printf("File open erroe\n ");
	return 1;
	}
fwrite(L.elem,sizeof(ElemType),L.length,fp);
//������1����д�룬������������ṹ����ͨ�������������������Ԫ��
//��д�뵽�ļ��С�Ҳ������д�������д��ȫ��Ԫ�أ���������������
fclose(fp);
	
//���ļ��ķ���
L.length=0;
if ((fp=fopen(filename,"rb"))==NULL)
	{
	printf("File open erroe\n ");
	 return 1;
	}
while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
L.length++;
//������ļ��������ȡ����Ԫ�ػָ�˳������ڲ�ͬ������ṹ����ͨ����//ȡ������Ԫ�ػָ��ڴ��е�����ṹ��
fclose(fp);
return 0;
}
*/

/*

#include "def.h"
#include "string.h"

#include "stu.h"
int main()
{
SqList L;
FILE *fp;
//char FileName[30];
int f,i=0,j,e;
//strcpy(FileName,"src/step13/list.dat");
scanf("%d",&f);
if (!f)
{
    	L.elem=NULL;
   		j=SaveList(L,"src/step13/list.dat");
   		if (j!=INFEASIBLE) printf("���ܶԲ����ڵ����Ա����д�ļ�������");
    	else 
      {
    		 L.elem=(ElemType *) malloc(sizeof(ElemType));
   			 j=LoadList(L,"src/step13/list.dat");
   			 if (j!=INFEASIBLE) printf("���ܶ��Ѵ��ڵ����Ա���ж��ļ�������");
    	    else printf("INFEASIBLE"); 
    		 free(L.elem);
      }
}
else
     {
        L.elem=(ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length=0;
        L.listsize= LIST_INIT_SIZE;
        scanf("%d",&e);
        while (e)
        {
            L.elem[i++]=e;
            scanf("%d",&e);
        }
        L.length=i;
        j=SaveList(L,"src/step13/list.dat");
   		free(L.elem); 
		L.elem=NULL;
        j=LoadList(L,"src/step13/list.dat");
        printf("%d\n",L.length);
        for(i=0;i<L.length;i++) 
            printf("%d ",L.elem[i]);
     }
return 1;
}
*/