#include"funct_1.h"

int main(void)
{
	lists.length = 0;
	lists.listsize = 10;
	for (int i = 0; i < 10;i++)
		lists.elem[i].L.elem = NULL;
	int op=1;
	SqList L;
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
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (LocateList(lists, name))
					printf("���Ա� %s �Ѵ���\n",name);
				else
				{
					AddList(lists, name);
					printf("���Ա� %s �����ɹ�!\n",name);
				}
				printf("���Enter������һ��");getchar();
				break;
			}
		case 2:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				int result=DestroyList(lists.elem[id].L);
		   		if(result==OK)
					printf("���Ա� %s ���ٳɹ���\n",name);
		   		else 
					printf("���Ա� %s �����ڣ�\n",name);
	   			printf("���Enter������һ��");
				getchar();
				break;
			}
		case 3:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				int result=ClearList(lists.elem[id].L);
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
		   		if(result==OK)
			   		printf("���Ա� %s ��ճɹ���\n",name);
	            printf("���Enter������һ��");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
					int result=ListEmpty(lists.elem[id].L);
					if(result==TRUE)
			   			printf("���Ա� %s �ǿյģ�\n",name);
		   			else 
						printf("���Ա� %s �ǿգ�\n",name);
				}
	   			printf("���Enter������һ��");
				getchar();
				break;
			}
		case 5:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				int result=ListLength(lists.elem[id].L);
		   	    if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
		   	    else 
                    printf("���Ա� %s ����Ϊ %d\n",name,result);
	            printf("���Enter������һ��");
				getchar();
			break;
			}
		case 6:
		   	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
				int i = 0,e;
	        	printf("���������ȡ�ĵ�i��Ԫ��: ");
		   		scanf("%d", &i);
				int result=GetElem(lists.elem[id].L,i,e);
		   		if (result!=OK)
			   	printf("��ȡʧ��\n");
		   		else 
				printf("�� %d ��Ԫ���� %d\n", i, e);
				}
	        	printf("���Enter������һ��");
				getchar();
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
			    printf("����������ҵ�Ԫ��e�Ĵ�С: ");
			    int e1;
			    scanf("%d", &e1);
			    int result = LocateElem(lists.elem[id].L, e1);
			    if(result==0)
				    printf("���в�����Ԫ��%d\n", e1);
		        else
			        printf("%d �������: %d\n", e1, result);
				}
			    printf("���Enter������һ��");
			    getchar();getchar();
			    break;
		  	}
		case 8:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
			    printf("����������ҵ�Ԫ��e��ǰ��: ");
			    int e2=0, pre=0;
			    scanf("%d", &e2);
			    int result =PriorElem(lists.elem[id].L,e2,pre);
			    if(result==ERROR)
				    printf("%d��ǰ��������\n",e2);
		   	    else
			        printf("%d ��ǰ����: %d\n", e2, pre);
				}
			    printf("���Enter������һ��");
			    getchar();getchar();
			    break;
		 	}
		case 9:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
	        printf("����������ҵ�Ԫ��e�ĺ��: ");
			int e=0,next=0;
			scanf("%d", &e);
			int result =NextElem(lists.elem[id].L,e,next);
			if(result==ERROR)
				printf("%d�ĺ�̲�����\n",e);
		   	else
			   printf("%d �ĺ����: %d\n", e, next);
				}
			printf("���Enter������һ��");
			getchar();getchar();
			break;
		  	}
		case 10:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
				printf("������������Ԫ��e��λ��i:  ");
				int i, e;
				scanf("%d %d", &e, &i);
				int result = ListInsert(lists.elem[id].L, i, e);
		   		if(result==ERROR)
			   printf("����λ�ô���\n");
		   		else
			   printf("��������ɹ�\n");
				}
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
		  	}
		case 11:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
			printf("��������ɾ����Ԫ�ص�λ��i:  ");
			int i, e;
			scanf("%d",&i);
			int result = ListDelete(lists.elem[id].L, i, e);
			if (result == ERROR)
				 printf("ɾ��λ�ô���\n");
			else
				 printf("ɾ�������ɹ���ɾ����Ԫ���� %d\n",e);
				}
			printf("���Enter������һ��");
			getchar();
			getchar();
			break;
			}
		case 12:
		  	{
			printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
		   	int result=ListTraverse(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("���Ա� %s δ��ʼ����\n",name);
			printf("���Enter������һ��");
			getchar();
			break;
		  	}
		case 13:
		{
			printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
			int result=MaxSubArray(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("���Ա� %s �ǿձ�\n",name);
			else
				printf("���������������Ϊ��%d\n", result);
				}
			printf("���Enter������һ��");
			getchar();
			break;
		}
	   	case 14:
		{
			printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("���Ա� %s ������\n",name);
				else
				{
			int K;
			printf("����������� K ��ֵ��");
			scanf("%d", &K);
			getchar();
			int result=SubArrayNum(lists.elem[id].L,K);
			if(result==ERROR)

			   printf("�����ڣ�\n");
			else
				printf("��Ϊ %d ���������� %d ��\n", K, result);
				}
			printf("���Enter������һ��");
			getchar();
			break;
		}
		case 15:
		{
			printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
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
			printf("%d", lists.length);
			scanf("%d", &opp);
			getchar();
			FILE *fp;char filename[50];int i;
			if(opp==1)
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				strcpy(filename, "D:/HUST-DataStructure-Labs/lab1/data/3.dat");
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
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (LocateList(lists, name)==0)
				{
					printf("��ѡ���ļ���ַ�� D:/HUST-DataStructure-Labs/lab1/data/1.dat   or  D:/HUST-DataStructure-Labs/lab1/data/2.dat\n");
					printf("�������ļ�·��: ");
					gets(filename);
					lists.elem[lists.length].L.elem = NULL;
					L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
					L.length=0;
					L.listsize=LIST_INIT_SIZE;
					strcpy(lists.elem[lists.length].name,name);
					int result=LoadList(lists.elem[lists.length].L, filename);
					ListTraverse(lists.elem[lists.length].L);
					if(result==ERROR)
						printf("�ļ���ַ����\n");
					else
						printf("�ѽ��ļ����ݶ������Ա� %s ��\n",name);
				}
				else 
					printf("���Ա� %s �ѳ�ʼ��\n",name);
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

