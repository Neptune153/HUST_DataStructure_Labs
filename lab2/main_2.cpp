#include "func_2.h"
int main(void)
{
	lists.length = 0;
	lists.listsize = LISTINCREMENT;
	for (int i = 0; i < LISTINCREMENT;i++)
		lists.elem[i].L= NULL;
	LinkList L;  int op=1;
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
				if (check(name)!=-1)
					printf("���Ա� %s �Ѵ���\n",name);
				else
				{
					addlist(name);
					printf("���Ա� %s �����ɹ�!\n",name);
				}
				printf("���Enter������һ��");getchar();
				break;
			}
		case 2:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					int result=DestroyList(lists.elem[id].L);
		   			if(result==OK)
						printf("���Ա� %s ���ٳɹ���\n",name);
		   			else 
						printf("���Ա� %s �����ڣ�\n",name);
				}
	   			printf("���Enter������һ��");
				getchar();
				break;
				
			}
		case 3:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					int result=ClearList(lists.elem[id].L);
			   		printf("���Ա� %s ��ճɹ���\n",name);
				}
	            printf("���Enter������һ��");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
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
				scanf("%s", name);
				getchar();
				int id=check(name);if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					int result=ListLength(lists.elem[id].L);
                	printf("���Ա� %s ����Ϊ %d\n",name,result);
				}
	            printf("���Enter������һ��");
				getchar();
				break;
			}
		case 6:
		   	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{				
					int i = 0,e;
	        		printf("���������ȡ�ĵ�i��Ԫ��: ");
		   			scanf("%d", &i);
					getchar();
					int result=GetElem(lists.elem[id].L,i,e);
		   			if (result!=OK)
			   			printf("��ȡʧ��\n");
		   			else 
						printf("�� %d ��Ԫ���� %d\n", i, e);
				}
	        	printf("���Enter������һ��");
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
			    	printf("����������ҵ�Ԫ��e�Ĵ�С: ");
			    	int e1;
			    	scanf("%d", &e1);
					getchar();
					int result = LocateElem(lists.elem[id].L, e1);
			    	if(result==0)
				    	printf("���в�����Ԫ��%d\n", e1);
		        	else
			        	printf("%d �������: %d\n", e1, result);
				}
			    printf("���Enter������һ��");
			    getchar();
			    break;
		  	}
		case 8:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
			    	printf("����������ҵ�Ԫ��e��ǰ��: ");
			    	int e2=0, pre=0;
			    	scanf("%d", &e2);
					getchar();
					int result =PriorElem(lists.elem[id].L,e2,pre);
			    	if(result==ERROR)
				    	printf("%d��ǰ��������\n",e2);
		   	    	else
			        	printf("%d ��ǰ����: %d\n", e2, pre);
				}
			    printf("���Enter������һ��");
			    getchar();
			    break;
		 	}
		case 9:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
	        		printf("����������ҵ�Ԫ��e�ĺ��: ");
					int e=0,next=0;
					scanf("%d", &e);getchar();
					int result =NextElem(lists.elem[id].L,e,next);
					if(result==ERROR)
						printf("%d�ĺ�̲�����\n",e);
		   			else
			   			printf("%d �ĺ����: %d\n", e, next);
				}
				printf("���Enter������һ��");
				getchar();
				break;
		  	}
		case 10:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					printf("������������Ԫ��e��λ��i:  ");
					int i, e;
					scanf("%d %d", &e, &i);getchar();
					int result = ListInsert(lists.elem[id].L, i, e);
		   			if(result==ERROR)
			   			printf("����λ�ô���\n");
		   			else
			   			printf("��������ɹ�\n");
				}
				printf("���Enter������һ��");
				getchar();
				break;
		  	}
		case 11:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					printf("��������ɾ����Ԫ�ص�λ��i:  ");
					int i, e;
					scanf("%d",&i);getchar();
					int result = ListDelete(lists.elem[id].L, i, e);
					if (result == ERROR)
				 		printf("ɾ��λ�ô���\n");
					else
				 		printf("ɾ�������ɹ���ɾ����Ԫ���� %d\n",e);
				}
				printf("���Enter������һ��");
				getchar();
				break;
			}
		case 12:
		  	{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else
		   			ListTraverse(lists.elem[id].L);
				printf("���Enter������һ��");
				getchar();
				break;
		  	}
		case 13:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					int result=reverseList(lists.elem[id].L);
					if(result==ERROR)
						printf("���Ա�Ϊ�ձ�\n");
					printf("���Ա�ת�ɹ�\n");
					ListTraverse(lists.elem[id].L);
				}		
				printf("���Enter������һ��");
				getchar();
				break;
			}
	   	case 14:
			{ 
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					int n;
					printf("������Ҫɾ���ĵ����� n ��Ԫ��n:\n");
					scanf("%d", &n);
					getchar();
					int result=RemoveNthFromEnd(lists.elem[id].L,n);
					if(result==ERROR)
			   			printf("ɾ��λ�ô���\n");
					else
						printf("ɾ���ɹ�\n");
				}
				printf("���Enter������һ��");
				getchar();
				break;
			}
		case 15:
			{
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					sortList(lists.elem[id].L);
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
			do{
			printf("��ѡ��������� 0.�˳�ϵͳ  1. ��ʾ�����Ա�����ļ��� 2. ��ʾ���ļ��������Ա�");
			scanf("%d", &opp);
			getchar();
			FILE *fp;char filename[50];int i;
			if(opp==1){
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("���Ա� %s ������\n",name);
				else{
					strcpy(filename, "D:/HUST-DataStructure-Labs/lab2/data/3.dat");
					int result = SaveList(lists.elem[id].L, filename);
					if(result==INFEASIBLE)
						printf("���Ա�Ϊ��\n");
					else
						printf("�ɹ�����·��Ϊ D:/HUST-DataStructure-Labs/lab2/data/3.dat ���ļ���\n");
				}
				printf("���Enter������һ��");
				getchar();
			}
			else if(opp==2){
				printf("���������Ա�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id!=-1) 
					printf("���Ա� %s �Ѵ���\n",name);
				else{
					printf("��ѡ���ļ���ַ�� D:/HUST-DataStructure-Labs/lab2/data/1.dat   or  D:/HUST-DataStructure-Labs/lab2/data/2.dat\n");
					printf("�������ļ�·��: ");
					gets(filename);
					int result=LoadList(filename,name);
					if(result==INFEASIBLE)
						printf("�ļ���ַ����\n");
					else
						printf("�ѽ��ļ����ݶ������Ա� %s ��\n",name);
					ListTraverse(lists.elem[lists.length].L);
					lists.length++;
				}
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

