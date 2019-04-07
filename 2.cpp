#include<stdio.h>
#include<stdlib.h>
#define SElemType int
typedef struct Snode{
    SElemType data;
	struct Snode *next;
}Snode,*LinkStack;

void InitStack(LinkStack &S)
{
    S=NULL;
}//��ʼ��ջ

void Push(LinkStack &S,SElemType e)
{
	LinkStack p;
	p=(LinkStack)malloc(sizeof(Snode));
	p->data=e;
	p->next=S;
    S=p;
}//��ջ

void Pop(LinkStack &S,SElemType &e)
{
	LinkStack p=S;
    if(!S) printf("��ջ����!\n");
	else
	{
		S=S->next;
		free(p);
	}
}//��ջ

void GetTop(LinkStack S,SElemType &e)
{
	if(!S)
	    printf("��ջ����");
    else
	{
		e=S->data;
	}
}//ȡջ��Ԫ��


int StackEmpty(LinkStack S)
{
	if(S)
		return 1;
	else return 0;
}//�ж��Ƿ�Ϊ��ջ

void VisitStack(LinkStack S)
{
	LinkStack p=S;
	if(!p)
	    printf("��ջ��");
	else
	{
	    while(p)
		{
		    printf("| %3d  |\n",p->data);
		    p=p->next;
		}
	}
}//����ջ

void main()
{
	LinkStack S;
    int e,m;
	InitStack(S);
	printf("������ջԪ�ص�����");
    scanf("%d",&m);
	while(m-->0)
	{
	printf("��������ջ��Ԫ��");
	scanf("%d",&e);Push(S,e);
	}	
	VisitStack(S);

	printf("����Ԫ�س�ջ��\n");
	Pop(S,e);	VisitStack(S);

	GetTop(S,e);printf("ջ��Ԫ��eΪ%d\n",e);
	if(StackEmpty(S)) printf("���ڵ�ջΪ��ջ\n");
	else printf("���ڵ�ջ�ǿ�ջ\n");
}