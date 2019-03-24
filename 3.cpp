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
		scanf("%d",&p->data);
		p->next=NULL;r->next=p;r=p;
	}
	ListPrint(La);
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
	return 0;
}

LinkList AmixBlist(LinkList La,LinkList Lb)
{
    LinkList p=La->next,q=Lb->next,Lc,pc,r;
	Lc=(LinkList)malloc(sizeof(LNode));
	Lc->next=NULL;
	r=Lc;
	while(p&&q)
	{
		if(p->data==q->data)
		{
			pc=(LinkList)malloc(sizeof(LNode));
			pc->data=p->data;
			pc->next=NULL;
			r->next=pc;
			r=pc;
			p=p->next;q=q->next;
		}
		else if(p->data < q->data)
		{
			p=p->next;
		}
		else
		{
			q=q->next;
		}
	}
	return Lc;
}

LinkList antilist(LinkList La)
{
	LinkList Ld,p,pa;
	pa=La->next;
	Ld=(LinkList)malloc(sizeof(LNode));
	Ld->next=NULL;
    while(pa)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->data=pa->data;
		p->next=Ld->next;
		Ld->next=p;
		pa=pa->next;
	}
	return Ld;
}

void main()
{
	int m;
	LinkList La,Lb,Lc,Ld;
	printf("请输入A链表的长度");
	scanf("%d",&m);
	CreatList(La,m);

	printf("请输入B链表的长度");
	scanf("%d",&m);
	CreatList(Lb,m);

	printf("\nC:");
	Lc=AmixBlist(La,Lb);
    ListPrint(Lc);

	printf("\nD:");
	Ld=antilist(La);
    ListPrint(Ld);
 
 

}