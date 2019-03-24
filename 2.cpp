#include<stdio.h>
#include<stdlib.h>
#define  ElemType int
typedef  struct  Node
{
    ElemType   data;      // ������
    struct Node *next;    // ָ����
}LNode, *LinkList;

void ListPrint(LinkList La)//��������La������Ԫ�شӱ�ͷ����β������ʾ��
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
//��������m�����ݣ������ν�������Ԫ�ؽ�㣬������뵽����β����������ͷ���ĵ�����La��
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

void ListDelete(LinkList &La, int n, ElemType &e) //ɾ������ĵ�n��Ԫ�أ�����e������ֵ��
{
	LinkList p=La,q;
	for(int j=1;j<n&&p;j++,p=p->next);
	if(!p||j>n)
	{
		printf("����\n");
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

int Search(LinkList La, ElemType x)//�ڱ��в����Ƿ����ĳ��Ԫ��x��������򷵻�x�ڱ��е�λ�ã����򷵻�0��
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

LinkList AandBlist(LinkList La,LinkList Lb)
{
    LinkList p=La->next,q=Lb->next,Lc,pc,r;
	Lc=(LinkList)malloc(sizeof(LNode));
	Lc->next=NULL;
	r=Lc;
	while(p||q)
	{
		if(q&&p&&p->data==q->data)
		{
			pc=(LinkList)malloc(sizeof(LNode));
			pc->data=p->data;
			pc->next=NULL;
			r->next=pc;
			r=pc;
			p=p->next;q=q->next;
		}
		else if(q&&p&&p->data<q->data||!q)
		{
            pc=(LinkList)malloc(sizeof(LNode));
			pc->data=p->data;
			pc->next=NULL;
			r->next=pc;
			r=pc;
			p=p->next;
		}
		else
		{
            pc=(LinkList)malloc(sizeof(LNode));
			pc->data=q->data;
			pc->next=NULL;
			r->next=pc;
			r=pc;
			q=q->next;
		}
	}
	return Lc;
}

LinkList AsubtractBlist(LinkList La,LinkList Lb)
{
    LinkList p=La->next,Ld,pd,r;
	Ld=(LinkList)malloc(sizeof(LNode));
	Ld->next=NULL;
	r=Ld;
	while(p)
	{
		if(!Search(Lb,p->data))
		{
			pd=(LinkList)malloc(sizeof(LNode));
			pd->data=p->data;
			pd->next=NULL;
			r->next=pd;
			r=pd;
			p=p->next;

		}
		else
		{
            p=p->next;
		}
	}
	return Ld;
}

void main()
{
	int m;
	LinkList La,Lb,Lc,Ld;
	printf("������A����ĳ���");
	scanf("%d",&m);
	CreatList(La,m);

	printf("������B����ĳ���");
	scanf("%d",&m);
	CreatList(Lb,m);

	printf("\nC:");
	Lc=AandBlist(La,Lb);
    ListPrint(Lc);

	printf("\nD:");
	Ld=AsubtractBlist(La,Lb);
    ListPrint(Ld);
 
 

}

 