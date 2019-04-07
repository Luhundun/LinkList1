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

void VisitStack(SqStack S)
{
	if(S.base==S.top)
		printf("��ջ����");
	while(S.base!=S.top)
	{
		printf("%d",*(S.top-1));
		S.top--;
	}
}//����ջ

void Turn(int m,int N)
{
	SqStack S;
	InitStack(S);
	while(m)
	{
		Push(S,m%N);
		m=m/N;
	}
	VisitStack(S);
	printf("\n");


}//����ת��

void main()
{
    int m,N;
	printf("������һ��ʮ������");
    scanf("%d",&m);
	printf("������Ҫת���Ľ���");
    scanf("%d",&N);
	printf("\n���Ϊ:");
	Turn(m,N);
}