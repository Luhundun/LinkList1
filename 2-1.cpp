#include<stdio.h>
#include<stdlib.h>
#define listinitsize 100
#define listincrement 10
typedef int ElemType;  //顺序表中存放的是整数       
typedef struct 
{
    ElemType *elem;        //存储空间基址                                     
    int length;             //当前长度                                     
    int listsize;           //当前分配的存储容量
}SqList;


void PrintList(SqList L)     // 输出顺序表
{
	for(int i=0;i<L.length;i++)
	{
        printf("%d   ",L.elem[i]);
	}
	printf("\n");
}

void InitList(SqList  &L, int n)   //建立一个表长为n的顺序表
{
	L.elem=(ElemType*)malloc(listinitsize*sizeof(ElemType));
	if(!L.elem) exit(-2);
	L.length=n;
	L.listsize=listinitsize;
	for(int i=0;i<n;i++)
	{
		L.elem[i]=i+1;
	}
	printf("The first:\n");
	PrintList(L);
}
void ListInsert(SqList &L, int i, ElemType e)   //在顺序表中第i个位置插入元素函数e
{
	if (i<1||i>L.length+1) 
	{
		printf("ERROR!");
		exit(-2);
	}
	if (L.length>=L.listsize)
	{
		printf("FULL!");
		exit(-2);
	}
	L.length++;
	for(int k=L.length-1;k>=i;k--)
	    L.elem[k]=L.elem[k-1];
	L.elem[k]=e;
	printf("The second:%d is added\n",e);
	PrintList(L);
}

void ListDelete(SqList&L, int i, ElemType &e) //删除顺序表L的第i个数据元素，并用e返回其值。
{
	if ((i < 1) || (i > L.length)) {printf("ERROR!");exit(-2);}
	L.length--;
	e=L.elem[i-1];
	for(int k=i-1;k<L.length;k++)
	    L.elem[k]=L.elem[k+1];
	printf("The third:\n");
	PrintList(L);
}

int Locate(SqList L, ElemType e)   
//若顺序表L中存在数据元素e，则返回e在顺序表L中第一次出现的位序;否则返回0.
{
	int x=0;
	for(int i=0;i<L.length;i++)
	{
        if(L.elem[i]==e)
		{
			x=i+1;
			return x;
		}
	}
	return 0;
}

int ListLength(SqList L) //求顺序表L的表长
{
	return L.length;
}

void main()
{
    SqList L;
	int x,a1,a2,a3,a4;
	InitList(L,10);

	printf("Please insert a num,enter the location and value:");
	scanf("%d%d",&a1,&a2);   ListInsert(L,a1,a2);

	printf("Please delete a num,enter the location:");
	scanf("%d",&a3);ListDelete(L,a3,x);

	printf("Please enter a number to return the location:");
	scanf("%d",&a4);
	if(Locate(L,a4))
		printf("%d locates at %d\n",a4,Locate(L,a4));
	else printf("Do not exist\n");

	printf("The length is %d\n",ListLength(L));
}
