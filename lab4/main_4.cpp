#include"func_4.h"
int main(void)
{
	lists.length = 0;
	lists.listsize = MAXLENGTH;
	for (int i = 0; i <MAXLENGTH ;i++)
        lists.elem[i].T.vertices[i].data.key=-1;
    ALGraph T;
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
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (check(name)!=-1)
					printf("ͼ %s �Ѵ���",name);
				else
				{
                    ALGraph T;
                    VertexType V[21];
                    KeyType VR[100][2];
                    int ans, i = 0, j = 0,key;
                    printf("����ͼ��VertexType V[]\n");
                    do {
                    	scanf("%d %s",&V[i].key,V[i].others);
                    } while (V[i++].key!=-1);
                    printf("����ͼ��keytype VR[]\n");
                    do {
                    	scanf("%d %d",&VR[j][0],&VR[j][1]);
                    } while (VR[j++][0]!=-1);
                    getchar();
                    ans=CreateCraph(T,V,VR);
                    if(ans==ERROR)
						printf("�������\n");
					else{
						lists.elem[lists.length].T=T;
	                	strcpy(lists.elem[lists.length].name,name);
	                	lists.length++;
						printf("ͼ %s �����ɹ�!",name);
					}
				}
                printf("\n���Enter������һ��");
                getchar();
				break;
			}
		case 2:
			{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					int result=DestroyGraph(lists.elem[id].T);
                    lists.elem[id].T.vertices[id].data.key=-1;
                    lists.length--;
                    if(result==OK)
						printf("ͼ %s ���ٳɹ���\n",name);
		   			else 
						printf("ͼ %s �����ڣ�\n",name);
				}
	   			printf("���Enter������һ��");
				getchar();
				break;
				
			}
		case 3:
			{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
                    printf("����Ҫ���ҵĽڵ� v :\n");
                    KeyType v;
                    scanf("%d", &v);
                    getchar();
                    int result=LocateVex(lists.elem[id].T,v);
			   		printf("%d %s\n",lists.elem[id].T.vertices[result].data.key,lists.elem[id].T.vertices[result].data.others);
				}
	            printf("���Enter������һ��");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
                    printf("����Ҫ��ֵ�Ķ���u��Ҫ�޸�value\n");
                    KeyType u;
                    VertexType value;
                    scanf("%d %d %s", &u, &value.key, value.others);
                    getchar();
                    int result=PutVex(lists.elem[id].T,u,value);
					if(result==ERROR)
			   			printf("��ֵ����ʧ��\n");
		   			else 
						for(int i=0;i<lists.elem[id].T.vexnum;i++)
                             printf("%d %s\n",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
				}
	   			printf("���Enter������һ��");
				getchar();
				break;
			}
		case 5:
			{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
                    printf("����Ҫ��ѯ��u�ĵ�һ�ڽӵ�: ");
                    int u;
                    scanf("%d", &u);
                    getchar();
                    int result=FirstAdjVex(lists.elem[id].T,u);
                	if(result!=-1)
                        printf("%d %s\n", lists.elem[id].T.vertices[result].data.key, lists.elem[id].T.vertices[result].data.others);
                    else
                        printf("�޵�һ�ڽӵ�\n");
                }
	            printf("���Enter������һ��");
				getchar();
				break;
			}
		case 6:
		   	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					printf("����Ҫ��ѯ��v�������w��һ���ڽӶ����λ�� v: w: \n");
                    int v,w;
                    scanf("%d %d", &v,&w);
                    getchar();
                    int result=NextAdjVex(lists.elem[id].T,v,w);
                	if(result!=-1)
                        printf("%d %s\n", lists.elem[id].T.vertices[result].data.key, lists.elem[id].T.vertices[result].data.others);
                    else
                        printf("����ʧ��\n");
                }
	            printf("���Enter������һ��");
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					printf("����Ҫ����Ķ���v��key��other \n");
                    VertexType v;
                    scanf("%d %s", &v.key,v.others);
                    getchar();
                    int result=InsertVex(lists.elem[id].T,v);
                	if(result==ERROR)
                        printf("����ʧ��\n");
                    else
                        for(int i=0;i<lists.elem[id].T.vexnum;i++)
                            printf("%d %s\n",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                }
	            printf("���Enter������һ��");
				getchar();
				break;
		  	}
		case 8:
		  	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					printf("����Ҫɾ���Ķ���v\n");
                    KeyType v;
                    scanf("%d", &v);
                    getchar();
                    int result=DeleteVex(lists.elem[id].T,v);
                	if(result==ERROR)
                        printf("ɾ��ʧ��\n");
                    else
                        for(int i=0;i<lists.elem[id].T.vexnum;i++)
                             printf("%d %s\n",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                }
	            printf("���Enter������һ��");
				getchar();
				break;
		 	}
		case 9:
		  	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					printf("����Ҫ����Ļ� v��w\n");
                    KeyType v,w;
                    scanf("%d %d", &v,&w);
                    getchar();
                    int result=InsertArc(lists.elem[id].T,v,w);
                	if(result==ERROR)
                        printf("����ʧ��\n");
                    else
                       	for(int i=0;i<lists.elem[id].T.vexnum;i++)
	                    {
                            ArcNode *p=lists.elem[id].T.vertices[i].firstarc;
                            printf("%d %s",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                            while (p)
                            {
                                printf(" %d",p->adjvex);
                                p=p->nextarc;
                            }
                            printf("\n");
	                    }
                }
	            printf("���Enter������һ��");
				getchar();
				break;
		  	}
		case 10:
		  	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					printf("����Ҫɾ���Ļ� v��w\n");
                    KeyType v,w;
                    scanf("%d %d", &v,&w);
                    getchar();
                    int result=DeleteArc(lists.elem[id].T,v,w);
                	if(result==ERROR)
                        printf("ɾ��ʧ��\n");
                    else
                       	for(int i=0;i<lists.elem[id].T.vexnum;i++)
	                    {
                            ArcNode *p=lists.elem[id].T.vertices[i].firstarc;
                            printf("%d %s",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                            while (p)
                            {
                                printf(" %d",p->adjvex);
                                p=p->nextarc;
                            }
                            printf("\n");
	                    }
                }
	            printf("���Enter������һ��");
				getchar();
				break;
		  	}
		case 11:
		  	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else
                    DFSTraverse(lists.elem[id].T, visit);
                printf("\n���Enter������һ��");
				getchar();
				break;
			}
		case 12:
		  	{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else
		   			BFSTraverse(lists.elem[id].T, visit);
				printf("\n���Enter������һ��");
                getchar();
				break;
		  	}
		case 13:
			{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
                    printf("���붥��V: �;���k:\n");
                    KeyType v;
                    ALGraph G;
                    G = lists.elem[id].T;
                    int k;
                    scanf("%d %d", &v, &k);
                    getchar();
                    int result=VerticesSetLessThanK(G, v, k);
                    int a[20];
                    memset(a, 0, sizeof(a));
                    if(result){
                        printf("����С��k�ĵ���: \n");
                        int pos_v = LocateVex(G, v);
                        printf("%d %s\n", G.vertices[pos_v].data.key, G.vertices[pos_v].data.others);
                        for (int i = 0; less[i]!=-1;i++){
                            if(a[less[i]]==0){
                                printf("%d %s\n", G.vertices[less[i]].data.key, G.vertices[less[i]].data.others);
                                a[less[i]] = 1;
                            }
                        }
                    }
                    else
                        printf("������\n");
                }
				printf("���Enter������һ��");
				getchar();
				break;  
			}
	   	case 14:
			{ 
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
                    printf("�����붥��v��w\n");
                    KeyType v, w;
                    scanf("%d %d", &v, &w);
                    getchar();
                    int result=ShortestPathLength(lists.elem[id].T, v, w);
                    if(result)
                        printf("���·������Ϊ: %d", result);
                    else
                        printf("������");
                }
				printf("\n���Enter������һ��");
				getchar();
				break;
			}
		case 15:
			{
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else
                    printf("��ͨ�����ĸ���Ϊ: %d\n", ConnectedComponentsNums(lists.elem[id].T));
			    printf("���Enter������һ��");
			    getchar();
			    break;
		    }
		case 16:
		{
			int opp;
			do{
			printf("��ѡ��������� 0.�˳�ϵͳ  1. ��ʾ��ͼ�����ļ��� 2. ��ʾ���ļ�����ͼ��");
			scanf("%d", &opp);
			getchar();
			FILE *fp;
			char filename[50];int i;
			if(opp==1){
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("ͼ %s ������\n",name);
				else{
					strcpy(filename, "D:/HUST-DataStructure-Labs/lab4/data/3.dat");
					int result = SaveGraph(lists.elem[id].T, filename);
					if(result==INFEASIBLE)
						printf("ͼΪ��\n");
					else
						printf("�ɹ�����·��Ϊ D:/HUST-DataStructure-Labs/lab4/data/3.dat ���ļ���\n");
				}
				printf("���Enter������һ��");
				getchar();
			}
			else if(opp==2){
				printf("������ͼ�� name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id!=-1) 
					printf("ͼ %s �Ѵ���\n",name);
				else{
					printf("��ѡ���ļ���ַ�� D:/HUST-DataStructure-Labs/lab4/data/1.dat   or  D:/HUST-DataStructure-Labs/lab4/data/2.dat\n");
					printf("�������ļ�·��: ");
					gets(filename);
                    ALGraph G;
                    int result=LoadGraph(G,filename);
					if(result==INFEASIBLE)
						printf("�ļ���ַ����\n");
					else
						printf("�ѽ��ļ����ݶ���ͼ %s ��\n",name);
					lists.elem[lists.length].T=G;
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
