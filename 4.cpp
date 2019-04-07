#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 100
#define STACKINCREMENT 10
#define SElemType char
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
		printf("| %c  |\n",*(S.top-1));
		S.top--;
	}
}//����ջ

int Check(SqStack S)
{
    char c,e;
	printf("������ջ���ʽ");
	while((c=getchar())!='\n')
	{
	    if(c=='('||c=='[')
		    Push(S,c);
		else if(c==')'&&*(S.top-1)=='(')
			Pop(S,e);
		else if(c==']'&&*(S.top-1)=='[')
			Pop(S,e);
	}
	if(StackEmpty(S))
		return 1;
	else 
		return 0;
}

void main()
{
	int e;
    SqStack S;
	InitStack(S);
	e=Check(S);
	if(e)
        printf("���\n");
	else
		printf("�����\n");
}