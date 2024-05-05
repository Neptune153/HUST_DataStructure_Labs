#include"def.h"
#include"funct.h"
   
int main(void)
{
	lists.length = 0;
	lists.listsize = 10;
	for (int i = 0; i < 10;i++)
		lists.elem[i].L.elem = NULL;
	SqList L;  int op=1;
	int count = 0;
	while(op)
	{
		My_print();
		scanf("%d", &op);
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
				printf("���������Ա��id(0-9): ");
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
		   	    else 
                    printf("���Ա� %d ����Ϊ %d\n",id,result);
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
			    getchar();getchar();
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
			    getchar();getchar();
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
			getchar();getchar();
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
			   printf("���Ա� %d δ��ʼ����\n",id);
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
			FILE *fp;char filename[50];int i;
			if(opp==1)
			{
				printf("���������Ա��id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				strcpy(filename, "D:/HUST-DataStructure-Labs/lab1/data/3.dat");
				int result = SaveList(lists.elem[id].L, filename);
				if(lists.elem[id].L.elem==NULL)
					printf("���Ա�δ��ʼ��\n");
				else if(result==INFEASIBLE)
					printf("���Ա�Ϊ��\n");
				else
					printf("�ɹ�����·��ΪD:/HUST-DataStructure-Labs/lab1/data/3.dat ���ļ���\n");
				printf("���Enter������һ��");
				getchar();
			}
			else if(opp==2)
			{
				printf("��ѡ���ļ���ַ�� D:/HUST-DataStructure-Labs/lab1/data/1.dat   or  D:/HUST-DataStructure-Labs/lab1/data/2.dat\n");
				printf("input file name: ");
				gets(filename);
				printf("���������Ա��id(0-9): ");
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
