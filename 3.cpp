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
}//初始化栈

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
}//入栈

void VisitStack(SqStack S)
{
	if(S.base==S.top)
		printf("空栈错误！");
	while(S.base!=S.top)
	{
		printf("%d",*(S.top-1));
		S.top--;
	}
}//遍历栈

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


}//进制转化

void main()
{
    int m,N;
	printf("请输入一个十进制数");
    scanf("%d",&m);
	printf("请输入要转化的进制");
    scanf("%d",&N);
	printf("\n结果为:");
	Turn(m,N);
}