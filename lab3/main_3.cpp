#include"func_3.h"
int main(void)
{
	lists.length = 0;
	lists.listsize = LISTINCREMENT;
	for (int i = 0; i < LISTINCREMENT;i++)
		lists.elem[i].T= NULL;
    BiTree T;
    TElemType e;
	int op=1;
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
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (check(name)!=-1)
					printf("������ %s �Ѵ���",name);
				else
				{
                    BiTree T;
                    TElemType e;
					DEF definition[100];
					int ans,i=0,key;
					printf("��definition���������T\n");
                    do {
                    	scanf("%d %d %s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
                    } while (definition[i++].pos);
                    ans=CreateBiTree(T,definition);
                    lists.elem[lists.length].T=T;
	                strcpy(lists.elem[lists.length].name,name);
	                lists.length++;
					printf("������ %s �����ɹ�!",name);
                    PreOrderTraverse(T, visit);
                    InOrderTraverse(T, visit);
				}
                getchar();
                printf("\n���Enter������һ��");getchar();
				break;
			}
		case 2:
			{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					int result=DestroyBiTree(lists.elem[id].T);
                    lists.elem[id].T = NULL;
                    lists.length--;
                    if(result==OK)
						printf("������ %s ���ٳɹ���\n",name);
		   			else 
						printf("������ %s �����ڣ�\n",name);
				}
	   			printf("���Enter������һ��");
				getchar();
				break;
				
			}
		case 3:
			{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					int result=ClearBiTree(lists.elem[id].T);
			   		printf("������ %s ��ճɹ���\n",name);
				}
	            printf("���Enter������һ��");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					int result=BiTreeEmpty(lists.elem[id].T);
					if(result==ERROR)
			   			printf("������ %s �ǿյģ�\n",name);
		   			else 
						printf("������ %s �ǿգ�\n",name);
				}
	   			printf("���Enter������һ��");
				getchar();
				break;
			}
		case 5:
			{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					int result=BiTreeDepth(lists.elem[id].T);
                	printf("������ %s ���Ϊ %d\n",name,result);
				}
	            printf("���Enter������һ��");
				getchar();
				break;
			}
		case 6:
		   	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					KeyType e;
					printf("����������ҵĽڵ��key: ");
		   			scanf("%d", &e);
					getchar();
					BiTNode *p=LocateNode(lists.elem[id].T,e);
					if(p) printf("%d,%s",p->data.key,p->data.others);
					else printf("�����ڸý��");
				}
	        	printf("\n���Enter������һ��");
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
			    	printf("�������븳ֵ�Ľڵ��e����value:  ");
					TElemType value;
					int e1;
					scanf("%d", &e1);
					getchar();
					scanf("%d %s", &value.key,value.others);
					getchar();
					int result = Assign(lists.elem[id].T, e1,value);
			    	if(result==ERROR)
				    	printf("��ֵ����ʧ��\n");
		        	else
			        	printf("��ֵ�ɹ�\n");
				}
				LevelOrderTraverse(lists.elem[id].T,visit);
			    printf("\n���Enter������һ��");
			    getchar();
			    break;
		  	}
		case 8:
		  	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
			    	printf("����������ҵĽڵ�e���ֵܽڵ�: ");
					int e;
					scanf("%d", &e);
					getchar();
					BiTree result =GetSibling(lists.elem[id].T,e);
			    	if(result==NULL)
				    	printf("%d���ֵܽڵ㲻����\n",e);
		   	    	else
			        	printf("%d ���ֵܽڵ���: %d %s\n", e,result->data.key,result->data.others);
				}
			    printf("���Enter������һ��");
			    getchar();
			    break;
		 	}
		case 9:
		  	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
	        		printf("�����������Ľڵ��λ�� e LR �Լ�Ҫ����Ľڵ�c��key��others: ");
					int e,LR;
					TElemType value;
					scanf("%d %d %d %s", &e, &LR, &value.key, value.others);
					getchar();
					int result =InsertNode(lists.elem[id].T,e,LR,value);
					if(result==ERROR)
						printf("��ֵ����ʧ��\n");
		   			else{
			   			printf("��ֵ�����ɹ�\n");
						LevelOrderTraverse(lists.elem[id].T,visit);
					}
				}
				printf("\n���Enter������һ��");
				getchar();
				break;
		  	}
		case 10:
		  	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					printf("��������ɾ���Ľڵ�Ĺؼ���e:  ");
					KeyType e;
					scanf("%d", &e);getchar();
					int result = DeleteNode(lists.elem[id].T,e);
		   			if(result==ERROR)
			   			printf("ɾ������\n");
		   			else{
			   			printf("ɾ���ɹ�\n");
						LevelOrderTraverse(lists.elem[id].T,visit);
					}
				}
				printf("\n���Enter������һ��");
				getchar();
				break;
		  	}
		case 11:
		  	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else
					PreOrderTraverse(lists.elem[id].T, visit);
				printf("\n���Enter������һ��");
				getchar();
				break;
			}
		case 12:
		  	{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else
		   			InOrderTraverse(lists.elem[id].T,visit);
				printf("\n���Enter������һ��");
				getchar();
				break;
		  	}
		case 13:
			{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					printf("\n�������--------------------------\n");
		   			PostOrderTraverse(lists.elem[id].T,visit);
				}
				printf("\n���Enter������һ��");
				getchar();
				break;
			}
	   	case 14:
			{ 
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else
		   			LevelOrderTraverse(lists.elem[id].T,visit);
				printf("\n���Enter������һ��");
				getchar();
				break;
			}
		case 15:
			{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					int result = MaxPathSum(lists.elem[id].T);
					printf("���·����Ϊ��%d\n", result);
				}
			printf("���Enter������һ��");
			getchar();
			break;
		    }
		case 16:
			{
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					printf("�����������ڵ�Ĺؼ���e1 e2 : ");
					KeyType e1, e2;
					scanf("%d %d", &e1, &e2);
					getchar();
					BiTree result = LowestCommonAncestor(lists.elem[id].T,e1,e2);
					printf("����Ĺ�������Ϊ��%d %s\n", result->data.key,result->data.others);
				}
				printf("���Enter������һ��");
				getchar();
				break;
			}
		case 17:
		    {
			    printf("������������� name: ");
			    char name[10];
			    scanf("%s", name);
			    getchar();
			    int id=check(name);
			    if(id==-1) 
				    printf("������ %s ������\n",name);
			    else{
				    InvertTree(lists.elem[id].T);
				    printf("��������ת�ɹ�\n");
					LevelOrderTraverse(lists.elem[id].T,visit);
			    }
			    printf("���Enter������һ��");
			    getchar();
			    break;
		    }
		case 18:
		{
			int opp;
			do{
			printf("��ѡ��������� 0.�˳�ϵͳ  1. ��ʾ�������������ļ��� 2. ��ʾ���ļ������������");
			scanf("%d", &opp);
			getchar();
			FILE *fp;
			char filename[50];int i;
			if(opp==1){
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("������ %s ������\n",name);
				else{
					strcpy(filename, "D:/HUST-DataStructure-Labs/lab3/data/3.dat");
					int result = SaveBiTree(lists.elem[id].T, filename);
					if(result==INFEASIBLE)
						printf("������Ϊ��\n");
					else
						printf("�ɹ�����·��Ϊ D:/HUST-DataStructure-Labs/lab3/data/3.dat ���ļ���\n");
				}
				printf("���Enter������һ��");
				getchar();
			}
			else if(opp==2){
				printf("������������� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id!=-1) 
					printf("������ %s �Ѵ���\n",name);
				else{
					printf("��ѡ���ļ���ַ�� D:/HUST-DataStructure-Labs/lab3/data/1.dat   or  D:/HUST-DataStructure-Labs/lab3/data/2.dat");
					printf("�������ļ�·��: ");
					gets(filename);
					T = NULL;
					int result=LoadBiTree(T,filename);
					if(result==INFEASIBLE)
						printf("�ļ���ַ����\n");
					else
						printf("�ѽ��ļ����ݶ�������� %s ��\n",name);
					LevelOrderTraverse(T, visit);
					lists.elem[lists.length].T=T;
	                strcpy(lists.elem[lists.length].name,name);
					lists.length++;
				}
				printf("\n���Enter������һ��");
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
