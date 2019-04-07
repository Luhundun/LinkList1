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

void Pop(SqStack &S,SElemType &e)
{ 
    if(S.top==S.base) printf("错误!\n");
	else
	{
		e=*S.top--;
	}
}//出栈

void GetTop(SqStack S,SElemType &e)
{
	if(S.base==S.top)
	    printf("空栈错误！");
    else
		e=*(S.top-1);
}//取栈顶元素

int StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 1;
	else return 0;
}//判断是否为空栈

void VisitStack(SqStack S)
{
	if(S.base==S.top)
		printf("空栈错误！");
	while(S.base!=S.top)
	{
		printf("| %c  |\n",*(S.top-1));
		S.top--;
	}
}//遍历栈

int Check(SqStack S)
{
    char c,e;
	printf("请输入栈表达式");
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
        printf("配对\n");
	else
		printf("不配对\n");
}