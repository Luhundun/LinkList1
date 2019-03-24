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
	//	scanf("%d",&p->data);
		p->data=i+1;
		p->next=NULL;r->next=p;r=p;
	}
	ListPrint(La);
}

void ListInsert(LinkList &La,int i,ElemType e)//�ڴ�ͷ���ĵ�����L�е�i������Ԫ��֮ǰ��������Ԫ��e
{
	LinkList p=La,q;
	q=(LinkList)malloc(sizeof(LNode));
	for(int j=1;j<=i&&p;j++,p=p->next);
    if(!p||j>i+1)
	{
		printf("����\n");
	}
	else
	{	
		q->data=e;
	    q->next=p->next;
     	p->next=q;
     	ListPrint(La);
	}

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
	printf("δ�ҵ�\n");
	return 0;
}

int ListLength(LinkList La)    //������L�ı�
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

void GetElem(LinkList La, int i, ElemType &e)  //��e����L�е�i��Ԫ�ص�ֵ
{
    LinkList p=La->next;
	for(int j=1;j<i&&p;j++)
        p=p->next;

	if(!p||j>i)
	{
		printf("����\n");
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
	printf("����������ĳ���");
	scanf("%d",&m);
	CreatList(La,m);
 
	printf("����������λ�ú�ֵ");
	scanf("%d%d",&i,&e);
	ListInsert(La,i,e);

	printf("������ɾ����λ��");
	scanf("%d",&n);
	ListDelete(La,n,e);
	if(e) printf("%d��ɾ��\n",e);

	printf("�����Ҫ����Ԫ�ص�ֵ");
	scanf("%d",&x);
	n=Search(La,x);
	if(n) printf("%d�ڵڼ���λ��%d\n",x,n);

	printf("�����Ϊ%d\n",ListLength(La));

	printf("������Ҫ���ص�Ԫ�ص�λ��");
	scanf("%d",&i);
	GetElem(La,i,e);
	if(e) printf("Ԫ��ֵΪ%d",e);
}