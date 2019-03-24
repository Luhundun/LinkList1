#include<stdio.h>
#include<stdlib.h>
#define  ElemType int
typedef  struct  Node
{
    ElemType   data;      // 数据域
    struct Node *next;    // 指针域
}LNode, *LinkList;

void ListPrint(LinkList La)//将单链表La的数据元素从表头到表尾依次显示。
{
	LinkList p=La->next;
	while(p)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
}

void CreatList(LinkList &La,int m)
//依次输入m个数据，并依次建立各个元素结点，逐个插入到链表尾；建立带表头结点的单链表La；
{
	LinkList p,r;
	La=(LinkList)malloc(sizeof(LNode));
	La->next=NULL;
	r=La;
    for(int i=0;i<m;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
	//	scanf("%d",&p->data);
		p->data=i+1;
		p->next=NULL;r->next=p;r=p;
	}
	ListPrint(La);
}

void ListInsert(LinkList &La,int i,ElemType e)//在带头结点的单链表L中第i个数据元素之前插入数据元素e
{
	LinkList p=La,q;
	q=(LinkList)malloc(sizeof(LNode));
	for(int j=1;j<=i&&p;j++,p=p->next);
    if(!p||j>i+1)
	{
		printf("错误！\n");
	}
	else
	{	
		q->data=e;
	    q->next=p->next;
     	p->next=q;
     	ListPrint(La);
	}

}

void ListDelete(LinkList &La, int n, ElemType &e) //删除链表的第n个元素，并用e返回其值。
{
	LinkList p=La,q;
	for(int j=1;j<n&&p;j++,p=p->next);
	if(!p||j>n)
	{
		printf("错误！\n");
		e=0;
	}
	else
	{
     	q=p->next;
	    e=p->next->data;
    	p->next=p->next->next;
	    free(q);
    	ListPrint(La);
	}

}

int Search(LinkList La, ElemType x)//在表中查找是否存在某个元素x，如存在则返回x在表中的位置，否则返回0。
{
	LinkList p=La->next;
	int i=1;
	while(p)
	{
        if(x==p->data)
		{
			return i;
		}
        p=p->next;
	    i++;
	}
	printf("未找到\n");
	return 0;
}

int ListLength(LinkList La)    //求链表L的表长
{
	LinkList p=La->next;
	int i=0;
	while(p)
	{
		p=p->next;
		i++;
	}

	return i;
}

void GetElem(LinkList La, int i, ElemType &e)  //用e返回L中第i个元素的值
{
    LinkList p=La->next;
	for(int j=1;j<i&&p;j++)
        p=p->next;

	if(!p||j>i)
	{
		printf("错误！\n");
		e=0;
	}
	else
	{
		e=p->data;
    }
}

void main()
{
	int m,x,e,i,n;
	LinkList La;
	printf("请输入链表的长度");
	scanf("%d",&m);
	CreatList(La,m);
 
	printf("请输入插入的位置和值");
	scanf("%d%d",&i,&e);
	ListInsert(La,i,e);

	printf("请输入删除的位置");
	scanf("%d",&n);
	ListDelete(La,n,e);
	if(e) printf("%d已删除\n",e);

	printf("请输出要查找元素的值");
	scanf("%d",&x);
	n=Search(La,x);
	if(n) printf("%d在第几个位置%d\n",x,n);

	printf("链表表长为%d\n",ListLength(La));

	printf("请输入要返回的元素的位置");
	scanf("%d",&i);
	GetElem(La,i,e);
	if(e) printf("元素值为%d",e);
}