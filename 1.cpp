#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 100
#define STACKINCREMENT 10
#define SElemType int
typedef struct{
    SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S)
{
    S.base=(SElemType *)malloc(STACKINITSIZE*sizeof(SElemType));
	if(!S.base) exit(-2);
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
}//��ʼ��ջ

void Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*(sizeof(SElemType)));
	    if(!S.base) exit(-2);
	    S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
}//��ջ

void Pop(SqStack &S,SElemType &e)
{ 
    if(S.top==S.base) printf("����!\n");
	else
	{
		e=*S.top--;
	}
}//��ջ

void GetTop(SqStack S,SElemType &e)
{
	if(S.base==S.top)
	    printf("��ջ����");
    else
		e=*(S.top-1);
}//ȡջ��Ԫ��

int StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 1;
	else return 0;
}//�ж��Ƿ�Ϊ��ջ

void VisitStack(SqStack S)
{
	if(S.base==S.top)
		printf("��ջ����");
	while(S.base!=S.top)
	{
		printf("| %3d  |\n",*(S.top-1));
		S.top--;
	}
}//����ջ

void main()
{
	SqStack S;
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
    GetTop(S,e);printf("ջ��Ԫ��Ϊ%d\n",e);
	if(StackEmpty(S)) printf("���ڵ�ջΪ��ջ\n");
	else printf("���ڵ�ջ�ǿ�ջ\n");
}