
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
	if(strcmp(FileName,"D:/HUST-DataStructure-Labs/lab1/data/1.dat")!=0 && 
		strcmp(FileName,"D:/HUST-DataStructure-Labs/lab1/data/2.dat")!=0)
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
