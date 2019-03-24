#include<stdio.h>
#include<stdlib.h>
#define  ElemType int

typedef struct LNode                    
{  
    int code;   //定义整型变量 code 用来存放序号 
    int key;  //定义整型变量 key 用来存放密码 
    struct LNode *next;                    
}LNode,*LinkList; 


void ListPrint(LinkList J)//将单链表La的数据元素从表头到表尾依次显示。
{
	LinkList p=J->next;
	while(p!=J)
	{
		printf("%d :",p->code);
		printf("%d\n",p->key);
		p=p->next;
	}
	printf("\n");
}

void CreatList(LinkList &Jr)
//建立Joseph；
{
	LinkList p,J1;
	Jr=(LinkList)malloc(sizeof(LNode));
	Jr->next=NULL;
	for(int i=1;i<=7;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->code=i;
		p->next=NULL;
		if(i==1) J1=p;Jr->next=p;Jr=p;
	}
    Jr->next=J1; p=J1;p->key=3;
	p=p->next;p->key=1;
	p=p->next;p->key=7;
	p=p->next;p->key=2;
	p=p->next;p->key=4;
	p=p->next;p->key=8;
	p=p->next;p->key=4;	
}

void Josephzzz(LinkList J,int m)
{
    LinkList p=J,q;
	while(p->next!=p)
	{
        while(m-->1)
		{
			p=p->next;
		}
		m=p->next->key;
		printf("%d ",p->next->code);
		q=p->next;
		p->next=q->next;
		free(q);
	}
	printf("%d ",p->code);
}

void main()
{
	LinkList Joseph;
	CreatList(Joseph);
	ListPrint(Joseph);

	Josephzzz(Joseph,6);

 
 

}